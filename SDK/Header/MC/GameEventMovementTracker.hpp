// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class GameEventMovementTracker {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GAMEEVENTMOVEMENTTRACKER
public:
    class GameEventMovementTracker& operator=(class GameEventMovementTracker const &) = delete;
    GameEventMovementTracker(class GameEventMovementTracker const &) = delete;
    GameEventMovementTracker() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_GAMEEVENTMOVEMENTTRACKER
#endif
    MCAPI GameEventMovementTracker(class Vec3 const &);
    MCAPI void trackMovement(class Actor &, bool);



};