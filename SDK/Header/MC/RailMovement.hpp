// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RailMovement {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RAILMOVEMENT
public:
    class RailMovement& operator=(class RailMovement const &) = delete;
    RailMovement(class RailMovement const &) = delete;
    RailMovement() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RAILMOVEMENT
#endif
    MCAPI static bool getPos(class Actor &, class Vec3 &, class Vec3);



};