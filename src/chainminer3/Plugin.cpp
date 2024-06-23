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
#include <queue>
#include <random>
#include <tuple>
#include <unordered_map>
#include <utility>


using std::get;
using std::tuple;
using ll::chrono_literals::operator""_tick;

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


// 全局变量声明
ll::event::ListenerPtr             mPlayerDestroyBlockEventListener;
ll ::schedule::GameTickScheduler   mNextTickScheduler; // 下一刻任务调度器
std::unordered_map<int, MinerInfo> task_list;          // 挖掘任务列表 (id, MinerInfo)
std::unordered_set<std::string>    chaining_blocks;    // 避免在call事件的时候进入死循环


namespace chainminer3::plugin {

void registerEventListener() {
    mPlayerDestroyBlockEventListener =
        ll::event::EventBus::getInstance().emplaceListener<ll::event::PlayerDestroyBlockEvent>(
            [](ll::event::PlayerDestroyBlockEvent& e) {
                // 避免在call事件的时候进入死循环
                if (chaining_blocks.contains(getBlockDimAndPos(e))) {
                    return true;
                }

                if (e.isCancelled()) return true; // 事件被拦截

                addSchedulderTask(
                    &e.self(),
                    &e.self().getDimension().getBlockSourceFromMainChunkSource().getBlock(e.pos()),
                    BlockPos(e.pos()) // 拷贝，避免生命周期导致异常
                );
                return true;
            }
        );
}


void removeEventListener() { ll::event::EventBus::getInstance().removeListener(mPlayerDestroyBlockEventListener); }


void addSchedulderTask(Player* player, Block const* block, BlockPos const blockPos) {
    mNextTickScheduler.add<ll::schedule::DelayTask>(1_tick, [player, block, blockPos]() {
        string const blockTypeName = block->getTypeName();
        auto&        playerSetting = playersetting::playerSetting;

        // 获取同位置的方块新实例, 检测方块是否已掉落, 未掉落(被领地拦截等)则不进行连锁
        if (!player->getDimension().getBlockSourceFromMainChunkSource().getBlock(blockPos).isAir()) return true;
        // 仅在生存模式下可连锁
        if (player->getPlayerGameType() != GameType::Survival) return true;
        // 仅当玩家连锁开关打开时可连锁 (默认开启)
        if (!playerSetting.getSwitch(player->getXuid())) return true;
        // 开启潜行连锁 (默认关闭) 后，仅当玩家潜行时可连锁
        if (playerSetting.getSwitch(player->getXuid(), "chain_while_sneaking_only") && !player->isSneaking())
            return true;


        // 检测方块是否在设置的方块列表中
        auto const iter = config::block_list.find(blockTypeName);

#ifdef DEBUG
        std::cout << fmt::format("TypeName: {}, iter: {}", blockTypeName, iter != config::block_list.end())
                  << std::endl;
#endif

        if (iter != config::block_list.end()) {
            // 仅在方块连锁启用时可连锁 (默认启用)
            if (!iter->second.enabled) return true;
            // 仅在玩家的相应方块开关开启时可连锁 (默认开启)
            if (!playerSetting.getSwitch(player->getXuid(), blockTypeName)) return true;

            auto*        tool     = const_cast<ItemStack*>(&player->getSelectedItem()); // 去 const，取指针
            auto*        toolBase = dynamic_cast<ItemStackBase*>(tool);                 // 转基类
            string const toolType = tool->getTypeName();
            auto const&  material = block->getMaterial();

            // 判断是否含有精准采集附魔
            bool const hasSilkTouch = EnchantUtils::hasEnchant(::Enchant::Type::MiningSilkTouch, *toolBase);

            // 如果该工具无法挖掘就结束
            const bool canThisToolChain =
                (iter->second.tools.empty()                           // 没有设置指定工具
                 || utils::v_contains(iter->second.tools, toolType)   // 使用了指定工具
                 || utils::v_contains(iter->second.tools, string("")) // 使用空字符串允许使用手挖掘
                )
                && (material.isAlwaysDestroyable() || tool->canDestroySpecial(*block)) // 可挖掘
                && ((iter->second.enchSilkTouch == 1 && hasSilkTouch)                  // 仅精准采集工具
                    || (iter->second.enchSilkTouch == 0 && !hasSilkTouch)              // 禁止精准采集工具
                    || iter->second.enchSilkTouch == 2);                               // 不论是否精准采集

#ifdef DEBUG
            std::cout << "canThisToolChain: " << canThisToolChain << std::endl;
#endif
            if (!canThisToolChain) return true;

            // logger.debug("{} is chainable using {}", bn, tool->getTypeName());
            int maxLimit = config::block_list[blockTypeName].limit; // 最大挖掘数量
            if (tool->isDamageableItem()) {
                maxLimit = std::min(
                    maxLimit,
                    static_cast<int>(
                        (tool->getMaxDamage() - tool->getDamageValue() - 1) // 留一点耐久,防止炸掉
                        / (config::ConfigManager::multiply_damage_switch ? config::ConfigManager::multiply_damage_max
                                                                         : 1)
                    )
                );
            }
            if (economic::economic.mode > 0 && config::block_list[blockTypeName].cost > 0)
                maxLimit = std::min(
                    maxLimit,
                    static_cast<int>(economic::economic.getMoney(player) / config::block_list[blockTypeName].cost)
                );

#ifdef DEBUG
            std::cout << "maxLimit: " << maxLimit << std::endl;
#endif

            // 仅在挖掘数量大于1时才进行连锁
            if (maxLimit > 1) {
                const int taskID = static_cast<int>(task_list.size()) + 1;
                task_list.insert(std::pair<int, MinerInfo>{
                    taskID,
                    {blockTypeName,
                      player->getDimensionId().id,
                      maxLimit, 0,
                      0, tool,
                      EnchantUtils::getEnchantLevel(::Enchant::Type::MiningDurability, *toolBase), // 耐久附魔等级
                     player}
                });
                miner2(taskID, BlockPos(blockPos)); // 拷贝 BlockPos，防止被销毁导致异常
            }
        }
        return true;
    });
}


// 使用队列进行连锁采集
void miner2(int taskID, BlockPos const startBlockPos) {
    std::queue<BlockPos> block_q; // 方块队列
    block_q.push(startBlockPos);
    // 与方块相邻的六个方块
    static std::vector<tuple<int, int, int>> dirs1 = {
        {1,  0,  0 },
        {-1, 0,  0 },
        {0,  1,  0 },
        {0,  -1, 0 },
        {0,  0,  1 },
        {0,  0,  -1}
    };
    // 以方块为中心的26个方块，优先相邻方块
    static std::vector<tuple<int, int, int>> dirs2 = {
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

    MinerInfo& curTask = task_list[taskID];

    // 判断使用的连锁范围
    std::vector<tuple<int, int, int>>& dirs = dirs1;
    if (config::config_j["default_detect_method"] == "cube"
        || config::block_list[task_list[taskID].blockName].detectMode == "cube") {
        dirs = dirs2;
    }

    // 记录不可挖掘的方块

    BlockSource* bs;             // 方块源
    if (!curTask.player) return; // nullptr
    if (curTask.dimId == curTask.player->getDimensionId().id) {
        bs = &curTask.player->getDimension().getBlockSourceFromMainChunkSource();
    } else {
        auto const dimension = ll::service::getLevel()->getDimension(curTask.dimId);
        if (!dimension) return; // 获取维度失败
        bs = &dimension->getBlockSourceFromMainChunkSource();
    }

    std::unordered_set<std::string> undamagableBlocks;

#ifdef DEBUG
    std::cout << fmt::format("block_q size: {}", block_q.size()) << std::endl;
#endif

    while (curTask.count < curTask.limit && !block_q.empty()) {
        BlockPos curpos = block_q.front(); // 取出队首方块(==startBlockPos)

        // 遍历相邻方块（每处理一个方块，搜索其相邻方块）
        for (auto& dir : dirs) {
            BlockPos     newpos = BlockPos(curpos.x + get<0>(dir), curpos.y + get<1>(dir), curpos.z + get<2>(dir));
            string const blockTypeName = bs->getBlock(newpos).getTypeName();

            const auto iter = config::block_list.find(curTask.blockName);

#ifdef DEBUG
            std::cout << fmt::format(
                // clang-format off
                "curposs: {7}  |  newpos: {0}  |  blockTypeName: {1}  |  curTask.blockName: {2}\niter: {3}  |  iter->second.similar: {4}\nv_contains: {5}\nundamagableBlocks.contanins: {6}",
                // clang-format on
                newpos.toString(),                                                                                 // 0
                blockTypeName,                                                                                     // 1
                curTask.blockName,                                                                                 // 2
                iter != config::block_list.end(),                                                                  // 3
                iter != config::block_list.end() ? std::to_string(iter->second.similar.size()) : "iter not found", // 4
                iter != config::block_list.end()
                    ? std::to_string(utils::v_contains(iter->second.similar, blockTypeName))
                    : "iter not found", // 5
                undamagableBlocks.contains(fmt::format("{}.{}.{}.{}", curpos.x, curpos.y, curpos.z, curTask.dimId)
                ),                // 6
                curpos.toString() // 7
            ) << std::endl
                      << std::endl;
#endif

            if ((blockTypeName == curTask.blockName || utils::v_contains(iter->second.similar, blockTypeName))
                && !undamagableBlocks.contains(fmt::format("{}.{}.{}.{}", curpos.x, curpos.y, curpos.z, curTask.dimId)
                )) {
                block_q.push(newpos); // 加入队列

#ifdef DEBUG
                std::cout << fmt::format("Add Block: {}, Pos: {}", blockTypeName, newpos.toString()) << std::endl
                          << std::endl;
#endif
            }
        }

        // if (const Block* bl = Level::getBlock(curpos, curTask.dimId); bl->getId() != 0) {
        const Block* bl = &bs->getBlock(curpos);
        if (!bl->isAir()) {
            // 破坏方块
            // 主动call玩家破坏事件，当事件被拦截时结束连锁（某个方块进入了领地等）
            auto         ev = ll::event::player::PlayerDestroyBlockEvent{*curTask.player, curpos};
            string const dp = getBlockDimAndPos(ev);

            chaining_blocks.insert(dp);
            ll::event::EventBus::getInstance().publish(ev);
            chaining_blocks.erase(dp);

            if (ev.isCancelled()) {
                // 将方块标记为不可挖掘
                undamagableBlocks.insert(fmt::format("{}.{}.{}.{}", curpos.x, curpos.y, curpos.z, curTask.dimId));
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
        block_q.pop(); // 弹出队首方块
    }

    // 在下一刻进行结果计算，否则手持物品无法更新
    mNextTickScheduler.add<ll::schedule::DelayTask>(1_tick, [&, taskID]() {
        const auto [name, dimId, limit, cnt, cntD, tool, enchU, pl] = curTask;
        if (cnt > 0) {
            // 减少耐久
            ItemStack curTool = pl->getSelectedItem();
            const int dmg     = toolDamage(curTool, cntD);
            // 手动给玩家替换工具
            //  mi.pl->setItemSlot(mi.pl->getEquipmentSlotForItem(tool), tool);
            pl->setSelectedItem(curTool);
            pl->refreshInventory();


            // 构建提示信息
            // 开启了成功提示 且 采集多个方块时发送提示
            if (config::config_j["switch"]["mine.success"] && cnt >= 1) {
                string message = config::ConfigManager::msg_prefix; // 前缀
                message +=
                    utils::s_replace(config::config_j["msg"]["mine.success"], "%Count%", std::to_string(cnt)); // 数量

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

        task_list.erase(taskID);
    });
}


// tools function
int randomInt() {
    static std::random_device                 rd;
    static std::default_random_engine         re(rd());
    static std::uniform_int_distribution<int> ud(0, 99);
    return ud(re);
}


std::string getBlockDimAndPos(ll::event::PlayerDestroyBlockEvent& e) {
    return std::to_string(e.self().getDimensionId()) + ',' + e.pos().toString();
}


int toolDamage(ItemStack& tool, const int count) {
    int        damage = count;
    const auto nbt    = tool.save();
    // logger.debug("before: {} {}", nbt->toSNBT(), tool.getMaxDamage());
    if (config::ConfigManager::multiply_damage_switch) {
        const double rate = config::ConfigManager::multiply_damage_min
                          + (config::ConfigManager::multiply_damage_max - config::ConfigManager::multiply_damage_min)
                                * randomInt() / 100;
        // logger.debug("rate:{}", rate);
        damage = static_cast<int>(count * rate);
    }
    short newDam = tool.getDamageValue() + damage;
    if (newDam < tool.getMaxDamage()) tool.setDamageValue(newDam);
    else damage = 0;
    return damage;
}

int countTaskList() { return static_cast<int>(task_list.size()); }

int countChainingBlocks() { return static_cast<int>(chaining_blocks.size()); }

} // namespace chainminer3::plugin
