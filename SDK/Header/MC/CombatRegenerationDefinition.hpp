// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CombatRegenerationDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMBATREGENERATIONDEFINITION
public:
    class CombatRegenerationDefinition& operator=(class CombatRegenerationDefinition const &) = delete;
    CombatRegenerationDefinition(class CombatRegenerationDefinition const &) = delete;
    CombatRegenerationDefinition() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMBATREGENERATIONDEFINITION
#endif
    MCAPI static void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class CombatRegenerationDefinition>> &);



};