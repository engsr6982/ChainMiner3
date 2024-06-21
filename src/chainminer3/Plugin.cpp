#include "Plugin.h"
#include "Config.h"
#include "Economic.h"
#include "PlayerSetting.h"
#include "Plugin.h"
#include "Utils.hpp"
#include "ll/api/chrono/GameChrono.h"
#include "ll/api/event/Event.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/ListenerBase.h"
#include "ll/api/event/player/PlayerDestroyBlockEvent.h"
#include "ll/api/schedule/Scheduler.h"
#include "ll/api/schedule/Task.h"
#include "ll/api/service/Bedrock.h"
#include "mc/nbt/CompoundTag.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/BlockSource.h"
#include "mc/world/level/Level.h"
#include "mc/world/level/block/ActorBlock.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/level/block/actor/BlockActor.h"
#include "mc/world/level/dimension/Dimension.h"
#include "mc/world/level/material/Material.h"
#include "plugin/MyPlugin.h"
#include <queue>
#include <random>
#include <unordered_map>
#include <utility>


// 全局变量声明
ll::event::ListenerPtr           mPlayerDestroyBlockEventListener;
ll ::schedule::GameTickScheduler mNextTickScheduler; // 注册到游戏主循环的下一tick调度器
using ll::chrono_literals::operator""_tick;


namespace chainminer3::plugin {

void removeListener() { ll::event::EventBus::getInstance().removeListener(mPlayerDestroyBlockEventListener); }


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


std::random_device                 rd;        // 使用硬件熵源的非确定随机数生成器(类)
std::default_random_engine         re(rd());  // 设置随机数分布类型
std::uniform_int_distribution<int> ud(0, 99); // 设置随机数范围为[0,99]


std::unordered_map<int, MinerInfo> task_list;       // id,cnt
std::unordered_set<std::string>    chaining_blocks; // 避免在call事件的时候进入死循环


// get a string like "dim,x,y,z"
std::string getBlockDimAndPos(ll::event::PlayerDestroyBlockEvent& e) {
    std::string spos = std::to_string(e.self().getDimensionId()) + ',' + e.pos().toString();
    return spos;
}

void addSchedulderTask(ll::event::PlayerDestroyBlockEvent& e, const Block* block) {
    mNextTickScheduler.add<ll::schedule::DelayTask>(1_tick, [e, block]() {
        const BlockPos& blockPos  = e.pos();
        const string    blockName = block->getTypeName();

        // 获取同位置的方块新实例, 检测方块是否已掉落, 未掉落(被领地拦截等)则不进行连锁
        if (!e.self().getDimension().getBlockSourceFromMainChunkSource().getBlock(e.pos()).isAir()) return true;
        // 仅在生存模式下可连锁
        if (e.self().getPlayerGameType() != GameType::Survival) return true;
        // 仅当玩家连锁开关打开时可连锁 (默认开启)
        if (!playersetting::playerSetting.getSwitch(e.self().getXuid())) return true;
        // 开启潜行连锁 (默认关闭) 后，仅当玩家潜行时可连锁
        if (playersetting::playerSetting.getSwitch(e.self().getXuid(), "chain_while_sneaking_only")
            && !e.self().isSneaking())
            return true;

        // 检测方块是否在设置的方块列表中
        if (const auto r = config::block_list.find(blockName); r != config::block_list.end()) {
            // 仅在方块连锁启用时可连锁 (默认启用)
            if (!r->second.enabled) return true;
            // 仅在玩家的相应方块开关开启时可连锁 (默认开启)
            if (!playersetting::playerSetting.getSwitch(e.self().getXuid(), blockName)) return true;
            auto*        tool     = const_cast<ItemStack*>(&e.self().getSelectedItem());
            const string toolType = tool->getTypeName();
            // logger.info("{}", toolType);
            const auto& material = block->getMaterial();

            // 判断是否含有精准采集bl->getTypeName();
            auto nbt = tool->save();
            // logger.debug("{}", nbt->toSNBT());
            const bool hasSilkTouch = getEnchantLevel(nbt, 16);

            // 如果该工具无法挖掘就结束
            if (const bool canThisToolChain =
                    (r->second.tools.empty()                           // 没有设置指定工具
                     || utils::v_contains(r->second.tools, toolType)   // 使用了指定工具
                     || utils::v_contains(r->second.tools, string("")) // 使用空字符串允许使用手挖掘
                    )
                    && (material.isAlwaysDestroyable() || tool->canDestroySpecial(*block)) // 可挖掘
                    && ((r->second.enchSilkTouch == 1 && hasSilkTouch)                     // 仅精准采集工具
                        || (r->second.enchSilkTouch == 0 && !hasSilkTouch)                 // 禁止精准采集工具
                        || r->second.enchSilkTouch == 2)                                   // 不论是否精准采集
                ;
                !canThisToolChain)
                return true;
            // logger.debug("{} is chainable using {}", bn, tool->getTypeName());
            int limit = config::block_list[blockName].limit;
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
                    static_cast<int>(economic::economic.getMoney(&e.self()) / config::block_list[blockName].cost)
                );

            // 仅当多个时
            if (limit > 1) {
                // add task
                const int id = static_cast<int>(task_list.size()) + 1;
                task_list.insert(std::pair<int, MinerInfo>{
                    id, // 因为挖掘的方块和玩家是在同一维度，所以直接用玩家当前维度ID
                    {blockName, e.self().getDimensionId().id, limit, 0, 0, tool, getEnchantLevel(nbt, 17), &e.self()}
                });
                miner2(id, &blockPos);
            }
        }
        return true;
    });
}

void registerEvent() {
    auto& bus = ll::event::EventBus::getInstance();
    // 注册监听器
    mPlayerDestroyBlockEventListener =
        bus.emplaceListener<ll::event::PlayerDestroyBlockEvent>([](ll::event::PlayerDestroyBlockEvent& e) {
            // 避免在call事件的时候进入死循环
            if (chaining_blocks.contains(getBlockDimAndPos(e))) {
                return true;
            }

            // 在当前刻获取方块实例，如果在下一刻获取，方块会被Minecraft处理掉
            const Block* block = &e.self().getDimension().getBlockSourceFromMainChunkSource().getBlock(e.pos());

            // 交给任务调度器处理
            addSchedulderTask(e, block);
            return true;
        });
}


// get enchant level with nbt && enchid
// return level (0 when non-exist)
short getEnchantLevel(const std::unique_ptr<CompoundTag>& nbt, const short id) {
    if (nbt->contains("tag")) {
        // 必须判断否则会报错
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
        const double rate =
            config::ConfigManager::multiply_damage_min
            + (config::ConfigManager::multiply_damage_max - config::ConfigManager::multiply_damage_min) * ud(re) / 100;
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

// 使用队列进行连锁采集
#include <tuple>
using std::get;
using std::tuple;

void miner2(int task_id, const BlockPos* start_pos) {
    std::queue<BlockPos> block_q;
    block_q.push(*start_pos);
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

    MinerInfo& curTask = task_list[task_id];

    // 判断使用的连锁范围
    std::vector<tuple<int, int, int>>& dirs = dirs1;
    if (config::config_j["default_detect_method"] == "cube"
        || config::block_list[task_list[task_id].blockName].detectMode == "cube") {
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
            if (const auto r = config::block_list.find(curTask.blockName);
                (bl->getTypeName() == curTask.blockName
                 || utils::v_contains(r->second.similar, bl->getTypeName()))
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
                if (curTask.enchU == 0 || (curTask.enchU > 0 && ud(re) < (100 / (curTask.enchU + 1))))
                    curTask.countDamage++;

                curTask.count++;
            }
        }
        block_q.pop();
    }

    // 在下一刻进行结果计算，否则手持物品无法更新
    mNextTickScheduler.add<ll::schedule::DelayTask>(1_tick, [&, task_id]() {
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

        task_list.erase(task_id);
    });
}


} // namespace chainminer3::plugin
