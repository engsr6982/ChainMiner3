/**
 * @file  FloatWanderGoal.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class FloatWanderGoal.
 *
 */
class FloatWanderGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FLOATWANDERGOAL
public:
    class FloatWanderGoal& operator=(class FloatWanderGoal const &) = delete;
    FloatWanderGoal(class FloatWanderGoal const &) = delete;
    FloatWanderGoal() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   1532731690
     */
    virtual ~FloatWanderGoal();
    /**
     * @vftbl  1
     * @symbol ?canUse@FloatWanderGoal@@UEAA_NXZ
     * @hash   2047926596
     */
    virtual bool canUse();
    /**
     * @vftbl  2
     * @hash   -1315668094
     */
    virtual void __unk_vfn_2();
    /**
     * @vftbl  3
     * @hash   -1314744573
     */
    virtual void __unk_vfn_3();
    /**
     * @vftbl  4
     * @hash   -1263526156
     */
    virtual void __unk_vfn_4();
    /**
     * @vftbl  5
     * @hash   738599141
     */
    virtual void __unk_vfn_5();
    /**
     * @vftbl  6
     * @symbol ?tick@FloatWanderGoal@@UEAAXXZ
     * @hash   -594613928
     */
    virtual void tick();
    /**
     * @vftbl  7
     * @symbol ?appendDebugInfo@FloatWanderGoal@@UEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   -2059526932
     */
    virtual void appendDebugInfo(std::string &) const;
    /**
     * @symbol ??0FloatWanderGoal@@QEAA@AEAVMob@@MMM_N1UFloatRange@@@Z
     * @hash   1642874203
     */
    MCAPI FloatWanderGoal(class Mob &, float, float, float, bool, bool, struct FloatRange);

//private:
    /**
     * @symbol ?_canReach@FloatWanderGoal@@AEAA_NAEBVVec3@@M@Z
     * @hash   1022270132
     */
    MCAPI bool _canReach(class Vec3 const &, float);

private:

};