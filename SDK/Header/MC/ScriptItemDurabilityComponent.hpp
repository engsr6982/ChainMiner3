// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ScriptObject.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptItemDurabilityComponent : public ScriptObject {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTITEMDURABILITYCOMPONENT
public:
    ScriptItemDurabilityComponent() = delete;
#endif

public:
    /*0*/ virtual ~ScriptItemDurabilityComponent();
    /*
    inline  ~ScriptItemDurabilityComponent(){
         (ScriptItemDurabilityComponent::*rv)();
        *((void**)&rv) = dlsym("??1ScriptItemDurabilityComponent@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI ScriptItemDurabilityComponent(class ScriptItemDurabilityComponent const &);
    MCAPI ScriptItemDurabilityComponent(class Scripting::WeakTypedObjectHandle<class ScriptItemStack>, class Scripting::WeakLifetimeScope const &);
    MCAPI class Scripting::Result<int> getCurrentDamage();
    MCAPI class Scripting::Result<int> getDamageChance(int);
    MCAPI class Scripting::Result<struct FloatRange> getDamageRange();
    MCAPI class Scripting::Result<int> getMaxDamage();
    MCAPI class ScriptItemDurabilityComponent & operator=(class ScriptItemDurabilityComponent const &);
    MCAPI void setCurrentDamage(int);
    MCAPI static class Scripting::ClassBindingBuilder<class ScriptItemDurabilityComponent> bind(struct Scripting::Version);
    MCAPI static std::string const & getTypeName();

protected:

private:

};