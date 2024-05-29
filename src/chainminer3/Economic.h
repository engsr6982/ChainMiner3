#pragma once
#include "mc/world/actor/player/Player.h"
#include <string>

using string = std::string;

namespace chainminer3::economic {

typedef long long money_t;
typedef string    xuid_t;

class Economic {
public:
    int    mode   = 0;
    string sbname = "money";

    money_t getMoney(Player* pl);
    bool    setMoney(Player* pl, money_t money);
    bool    addMoney(Player* pl, money_t money);
    bool    reduceMoney(Player* pl, money_t money);
    bool    clearMoneyHist(int time);
};

extern Economic economic;

} // namespace chainminer3::economic