// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ExperimentStorage {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EXPERIMENTSTORAGE
public:
    class ExperimentStorage& operator=(class ExperimentStorage const &) = delete;
    ExperimentStorage(class ExperimentStorage const &) = delete;
    ExperimentStorage() = delete;
#endif

public:
    MCAPI bool isAnyToggleEnabled() const;
    MCAPI bool wereAnyExperimentsEverToggled() const;
    MCAPI ~ExperimentStorage();

protected:

private:

};