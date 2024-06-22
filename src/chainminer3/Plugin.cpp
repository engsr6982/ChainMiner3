#include "Plugin.h"
#include "Config.h"
#include "Economic.h"
#include "PlayerSetting.h"
#include "Plugin.h"
#include "Utils.hpp"
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
    short      enchU{};       // 耐久附魔等级(没有为0)
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

                // 在当前刻获取方块实例，如果在下一刻获取，方块会被Minecraft处理掉
                Block const* block = &e.self().getDimension().getBlockSourceFromMainChunkSource().getBlock(e.pos());

                if (e.isCancelled()) return true; // 事件被拦截

                addSchedulderTask(e, block);
                return true;
            }
        );
}


void removeEventListener() { ll::event::EventBus::getInstance().removeListener(mPlayerDestroyBlockEventListener); }


void addSchedulderTask(ll::event::PlayerDestroyBlockEvent& ev, Block const* block) {
    mNextTickScheduler.add<ll::schedule::DelayTask>(1_tick, [ev, block]() {
        BlockPos const& blockPos  = ev.pos();
        string const    blockName = block->getTypeName();
        Player&         player    = ev.self();

        // 获取同位置的方块新实例, 检测方块是否已掉落, 未掉落(被领地拦截等)则不进行连锁
        if (!player.getDimension().getBlockSourceFromMainChunkSource().getBlock(ev.pos()).isAir()) return true;
        // 仅在生存模式下可连锁
        if (player.getPlayerGameType() != GameType::Survival) return true;
        // 仅当玩家连锁开关打开时可连锁 (默认开启)
        if (!playersetting::playerSetting.getSwitch(player.getXuid())) return true;
        // 开启潜行连锁 (默认关闭) 后，仅当玩家潜行时可连锁
        if (playersetting::playerSetting.getSwitch(player.getXuid(), "chain_while_sneaking_only")
            && !player.isSneaking())
            return true;

        // 检测方块是否在设置的方块列表中
        auto const iter = config::block_list.find(blockName);
        if (iter != config::block_list.end()) {
            // 仅在方块连锁启用时可连锁 (默认启用)
            if (!iter->second.enabled) return true;
            // 仅在玩家的相应方块开关开启时可连锁 (默认开启)
            if (!playersetting::playerSetting.getSwitch(player.getXuid(), blockName)) return true;

            auto*        tool     = const_cast<ItemStack*>(&player.getSelectedItem());
            string const toolType = tool->getTypeName();
            auto const&  material = block->getMaterial();

            // 判断是否含有精准采集附魔
            auto       nbt          = tool->save();
            bool const hasSilkTouch = getEnchantLevel(nbt, 16);

            // 如果该工具无法挖掘就结束
            const bool canThisToolChain =
                (iter->second.tools.empty()                           // 没有设置指定工具
                 || utils::v_contains(iter->second.tools, toolType)   // 使用了指定工具
                 || utils::v_contains(iter->second.tools, string("")) // 使用空字符串允许使用手挖掘
                )
                && (material.isAlwaysDestroyable() || tool->canDestroySpecial(*block)) // 可挖掘
                && ((iter->second.enchSilkTouch == 1 && hasSilkTouch)                  // 仅精准采集工具
                    || (iter->second.enchSilkTouch == 0 && !hasSilkTouch)              // 禁止精准采集工具
                    || iter->second.enchSilkTouch == 2)                                // 不论是否精准采集
                ;
            if (!canThisToolChain) return true;

            // logger.debug("{} is chainable using {}", bn, tool->getTypeName());
            int limit = config::block_list[blockName].limit; // 最大挖掘数量
            if (tool->isDamageableItem()) {
                limit = std::min(
                    limit,
                    static_cast<int>(
                        (tool->getMaxDamage() - getDamageFromNbt(nbt) - 1)
                        / (config::ConfigManager::multiply_damage_switch ? config::ConfigManager::multiply_damage_max
                                                                         : 1)
                    )
                ); // 留一点耐久,防止炸掉
            }
            if (economic::economic.mode > 0 && config::block_list[blockName].cost > 0)
                limit = std::min(
                    limit,
                    static_cast<int>(economic::economic.getMoney(&player) / config::block_list[blockName].cost)
                );

            // 仅当多个时
            if (limit > 1) {
                const int taskID = static_cast<int>(task_list.size()) + 1;
                task_list.insert(std::pair<int, MinerInfo>{
                    taskID,
                    {blockName, player.getDimensionId().id, limit, 0, 0, tool, getEnchantLevel(nbt, 17), &ev.self()}
                });
                miner2(taskID, &blockPos);
            }
        }
        return true;
    });
}


// 使用队列进行连锁采集
void miner2(int taskID, const BlockPos* startBlockPos) {
    std::queue<BlockPos> block_q;
    block_q.push(*startBlockPos);
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
    std::unordered_set<std::string> undamagableBlocks;
    while (curTask.count < curTask.limit && !block_q.empty()) {
        BlockPos curpos = block_q.front();
        for (auto& dir : dirs) {
            auto         newpos = BlockPos(curpos.x + get<0>(dir), curpos.y + get<1>(dir), curpos.z + get<2>(dir));
            const Block* bl     = &ll::service::getLevel()
                                   ->getOrCreateDimension(curTask.dimId)
                                   ->getBlockSourceFromMainChunkSource()
                                   .getBlock(newpos);

            const auto iter = config::block_list.find(curTask.blockName);
            if ((bl->getTypeName() == curTask.blockName || utils::v_contains(iter->second.similar, bl->getTypeName()))
                && !undamagableBlocks.contains(fmt::format("{}.{}.{}.{}", curpos.x, curpos.y, curpos.z, curTask.dimId)
                )) {
                block_q.push(newpos);
            }
        }

        // if (const Block* bl = Level::getBlock(curpos, curTask.dimId); bl->getId() != 0) {
        if (const Block* bl = &ll::service::getLevel()
                                   ->getOrCreateDimension(curTask.dimId)
                                   ->getBlockSourceFromMainChunkSource()
                                   .getBlock(curpos);
            !bl->isAir()) {
            // 破坏方块
            // 主动call玩家破坏事件，当事件被拦截时结束连锁（某个方块进入了领地等）
            auto   ev = ll::event::player::PlayerDestroyBlockEvent{*curTask.player, curpos};
            string dp = getBlockDimAndPos(ev);
            chaining_blocks.insert(dp);
            ll::event::EventBus::getInstance().publish(ev);
            chaining_blocks.erase(dp);
            if (ev.isCancelled()) {
                // 将方块标记为不可挖掘
                undamagableBlocks.insert(fmt::format("{}.{}.{}.{}", curpos.x, curpos.y, curpos.z, curTask.dimId));
            } else {
                bl->playerDestroy(*curTask.player, curpos); // playerDestroy仅生成掉落物
                ll::service::getLevel()
                    ->getOrCreateDimension(curTask.dimId)
                    ->getBlockSourceFromMainChunkSource()
                    .removeBlock(curpos); // 移除方块

                // 累计耐久损失
                // 1.当工具未附魔耐久时+1
                // 2.当附魔了耐久的工具踩中扣除概率1/(level+1)
                if (curTask.enchU == 0 || (curTask.enchU > 0 && randomInt() < (100 / (curTask.enchU + 1))))
                    curTask.countDamage++;

                curTask.count++;
            }
        }
        block_q.pop();
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

/**
 * @brief 获取附魔等级
 * @param nbt 工具nbt
 * @param id 附魔id
 * @return 等级(0表示不存在)
 */
short getEnchantLevel(const std::unique_ptr<CompoundTag>& nbt, const short id) {
    if (nbt->contains("tag")) {
        const auto tag = nbt->getCompound("tag");
        if (tag->contains(ItemStack::TAG_ENCHANTS)) {
            const ListTag* ench = tag->getList(ItemStack::TAG_ENCHANTS);
            short          val;
            ench->forEachCompoundTag([&](CompoundTag const& tag) {
                if (tag.getShort("id") == id) {
                    val = tag.getShort("lvl");
                }
            });
            return val;
        }
    }
    return 0;
}

/**
 * @brief 获取工具的耐久值
 * @param nbt 工具nbt
 * @return 耐久值
 */
int getDamageFromNbt(const std::unique_ptr<CompoundTag>& nbt) {
    if (nbt->contains("tag")) {
        // 必须判断否则会报错
        if (const auto tag = nbt->getCompound("tag"); tag->contains("Damage")) {
            return tag->getInt("Damage");
        }
    }
    return 0;
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
