// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class StackResultStorageFeature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STACKRESULTSTORAGEFEATURE
public:
    class StackResultStorageFeature& operator=(class StackResultStorageFeature const &) = delete;
    StackResultStorageFeature(class StackResultStorageFeature const &) = delete;
    StackResultStorageFeature() = delete;
#endif

public:

protected:
    MCAPI StackResultStorageFeature(class WeakStorageFeature const &);
    MCAPI class IFeature & _getStackRef() const;
    MCAPI bool _hasValue() const;

private:

};