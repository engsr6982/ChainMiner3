#include "Plugin.h"
#include "Config.h"
#include "Economic.h"
#include "PlayerSetting.h"
#include "Plugin.h"
#include "Utils.hpp"
#include "mc/world/item/ItemStackBase.h"
#include "mc/world/item/enchanting/Enchant.h"
#include "mc/world/item/enchanting/EnchantUtils.h"
#include "plugin/MyPlugin.h"
#include <cstddef>
#include <functional>
#include <queue>
#include <random>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>


#ifdef DEBUG
#define debugger(...) std::cout << __VA_ARGS__ << std::endl;
#endif


typedef struct minerinfo {
    string     blockName;     // 方块名称
    int        dimId{};       // 维度id
    int        limit{};       // 最大挖掘数量
    int        count{};       // 已挖掘数量
    int        countDamage{}; // 需要扣除的耐久
    ItemStack* tool{};        // 工具
    int        enchU{};       // 耐久附魔等级(没有为0)
    Player*    player{};      // 玩家指针
} MinerInfo;


ll::event::ListenerPtr             mPlayerDestroyBlockEventListener;
ll ::schedule::GameTickScheduler   _mTickScheduler;
std::unordered_map<int, MinerInfo> mTaskList;       // 挖掘任务列表 (id, MinerInfo)
std::unordered_set<size_t>         mChainingBlocks; // 正在连锁的方块 (hashDestroyBlockDimAndPos)

namespace chainminer3::plugin {
void nextTick(std::function<void()> func) {
    using ll::chrono_literals::operator""_tick;
    _mTickScheduler.add<ll::schedule::DelayTask>(1_tick, func);
}

void registerEventListener() {
    mPlayerDestroyBlockEventListener =
        ll::event::EventBus::getInstance().emplaceListener<ll::event::PlayerDestroyBlockEvent>(
            [](ll::event::PlayerDestroyBlockEvent& e) {
                if (mChainingBlocks.contains(hashPosAndDim(e)) || e.isCancelled()) return true;

                // 在当前刻获取必要信息
                auto*    player   = &e.self();
                auto*    block    = &e.self().getDimension().getBlockSourceFromMainChunkSource().getBlock(e.pos());
                BlockPos blockPos = BlockPos(e.pos());

                nextTick([player, block, blockPos]() {
                    string const blockTypeName = block->getTypeName();

                    // 获取同位置的方块新实例, 检测方块是否已掉落, 未掉落(被领地拦截等)则不进行连锁
                    if (!player->getDimension().getBlockSourceFromMainChunkSource().getBlock(blockPos).isAir()) return;
                    // 仅在生存模式下可连锁
                    if (player->getPlayerGameType() != GameType::Survival) return;
                    // 仅当玩家连锁开关打开时可连锁 (默认开启)
                    if (!playersetting::playerSetting.getSwitch(player->getXuid())) return;
                    // 开启潜行连锁 (默认关闭) 后，仅当玩家潜行时可连锁
                    if (playersetting::playerSetting.getSwitch(player->getXuid(), "chain_while_sneaking_only")
                        && !player->isSneaking())
                        return;

                    // 检测方块是否在设置的方块列表中
                    auto const iter = config::block_list.find(blockTypeName);

#ifdef DEBUG
                    debugger(fmt::format("TypeName: {}, iter: {}", blockTypeName, iter != config::block_list.end()));
#endif

                    if (iter != config::block_list.end()) {
                        // 仅在方块连锁启用时可连锁 (默认启用)
                        if (!iter->second.enabled) return;
                        // 仅在玩家的相应方块开关开启时可连锁 (默认开启)
                        if (!playersetting::playerSetting.getSwitch(player->getXuid(), blockTypeName)) return;

                        auto*        tool = const_cast<ItemStack*>(&player->getSelectedItem()); // 去 const，取指针
                        string const toolType = tool->getTypeName();
                        auto const&  material = block->getMaterial();

                        // 判断是否含有精准采集附魔
                        bool const hasSilkTouch = EnchantUtils::hasEnchant(::Enchant::Type::MiningSilkTouch, *tool);

                        // 如果该工具无法挖掘就结束
                        bool const canThisToolChain =
                            (iter->second.tools.empty()                         // 没有设置指定工具
                             || utils::v_contains(iter->second.tools, toolType) // 使用了指定工具
                             || utils::v_contains(iter->second.tools, string("")) // 使用空字符串允许使用手挖掘
                            )
                            && (material.isAlwaysDestroyable() || tool->canDestroySpecial(*block)) // 可挖掘
                            && ((iter->second.enchSilkTouch == 1 && hasSilkTouch)     // 仅精准采集工具
                                || (iter->second.enchSilkTouch == 0 && !hasSilkTouch) // 禁止精准采集工具
                                || iter->second.enchSilkTouch == 2);                  // 不论是否精准采集

#ifdef DEBUG
                        debugger("canThisToolChain: " << canThisToolChain);
#endif
                        if (!canThisToolChain) return;

                        // logger.debug("{} is chainable using {}", bn, tool->getTypeName());
                        int maxLimit = config::block_list[blockTypeName].limit; // 最大挖掘数量
                        if (tool->isDamageableItem()) {
                            maxLimit = std::min(
                                maxLimit,
                                static_cast<int>(
                                    (tool->getMaxDamage() - tool->getDamageValue() - 1) // 留一点耐久,防止炸掉
                                    / (config::ConfigManager::multiply_damage_switch
                                           ? config::ConfigManager::multiply_damage_max
                                           : 1)
                                )
                            );
                        }
                        if (economic::economic.mode > 0 && config::block_list[blockTypeName].cost > 0)
                            maxLimit = std::min(
                                maxLimit,
                                static_cast<int>(
                                    economic::economic.getMoney(player) / config::block_list[blockTypeName].cost
                                )
                            );

#ifdef DEBUG
                        debugger("maxLimit: " << maxLimit);
#endif

                        // 仅在挖掘数量大于1时才进行连锁
                        if (maxLimit > 1) {
                            const int taskID = static_cast<int>(mTaskList.size()) + 1;
                            // clang-format off
                            mTaskList.insert(std::pair<int, MinerInfo>{
                                taskID,
                                {
                                    blockTypeName,
                                  player->getDimensionId().id,
                                  maxLimit,
                                   0,
                                  0,
                                   tool,
                                  EnchantUtils::getEnchantLevel(::Enchant::Type::MiningDurability,*tool), // 耐久附魔等级
                                 player
                                }
                            });
                            // clang-format on
                            miner2(taskID, BlockPos(blockPos)); // 拷贝 BlockPos，防止被销毁导致异常
                        }
                    }
                    return;
                });
                return true;
            }
        );
}
void removeEventListener() { ll::event::EventBus::getInstance().removeListener(mPlayerDestroyBlockEventListener); }


// 使用队列进行连锁采集
void miner2(int taskID, BlockPos const startBlockPos) {
    // 与方块相邻的六个方块
    static std::vector<std::tuple<int, int, int>> _dirs1 = {
        {1,  0,  0 },
        {-1, 0,  0 },
        {0,  1,  0 },
        {0,  -1, 0 },
        {0,  0,  1 },
        {0,  0,  -1}
    };
    // 以方块为中心的26个方块，优先相邻方块
    static std::vector<std::tuple<int, int, int>> _dirs2 = {
        {1,  0,  0 },
        {-1, 0,  0 },
        {0,  1,  0 },
        {0,  -1, 0 },
        {0,  0,  1 },
        {0,  0,  -1}, // 相邻六个
        {1,  0,  1 },
        {-1, 0,  1 },
        {0,  1,  1 },
        {0,  -1, 1 },
        {1,  1,  1 },
        {-1, -1, 1 },
        {1,  -1, 1 },
        {-1, 1,  1 }, // z+1 剩下8个
        {1,  0,  -1},
        {-1, 0,  -1},
        {0,  1,  -1},
        {0,  -1, -1},
        {1,  1,  -1},
        {-1, -1, -1},
        {1,  -1, -1},
        {-1, 1,  -1}, // z-1剩下8个
        {1,  1,  0 },
        {-1, -1, 0 },
        {1,  -1, 0 },
        {-1, 1,  0 }  // z剩下4个
    };

    try {
        std::vector<std::tuple<int, int, int>>& dirs = _dirs1; // 连锁范围
        if (config::config_j["default_detect_method"] == "cube"
            || config::block_list[mTaskList[taskID].blockName].detectMode == "cube") {
            dirs = _dirs2;
        }

        std::queue<BlockPos>       mBlockQueue;        // 方块队列(存储待采集的方块指针)
        std::unordered_set<size_t> mUndamagableBlocks; // 不可挖掘的方块

        MinerInfo&   curTask = mTaskList[taskID];
        BlockSource* bs      = &curTask.player->getDimension().getBlockSourceFromMainChunkSource(); // 方块源
        mBlockQueue.push(startBlockPos);


        while (curTask.count < curTask.limit && !mBlockQueue.empty()) {
            const BlockPos& curpos = mBlockQueue.front();

            // 遍历相邻方块（每处理一个方块，搜索其相邻方块）
            for (auto& dir : dirs) {
                BlockPos     newpos = BlockPos(curpos.x + get<0>(dir), curpos.y + get<1>(dir), curpos.z + get<2>(dir));
                size_t const hashedPos = hashPosAndDim(newpos, curTask.dimId);

                const Block* bl            = &bs->getBlock(newpos);
                string const blockTypeName = bl->getTypeName();
                auto const   iter          = config::block_list.find(curTask.blockName);

                if ((blockTypeName == curTask.blockName || utils::v_contains(iter->second.similar, blockTypeName))
                    && !mUndamagableBlocks.contains(hashedPos)) {
                    mBlockQueue.push(newpos); // 加入队列
#ifdef DEBUG
                    debugger("Add Block: " << blockTypeName << ", Pos: " << newpos.toString() << std::endl);
#endif
                }
            }

            const Block* bl = &bs->getBlock(curpos);
            if (!bl->isAir()) {
                // 破坏方块
                // 主动call玩家破坏事件，当事件被拦截时结束连锁（某个方块进入了领地等）
                auto       event     = ll::event::player::PlayerDestroyBlockEvent{*curTask.player, curpos};
                auto const hashedPos = hashPosAndDim(event);

                mChainingBlocks.insert(hashedPos);
                ll::event::EventBus::getInstance().publish(event);
                mChainingBlocks.erase(hashedPos);

                if (event.isCancelled()) {
                    mUndamagableBlocks.insert(hashedPos); // 将方块标记为不可挖掘
                } else {
                    bl->playerDestroy(*curTask.player, curpos); // playerDestroy仅生成掉落物
                    bs->removeBlock(curpos);                    // 移除方块

                    // 累计耐久损失
                    // 1.当工具未附魔耐久时+1
                    // 2.当附魔了耐久的工具踩中扣除概率1/(level+1)
                    if (curTask.enchU == 0 || (curTask.enchU > 0 && randomInt() < (100 / (curTask.enchU + 1))))
                        curTask.countDamage++;

                    curTask.count++;
                }
            }
            mBlockQueue.pop(); // 弹出队首方块
        }

        // 在下一刻进行结果计算，否则手持物品无法更新
        nextTick([&, taskID]() {
            const auto [name, dimId, limit, cnt, cntD, tool, enchU, pl] = curTask;
            if (cnt > 0) {
                // 减少耐久
                ItemStack curTool = pl->getSelectedItem();
                const int dmg     = toolDamage(curTool, cntD);
                // 手动给玩家替换工具
                pl->setSelectedItem(curTool);
                pl->refreshInventory();

                // 构建提示信息
                // 开启了成功提示 且 采集多个方块时发送提示
                if (config::config_j["switch"]["mine.success"] && cnt >= 1) {
                    string message  = config::ConfigManager::msg_prefix; // 前缀
                    message        += utils::s_replace(
                        config::config_j["msg"]["mine.success"],
                        "%Count%",
                        std::to_string(cnt)
                    ); // 数量

                    // 有一个是自己挖的
                    if (config::config_j["switch"]["mine.damage"]) {
                        message += " ";
                        message += utils::s_replace(
                            config::config_j["msg"]["mine.damage"],
                            "%Damage%",
                            std::to_string(dmg)
                        ); // 耐久
                    }

                    if (economic::economic.mode > 0) {
                        const long long cost = config::block_list[name].cost * (cnt - 1);
                        if (cost > 0) {
                            economic::economic.reduceMoney(pl, cost); // 扣除经济
                            message += " ";
                            message += config::config_j["msg"]["money.use"];
                            // 替换变量文本
                            message = utils::s_replace(message, "%Cost%", std::to_string(cost));
                            message =
                                utils::s_replace(message, "%Remain%", std::to_string(economic::economic.getMoney(pl)));
                            message = utils::s_replace(message, "%Name%", config::config_j["money.name"]);
                        }
                    }

                    if (curTool.hasDamageValue() && (curTool.getMaxDamage() - curTool.getDamageValue()) <= 2) {
                        message += "\n";
                        message += utils::s_replace(
                            config::config_j["msg"]["mine.damage.warning"],
                            "%Damage%",
                            std::to_string(curTool.getMaxDamage() - curTool.getDamageValue())
                        );
                    }
                    pl->sendMessage(message);
                }
            }

            mTaskList.erase(taskID);
        });
    } catch (std::exception& e) {
        mTaskList.erase(taskID);
        my_plugin::MyPlugin::getInstance().getSelf().getLogger().error(
            "Fail in {}, std::exception: {}",
            __FUNCTION__,
            e.what()
        );
    } catch (...) {
        mTaskList.erase(taskID);
        my_plugin::MyPlugin::getInstance().getSelf().getLogger().error("Fail in {}, unknown exception", __FUNCTION__);
    }
}


// Tools
size_t hashPosAndDim(Vec3 const& v3, int& dim) { return std::hash<std::string>()(v3.toString() + std::to_string(dim)); }
size_t hashPosAndDim(ll::event::PlayerDestroyBlockEvent& e) {
    return std::hash<std::string>()(e.pos().toString() + std::to_string(e.self().getDimensionId().id));
}
int randomInt() {
    static std::random_device                 rd;
    static std::default_random_engine         re(rd());
    static std::uniform_int_distribution<int> ud(0, 99);
    return ud(re);
}
int toolDamage(ItemStack& tool, const int count) {
    int damage = count;
    if (config::ConfigManager::multiply_damage_switch) {
        damage = static_cast<int>(
            count
            * (config::ConfigManager::multiply_damage_min
               + (config::ConfigManager::multiply_damage_max - config::ConfigManager::multiply_damage_min) * randomInt()
                     / 100)
        );
    }
    short newDam = tool.getDamageValue() + damage;
    if (newDam < tool.getMaxDamage()) tool.setDamageValue(newDam);
    else damage = 0;
    return damage;
}


// Command
int countTaskList() { return static_cast<int>(mTaskList.size()); }
int countChainingBlocks() { return static_cast<int>(mChainingBlocks.size()); }
} // namespace chainminer3::plugin