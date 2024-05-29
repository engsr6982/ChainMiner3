#pragma once
#include "LLMoney.h"
#include "mc/world/actor/player/Player.h"
#include <string>


using std::string;

typedef long long money_t;
typedef string    xuid_t;

class Economic {
public:
    int    mode   = 0;
    string sbname = "money";
    // bool   init();

    money_t getMoney(Player* pl);
    bool    setMoney(Player* pl, money_t money);
    bool    addMoney(Player* pl, money_t money);
    bool    reduceMoney(Player* pl, money_t money);
    bool    clearMoneyHist(int time);
};