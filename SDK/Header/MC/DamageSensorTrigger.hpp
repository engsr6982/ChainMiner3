// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct DamageSensorTrigger {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DAMAGESENSORTRIGGER
public:
    struct DamageSensorTrigger& operator=(struct DamageSensorTrigger const &) = delete;
#endif

public:
    MCAPI DamageSensorTrigger(struct DamageSensorTrigger const &);
    MCAPI DamageSensorTrigger();
    MCAPI void setCause(std::string const &);
    MCAPI ~DamageSensorTrigger();

protected:

private:

};