// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SlimeKeepOnJumpingDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SLIMEKEEPONJUMPINGDEFINITION
public:
    class SlimeKeepOnJumpingDefinition& operator=(class SlimeKeepOnJumpingDefinition const &) = delete;
    SlimeKeepOnJumpingDefinition(class SlimeKeepOnJumpingDefinition const &) = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SLIMEKEEPONJUMPINGDEFINITION
#endif
    MCAPI SlimeKeepOnJumpingDefinition();
    MCAPI void initialize(class EntityContext &, class SlimeKeepOnJumpingGoal &);
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class SlimeKeepOnJumpingDefinition>> &);



};