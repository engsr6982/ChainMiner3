

#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <string>
#include <vector>

namespace chainminer3::config {


void initConfig();

void readConfig();

void saveConfig();

void updateConfig();

void writeDefaultConfig();

nlohmann::json getDefaultConfig();

struct BlockInfo {
    int limit{256};       // 最大值
    int cost{0};          // 每个所需
    int enchSilkTouch{0}; // 精准采集(0-不允许,1-当且仅当有精准采集魔咒,2-有无精准采集都会挖掘)
    std::vector<std::string> tools;              // 可用工具（由于数量较少，vector比set快）
    std::vector<std::string> similar;            // 同类方块
    std::string              texture;            // 纹理地址(为空则自动生成)
    std::string              name;               // 展示的名称
    std::string              detectMode{"abut"}; // 探测模式(abut-邻接,cube-3*3*3)
    bool                     enabled{true};      // 是否启用
};

class ConfigManager {
public:
    static bool        multiply_damage_switch;
    static double      multiply_damage_min;
    static double      multiply_damage_max;
    static std::string msg_prefix;
};

// 全局变量
extern nlohmann::json                             config_j;
extern std::vector<std::string>                   op_list;
extern std::unordered_map<std::string, BlockInfo> block_list;


} // namespace chainminer3::config
