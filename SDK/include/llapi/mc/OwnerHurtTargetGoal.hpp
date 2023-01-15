/**
 * @file  OwnerHurtTargetGoal.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "TargetGoal.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class OwnerHurtTargetGoal.
 *
 */
class OwnerHurtTargetGoal : public TargetGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_OWNERHURTTARGETGOAL
public:
    class OwnerHurtTargetGoal& operator=(class OwnerHurtTargetGoal const &) = delete;
    OwnerHurtTargetGoal(class OwnerHurtTargetGoal const &) = delete;
    OwnerHurtTargetGoal() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1873302636
     */
    virtual ~OwnerHurtTargetGoal();
    /**
     * @vftbl  1
     * @symbol ?canUse@OwnerHurtTargetGoal@@UEAA_NXZ
     * @hash   -21134310
     */
    virtual bool canUse();
    /**
     * @vftbl  4
     * @symbol ?start@OwnerHurtTargetGoal@@UEAAXXZ
     * @hash   -1047889277
     */
    virtual void start();
    /**
     * @vftbl  8
     * @hash   -1310126968
     */
    virtual void __unk_vfn_8();
    /**
     * @vftbl  9
     * @hash   -1258908551
     */
    virtual void __unk_vfn_9();
    /**
     * @symbol ??0OwnerHurtTargetGoal@@QEAA@AEAVMob@@AEBV?$vector@UMobDescriptor@@V?$allocator@UMobDescriptor@@@std@@@std@@@Z
     * @hash   794521476
     */
    MCAPI OwnerHurtTargetGoal(class Mob &, std::vector<struct MobDescriptor> const &);

};