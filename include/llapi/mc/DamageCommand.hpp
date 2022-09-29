/**
 * @file  DamageCommand.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class DamageCommand.
 *
 */
class DamageCommand : public Command {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DAMAGECOMMAND
public:
    class DamageCommand& operator=(class DamageCommand const &) = delete;
    DamageCommand(class DamageCommand const &) = delete;
    DamageCommand() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol __unk_destructor_0
     */
    virtual ~DamageCommand();
    /**
     * @hash   -1090180825
     * @vftbl  1
     * @symbol ?execute@DamageCommand@@UEBAXAEBVCommandOrigin@@AEAVCommandOutput@@@Z
     */
    virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
    /**
     * @hash   918375072
     * @symbol ?setup@DamageCommand@@SAXAEAVCommandRegistry@@@Z
     */
    MCAPI static void setup(class CommandRegistry &);

//private:
    /**
     * @hash   -1991130110
     * @symbol ?_applyDamage@DamageCommand@@AEBAXAEAV?$CommandSelectorResults@VActor@@@@AEBVActorDamageSource@@AEAVCommandOutput@@@Z
     */
    MCAPI void _applyDamage(class CommandSelectorResults<class Actor> &, class ActorDamageSource const &, class CommandOutput &) const;

private:

};