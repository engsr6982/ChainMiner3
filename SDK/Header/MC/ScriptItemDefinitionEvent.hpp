// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ScriptItemDefinitionEvent {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTITEMDEFINITIONEVENT
public:
    ScriptItemDefinitionEvent() = delete;
#endif

public:
    MCAPI ScriptItemDefinitionEvent(struct ScriptItemDefinitionEvent const &);
    MCAPI ScriptItemDefinitionEvent(class Scripting::StrongTypedObjectHandle<class ScriptItemStack>, struct ItemDefinitionEventTriggeredEvent const &, class Scripting::WeakLifetimeScope const &);
    MCAPI struct ScriptItemDefinitionEvent & operator=(struct ScriptItemDefinitionEvent &&);
    MCAPI struct ScriptItemDefinitionEvent & operator=(struct ScriptItemDefinitionEvent const &);

protected:

private:

};