// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RaidTriggerComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RAIDTRIGGERCOMPONENT
public:
    class RaidTriggerComponent& operator=(class RaidTriggerComponent const &) = delete;
    RaidTriggerComponent(class RaidTriggerComponent const &) = delete;
    RaidTriggerComponent() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RAIDTRIGGERCOMPONENT
#endif
    MCAPI void initFromDefinition(class Actor &);
    MCAPI void reloadComponent(class Actor &);



};