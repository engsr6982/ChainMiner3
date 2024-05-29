#include "PlayerSetting.h"
#include "Config.h"


using json = nlohmann::json;


namespace chainminer3::playersetting {


#define logger              my_plugin::MyPlugin::getInstance().getSelf().getLogger()
#define PLAYER_SETTING_FILE "plugins/ChainMiner/player.json"


void PlayerSetting::save_player_setting() {
    std::ofstream file(PLAYER_SETTING_FILE);
    if (!file.is_open()) {
        logger.warn("Failed to open file: " PLAYER_SETTING_FILE);
        return;
    }
    file << player_j.dump(4);
    file.close();
}

void PlayerSetting::read_player_setting() {
    std::ifstream file(PLAYER_SETTING_FILE);
    if (!file.is_open()) {
        logger.warn("Failed to open file: " PLAYER_SETTING_FILE);
        return;
    }
    file >> player_j;
    file.close();
}

void PlayerSetting::create_empty_file() {
    if (!std::filesystem::exists(PLAYER_SETTING_FILE) || std::filesystem::is_empty(PLAYER_SETTING_FILE)) {
        std::ofstream file(PLAYER_SETTING_FILE);
        if (!file.is_open()) {
            logger.warn("Failed to open file: " PLAYER_SETTING_FILE);
            return;
        }
        file << player_j.dump(4);
        file.close();
    }
}

void PlayerSetting::delOP(const xuid_t& xuid) {
    extern json config_j;
    utils::v_remove(config::op_list, xuid);
    config_j["op"] = config::op_list;
    config::saveConfig();
}

void PlayerSetting::setOP(const xuid_t& xuid) {
    extern json config_j;
    config::op_list.push_back(xuid);
    config_j["op"] = config::op_list;
    config::saveConfig();
}

void PlayerSetting::setSwitch(const xuid_t& xuid, const string& nsid, const bool& value) {
    player_j[xuid][nsid] = value;
    save_player_setting();
}

bool PlayerSetting::getSwitch(const xuid_t& xuid) {
    extern json config_j;
    if (player_j.contains(xuid)) {
        if (player_j[xuid].contains("switch")) {
            return bool(player_j[xuid]["switch"]);
        } else {
            return bool(config_j["switch"]["default"]);
        }
    } else {
        return bool(config_j["switch"]["default"]);
    }
}

bool PlayerSetting::getSwitch(const xuid_t& xuid, const string& nsid) { // 获取指定项目开关
    extern json config_j;
    if (player_j.contains(xuid) && player_j[xuid].contains(nsid)) {
        return player_j[xuid][nsid];
    } else if (config_j["switch"].contains(nsid)) {
        return bool(config_j["switch"][nsid]);
    } else {
        return true;
    }
}

void PlayerSetting::turnOff(const xuid_t& xuid) {
    player_j[xuid]["switch"] = false;
    save_player_setting();
}


void PlayerSetting::turnOff(const xuid_t& xuid, const string& nsid) { // 关闭指定项目
    player_j[xuid][nsid] = false;
    save_player_setting();
}

void PlayerSetting::turnOn(const xuid_t& xuid) {
    player_j[xuid]["switch"] = true;
    save_player_setting();
}

void PlayerSetting::turnOn(const xuid_t& xuid, const string& nsid) { // 开启指定项目
    // 两种情况
    // 当nsid包含minecraft:即表示某个方块时，删除该属性（因为默认为true）
    // 当nsid不包含时，设置为true
    if (nsid.find("minecraft:") == 0) player_j[xuid].erase(nsid);
    else player_j[xuid][nsid] = true;
    save_player_setting();
}


void PlayerSetting::load() {
    if (!std::filesystem::exists("plugins/ChainMiner/")) {
        std::filesystem::create_directory("plugins/ChainMiner/");
    } else {
        create_empty_file(); // 不存在或为空才创建
        read_player_setting();
        // logger.debug("{}", player_j.dump(4));
    }
}

PlayerSetting playerSetting; // 初始化单例

} // namespace chainminer3::playersetting