// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScheduleCommand : public Command {

#define AFTER_EXTRA
// Add Member There
public:
struct FunctionInfo {
    FunctionInfo() = delete;
    FunctionInfo(FunctionInfo const&) = delete;
    FunctionInfo(FunctionInfo const&&) = delete;
};

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCHEDULECOMMAND
public:
    class ScheduleCommand& operator=(class ScheduleCommand const &) = delete;
    ScheduleCommand(class ScheduleCommand const &) = delete;
    ScheduleCommand() = delete;
#endif


public:
    /*0*/ virtual ~ScheduleCommand();
    /*1*/ virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCHEDULECOMMAND
#endif
    MCAPI static void setup(class CommandRegistry &);

//private:
    MCAPI void _delay(class CommandOrigin const &, class CommandOutput &) const;
    MCAPI void _onAreaLoaded(class CommandOrigin const &, class CommandOutput &) const;
    MCAPI struct ScheduleCommand::FunctionInfo _tryGetFunction(class FunctionManager &, class CommandOutput &) const;


private:


};