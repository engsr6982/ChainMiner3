/**
 * @file  ActorParticles.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC namespace ActorParticles.
 *
 */
namespace ActorParticles {

#define AFTER_EXTRA

#undef AFTER_EXTRA
    /**
     * @symbol ?calculateDustParticleNumberFromFall@ActorParticles@@YAIM@Z
     * @hash   599019762
     */
    MCAPI unsigned int calculateDustParticleNumberFromFall(float);
    /**
     * @symbol ?getDustParticlePosition@ActorParticles@@YA?AVVec3@@AEBV2@AEBVAABB@@@Z
     * @hash   -1400133420
     */
    MCAPI class Vec3 getDustParticlePosition(class Vec3 const &, class AABB const &);
    /**
     * @symbol ?spawnBalloonPopParticles@ActorParticles@@YAXIVAABB@@W4PaletteColor@@AEAVILevel@@AEAVRandom@@@Z
     * @hash   1342999005
     */
    MCAPI void spawnBalloonPopParticles(unsigned int, class AABB, enum class PaletteColor, class ILevel &, class Random &);
    /**
     * @symbol ?spawnDeathParticles@ActorParticles@@YAXVVec3@@VVec2@@MAEAVILevel@@@Z
     * @hash   737803132
     */
    MCAPI void spawnDeathParticles(class Vec3, class Vec2, float, class ILevel &);
    /**
     * @symbol ?spawnDustParticlesFromFalling@ActorParticles@@YAXIVVec3@@AEAVILevel@@AEBVBlock@@VBlockPos@@@Z
     * @hash   1537793087
     */
    MCAPI void spawnDustParticlesFromFalling(unsigned int, class Vec3, class ILevel &, class Block const &, class BlockPos);
    /**
     * @symbol ?spawnParticlesInArea@ActorParticles@@YAXAEAVILevel@@IW4ParticleType@@AEBVVec3@@AEBVVec2@@AEAVRandom@@@Z
     * @hash   -1447037082
     */
    MCAPI void spawnParticlesInArea(class ILevel &, unsigned int, enum class ParticleType, class Vec3 const &, class Vec2 const &, class Random &);
    /**
     * @symbol ?spawnPukeParticles@ActorParticles@@YAXIIVVec3@@0AEAVILevel@@AEAVRandom@@@Z
     * @hash   1757580675
     */
    MCAPI void spawnPukeParticles(unsigned int, unsigned int, class Vec3, class Vec3, class ILevel &, class Random &);
    /**
     * @symbol ?spawnTreasureHuntingParticles@ActorParticles@@YAXIVVec3@@0VVec2@@AEAVILevel@@AEAVRandom@@@Z
     * @hash   -1368672889
     */
    MCAPI void spawnTreasureHuntingParticles(unsigned int, class Vec3, class Vec3, class Vec2, class ILevel &, class Random &);

};