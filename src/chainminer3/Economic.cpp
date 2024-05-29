#include "Economic.h"
#include "LLMoney.h"
#include "ll/api/service/Bedrock.h"
#include "mc/deps/core/mce/UUID.h"
#include "mc/world/actor/player/PlayerScoreSetFunction.h"
#include "mc/world/level/Level.h"
#include "mc/world/scores/ScoreInfo.h"
#include "mc/world/scores/Scoreboard.h"
#include "pch.h"
#include <mc/world/scores/Objective.h>
#include <mc/world/scores/Scoreboard.h>
#include <mc/world/scores/ScoreboardId.h>
#include <string>


// LLMoney不存在返回false,其余返回true
// bool Economic::init() {
//     auto pl = ll::getPlugin("LLMoney");
//     if (pl) {
//         llmoney.init();
//     }
//     return !!pl;
// }

money_t Economic::getMoney(Player* pl) {
    if (Economic::mode == 1) {
        return LLMoney_Get(pl->getXuid());
    } else if (Economic::mode == 2) {
        // ScoreboardMoney
        auto&       player     = *pl;
        Scoreboard& scoreboard = ll::service::getLevel()->getScoreboard();
        Objective*  obj        = scoreboard.getObjective(Economic::sbname);
        if (!obj) return 0;
        const ScoreboardId& id = scoreboard.getScoreboardId(player);
        if (!id.isValid()) {
            scoreboard.createScoreboardId(player);
        }
        return obj->getPlayerScore(id).mScore;
    }
    return 0;
}

bool Economic::setMoney(Player* pl, money_t money) {
    if (Economic::mode == 1) {
        return LLMoney_Set(pl->getXuid(), money);
    } else if (Economic::mode == 2) {
        // ScoreboardMoney
        auto&       player     = *pl;
        Scoreboard& scoreboard = ll::service::getLevel()->getScoreboard();
        Objective*  obj        = scoreboard.getObjective(Economic::sbname);
        if (!obj) return false;
        const ScoreboardId& id = scoreboard.getScoreboardId(player);
        if (!id.isValid()) {
            scoreboard.createScoreboardId(player);
        }
        bool isSuccess = false;
        scoreboard.modifyPlayerScore(isSuccess, id, *obj, int(money), PlayerScoreSetFunction::Set);
        return isSuccess;
    }
    return false;
}

bool Economic::addMoney(Player* pl, money_t money) {
    if (Economic::mode == 1) {
        return LLMoney_Add(pl->getXuid(), money);
    } else if (Economic::mode == 2) {
        // ScoreboardMoney
        auto&       player     = *pl;
        Scoreboard& scoreboard = ll::service::getLevel()->getScoreboard();
        Objective*  obj        = scoreboard.getObjective(Economic::sbname);
        if (!obj) return false;

        const ScoreboardId& id = scoreboard.getScoreboardId(player);
        if (!id.isValid()) {
            scoreboard.createScoreboardId(player);
        }
        bool isSuccess = false;
        scoreboard.modifyPlayerScore(isSuccess, id, *obj, int(money), PlayerScoreSetFunction::Add);
        return isSuccess;
    }
    return false;
}

bool Economic::reduceMoney(Player* pl, money_t money) {
    if (Economic::mode == 1) {
        return LLMoney_Reduce(pl->getXuid(), money);
    } else if (Economic::mode == 2) {
        // ScoreboardMoney
        auto&       player     = *pl;
        Scoreboard& scoreboard = ll::service::getLevel()->getScoreboard();
        Objective*  obj        = scoreboard.getObjective(Economic::sbname);
        if (!obj) return false;
        const ScoreboardId& id = scoreboard.getScoreboardId(player);
        if (!id.isValid()) {
            scoreboard.createScoreboardId(player);
        }
        bool isSuccess = false;
        scoreboard.modifyPlayerScore(isSuccess, id, *obj, int(money), PlayerScoreSetFunction::Subtract);
        return isSuccess;
    }
    return false;
}

bool Economic::clearMoneyHist(int time) {
    LLMoney_ClearHist(time);
    return true;
}