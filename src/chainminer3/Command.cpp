#include "Command.h"
#include "Config.h"
#include "PlayerSetting.h"
#include "Plugin.h"
#include "Utils.hpp"
#include "mc/nbt/CompoundTag.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/item/registry/ItemStack.h"
#include <fmt/core.h>
#include <initializer_list>
#include <ll/api/Logger.h>
#include <ll/api/command/Command.h>
#include <ll/api/command/CommandHandle.h>
#include <ll/api/command/CommandRegistrar.h>
#include <ll/api/command/Optional.h>
#include <ll/api/command/Overload.h>
#include <ll/api/i18n/I18n.h>
#include <ll/api/plugin/NativePlugin.h>
#include <ll/api/service/Bedrock.h>
#include <ll/api/service/PlayerInfo.h>
#include <ll/api/service/Service.h>
#include <ll/api/utils/HashUtils.h>
#include <mc/entity/utilities/ActorType.h>
#include <mc/network/packet/LevelChunkPacket.h>
#include <mc/network/packet/TextPacket.h>
#include <mc/server/ServerLevel.h>
#include <mc/server/ServerPlayer.h>
#include <mc/server/commands/CommandOrigin.h>
#include <mc/server/commands/CommandOriginType.h>
#include <mc/server/commands/CommandOutput.h>
#include <mc/server/commands/CommandParameterOption.h>
#include <mc/server/commands/CommandPermissionLevel.h>
#include <mc/server/commands/CommandRegistry.h>
#include <mc/server/commands/CommandSelector.h>
#include <mc/world/actor/Actor.h>
#include <mc/world/actor/player/Player.h>
#include <sstream>


namespace chainminer3::command {


extern nlohmann::json config_j;

// 命令 Optionl 枚举
enum OptionalList_1 { reload = 0, test = -1, menu = 1, block = 2, edit = 3, help = 4 };
enum OptionalList_2 { on = 5, off = 6 };
enum OptionalList_3 { op = 7, deop = 8, ban = 9, forgiv = 10 };

// 重载1
struct OP1 {
    OptionalList_1 op1;
};
// 重载2：玩家可选
struct OP2 {
    OptionalList_2          op2;
    CommandSelector<Player> player;
};
// 重载3：玩家必选
struct OP3 {
    OptionalList_3          op3;
    CommandSelector<Player> player;
};
// 重载4：数字必选
struct ParamDamage {
    int count;
};


void registerCommand() {
    auto& cmd =
        ll::command::CommandRegistrar::getInstance().getOrCreateCommand(config_j["command"], "ChainMiner连锁采集");

    // 重载1
    cmd.overload<OP1>().execute([](CommandOrigin const& ori, CommandOutput& outp, OP1 const& param) {
        switch (param.op1) {
        case OptionalList_1::reload: {
            // 限制为管理员权限
            if (ori.getPermissionsLevel() >= CommandPermissionLevel::Admin) {
                config::readConfig();
                outp.success("§e重载成功!");
            }
            break;
        }
        case OptionalList_1::test: {
            // 限制为管理员权限
            if (ori.getPermissionsLevel() >= CommandPermissionLevel::Admin) {
                outp.success(
                    fmt::format("{} {}", plugin::countTaskList() /*, countPos2Id()*/, plugin::countChainingBlocks())
                );
            }
            break;
        }
        case OptionalList_1::menu: {
            if (ori.getOriginType() == CommandOriginType::Player) {
                Player& pl = *static_cast<Player*>(ori.getEntity());
                sendPlayerMenu(pl);
            } else {
                outp.error("Please use in game.");
            }
            break;
        }
        case OptionalList_1::block: {
            if (ori.getOriginType() == CommandOriginType::Player) {
                Player& pl = *static_cast<Player*>(ori.getEntity());
                sendBlockSwitchMenu(pl);
            } else {
                outp.error("Please use in game.");
            }
            break;
        }
        case OptionalList_1::edit: {
            break; // 原作者未实现
        }
        case OptionalList_1::help: {
            break; // 原作者未实现
        }
        };
    });

    // 重载2：玩家可选
    cmd.overload<OP2>().optional("player").execute([](CommandOrigin const& ori, CommandOutput& outp, OP2 const& param) {
        switch (param.op2) {
        case OptionalList_2::on: {
            if (ori.getOriginType() == CommandOriginType::Player) {
                Player& pl      = *static_cast<Player*>(ori.getEntity());
                auto    targets = param.player.results(ori).data;
                if (!targets->empty()) {
                    // 玩家选择器
                    for (auto el : *targets) {
                        if (ori.getPermissionsLevel() >= CommandPermissionLevel::Admin || pl.getXuid() == el->getXuid())
                            playersetting::playerSetting.turnOn(el->getXuid());
                        outp.success(std::string(config_j["msg"]["switch.on"]));
                    }
                } else {
                    // 玩家自己执行命令
                    playersetting::playerSetting.turnOn(pl.getXuid());
                    pl.sendMessage(config_j["msg"]["switch.on"]);
                }
            } else {
                outp.error("Do not use this in console.");
            }
            break;
        }
        case OptionalList_2::off: {
            if (ori.getOriginType() == CommandOriginType::Player) {
                Player& pl      = *static_cast<Player*>(ori.getEntity());
                auto    targets = param.player.results(ori).data;
                if (!targets->empty()) {
                    // 玩家选择器
                    for (auto el : *targets) {
                        if (ori.getPermissionsLevel() >= CommandPermissionLevel::Admin || pl.getXuid() == el->getXuid())
                            playersetting::playerSetting.turnOff(el->getXuid());
                        outp.success(std::string(config_j["msg"]["switch.off"]));
                    }
                } else {
                    // 玩家自己执行命令
                    playersetting::playerSetting.turnOff(pl.getXuid());
                    pl.sendMessage(config_j["msg"]["switch.off"]);
                }
            } else {
                outp.error("Do not use this in console.");
            }
            break;
        }
        };
    });

    // 重载3：玩家必选
    cmd.overload<OP3>().required("player").execute([](CommandOrigin const& ori, CommandOutput& outp, OP3 const& param) {
        switch (param.op3) {
        case OptionalList_3::op: {
            auto& op_list = config::op_list;
            if (ori.getOriginType() == CommandOriginType::DedicatedServer) {
                auto pls = param.player.results(ori).data;
                for (auto el : *pls)
                    if (!utils::v_contains(op_list, el->getXuid())) {
                        playersetting::playerSetting.setOP(el->getXuid());
                        outp.success("成功添加<" + el->getName() + ">为连锁采集管理.");
                    } else {
                        outp.success("<" + el->getName() + ">已经是连锁采集管理.");
                    }
            } else {
                outp.error("Permission Denied.");
            }
            break;
        }
        case OptionalList_3::deop: {
            auto& op_list = config::op_list;
            if (ori.getOriginType() == CommandOriginType::DedicatedServer) {
                auto pls = param.player.results(ori).data;
                for (auto el : *pls)
                    if (utils::v_contains(op_list, el->getXuid())) {
                        playersetting::playerSetting.delOP(el->getXuid());
                        outp.success("成功移除<" + el->getName() + ">的连锁采集管理.");
                    } else {
                        outp.success("<" + el->getName() + ">不是连锁采集管理.");
                    }
            } else {
                outp.error("Permission Denied.");
            }
            break;
        }
        case OptionalList_3::ban: {
            break; // 原作者未实现
        }
        case OptionalList_3::forgiv: {
            break; // 原作者未实现
        }
        }
    });

    // 重载4：数字必选
    cmd.overload<ParamDamage>().required("count").execute(
        [](CommandOrigin const& ori, CommandOutput&, ParamDamage const& param) {
            if (ori.getOriginType() == CommandOriginType::Player) {
                auto      pl   = static_cast<Player*>(ori.getEntity());
                ItemStack item = pl->getSelectedItem();
                plugin::toolDamage(item, param.count);
                pl->setSelectedItem(item);
                pl->refreshInventory();
            }
        }
    );
}


#include "ll/api/form/CustomForm.h"
#include "ll/api/form/SimpleForm.h"
using namespace ll::form;
// C:\Program
// Files\WindowsApps\Microsoft.MinecraftUWP_1.18.3004.0_x64__8wekyb3d8bbwe\data\resource_packs\vanilla\textures\blocks

void sendPlayerMenu(Player& pl) {
    SimpleForm form("连锁采集 - ChainMiner", "");
    form.appendButton("基础设置", [](Player& p_pl) { sendBasicSettingMenu(p_pl); })
        .appendButton("方块开关", [](Player& p_pl) { sendBlockSwitchMenu(p_pl); })
        .appendButton("关闭", [](Player&) {});
    form.sendTo(pl);
}

void sendBasicSettingMenu(Player& pl) {
    CustomForm form("连锁采集 - 基础设置");
    form.appendLabel("Tip1: 修改后点击提交即可保存");
    form.appendToggle("chain", "连锁采集开关", playersetting::playerSetting.getSwitch(pl.getXuid()));
    form.appendToggle(
        "sneak",
        "仅在下蹲时连锁",
        playersetting::playerSetting.getSwitch(pl.getXuid(), "chain_while_sneaking_only")
    );
    form.sendTo(pl, [](Player& p_pl, CustomFormResult const& elems, FormCancelReason) {
        // 为空代表表单被关闭
        if (elems) {
            bool chain = std::get<uint64>(elems->at("chain"));
            bool sneak = std::get<uint64>(elems->at("sneak"));
            if (playersetting::playerSetting.getSwitch(p_pl.getXuid()) != chain) {
                playersetting::playerSetting.setSwitch(p_pl.getXuid(), "switch", chain);
            } else if (playersetting::playerSetting.getSwitch(p_pl.getXuid(), "chain_while_sneaking_only") != sneak) {
                playersetting::playerSetting.setSwitch(p_pl.getXuid(), "chain_while_sneaking_only", sneak);
            }
            p_pl.sendMessage("§c[§6连§e锁§a采§b集§c] §a设置成功");
        }
        sendPlayerMenu(p_pl);
    });
}

using string = std::string;
void sendBlockSwitchMenu(Player& pl, int page) {
    // 第一页的page=0
    auto& block_list = config::block_list; // 可连锁方块列表

    int count_per_page = config_j["menu.count_per_page"];
    int max_page       = (block_list.size() - 1) / count_per_page;
    page               = (page < max_page ? page : max_page); // 取更小的页码->避免空页
    if (count_per_page != -1 && page == -1) page = 0;         // 当每页数量不为-1时->访问第一页
    // logger.debug("{} {} {} {}", page, max_page, count_per_page, block_list.size());
    SimpleForm form("连锁采集 - 方块开关", "选择一项进行开关");

    auto it = block_list.begin();
    advance(it, (page == -1 ? 0 : page * count_per_page)); //
    for (it; (page == -1 || count_per_page) && it != block_list.end(); ++it, --count_per_page) {
        // logger.debug("{} {} {}", page, count_per_page, it->first);
        string name  = it->first.substr(10);
        string nsid  = "minecraft:" + name;
        bool   onoff = playersetting::playerSetting.getSwitch(pl.getXuid(), nsid);
        form.appendButton(
            string((it->second.name == "" ? name : it->second.name) + "§f(" + (onoff ? "§a开启" : "§c关闭") + "§f)"),
            (it->second.texture == "" ? string("textures/blocks/" + name) : it->second.texture),
            "path",
            [nsid, page](Player& p_pl) {
                if (playersetting::playerSetting.getSwitch(p_pl.getXuid(), nsid)) {
                    playersetting::playerSetting.turnOff(p_pl.getXuid(), nsid);
                    string msg = config_j["msg"]["switch.block.off"];
                    msg        = utils::s_replace(msg, "%Block%", nsid);
                    p_pl.sendMessage(msg);
                } else {
                    playersetting::playerSetting.turnOn(p_pl.getXuid(), nsid);
                    string msg = config_j["msg"]["switch.block.on"];
                    msg        = utils::s_replace(msg, "%Block%", nsid);
                    p_pl.sendMessage(msg);
                }
                sendBlockSwitchMenu(p_pl, page); // 一直重复发送菜单
            }
        );
    }
    if (page >= 1)
        form.appendButton("上一页", [page](Player& p_pl) {
            sendBlockSwitchMenu(p_pl, page - 1); // 发送上一页的菜单
        });
    if (page >= 0 && page < max_page)
        form.appendButton("下一页", [page](Player& p_pl) { sendBlockSwitchMenu(p_pl, page + 1); });
    form.appendButton("关闭", [](Player&) {});
    form.sendTo(pl);
}


} // namespace chainminer3::command
