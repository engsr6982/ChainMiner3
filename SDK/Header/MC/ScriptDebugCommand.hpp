// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptDebugCommand : public Command {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTDEBUGCOMMAND
public:
    class ScriptDebugCommand& operator=(class ScriptDebugCommand const &) = delete;
    ScriptDebugCommand(class ScriptDebugCommand const &) = delete;
#endif


public:
    /*0*/ virtual ~ScriptDebugCommand();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCRIPTDEBUGCOMMAND
#endif
    MCAPI ScriptDebugCommand();

//protected:
    MCAPI void _handleDebuggerAttach(class IScriptDebugger *, std::string const &, enum ScriptDebugCommand::DebuggerAction, std::string const &, unsigned short, class CommandOutput &) const;
    MCAPI void _handleProfilerAction(class IScriptDebugger *, std::string const &, enum ScriptDebugCommand::ProfilerAction, class CommandOutput &) const;


protected:


};