// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LootItemRandomChanceWithSpecialModifierCondition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LOOTITEMRANDOMCHANCEWITHSPECIALMODIFIERCONDITION
public:
    class LootItemRandomChanceWithSpecialModifierCondition& operator=(class LootItemRandomChanceWithSpecialModifierCondition const &) = delete;
    LootItemRandomChanceWithSpecialModifierCondition(class LootItemRandomChanceWithSpecialModifierCondition const &) = delete;
    LootItemRandomChanceWithSpecialModifierCondition() = delete;
#endif

public:
    /*0*/ virtual ~LootItemRandomChanceWithSpecialModifierCondition();
    /*1*/ virtual bool applies(class Random &, class LootTableContext &);
    MCAPI static std::unique_ptr<class LootItemCondition> deserialize(class Json::Value);

protected:

private:

};