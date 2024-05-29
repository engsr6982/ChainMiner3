#pragma once
#include "Utils.hpp"
#include "nlohmann/json.hpp"
#include "plugin/MyPlugin.h"


using string = std::string;


namespace chainminer3::playersetting {


typedef string xuid_t;


class PlayerSetting {
public:
    nlohmann::json player_j = {};

    void load();
    void turnOn(const xuid_t& xuid, const string& nsid);
    void turnOn(const xuid_t& xuid);
    void turnOff(const xuid_t& xuid, const string& nsid);
    void turnOff(const xuid_t& xuid);
    bool getSwitch(const xuid_t& xuid, const string& nsid);
    bool getSwitch(const xuid_t& xuid);
    void setSwitch(const xuid_t& xuid, const string& nsid, const bool& value);

    static void setOP(const xuid_t& xuid);
    static void delOP(const xuid_t& xuid);

private:
    void create_empty_file();
    void read_player_setting();
    void save_player_setting();
};

extern PlayerSetting playerSetting;

} // namespace chainminer3::playersetting
