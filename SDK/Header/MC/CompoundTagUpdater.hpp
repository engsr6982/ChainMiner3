// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CompoundTagUpdater {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMPOUNDTAGUPDATER
public:
    class CompoundTagUpdater& operator=(class CompoundTagUpdater const &) = delete;
    CompoundTagUpdater(class CompoundTagUpdater const &) = delete;
    CompoundTagUpdater() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMPOUNDTAGUPDATER
#endif
    MCAPI bool update(class CompoundTag &) const;
    MCAPI ~CompoundTagUpdater();



};