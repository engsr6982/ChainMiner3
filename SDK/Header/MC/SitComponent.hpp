// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SitComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SITCOMPONENT
public:
    class SitComponent& operator=(class SitComponent const &) = delete;
    SitComponent(class SitComponent const &) = delete;
    SitComponent() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SITCOMPONENT
#endif
    MCAPI bool getInteraction(class Actor &, class Player &, class ActorInteraction &);



};