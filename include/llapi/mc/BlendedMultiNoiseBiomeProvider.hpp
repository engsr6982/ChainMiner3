/**
 * @file  BlendedMultiNoiseBiomeProvider.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ChunkLocalNoiseCache.hpp"
#include "RTree.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class BlendedMultiNoiseBiomeProvider.
 *
 */
class BlendedMultiNoiseBiomeProvider {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLENDEDMULTINOISEBIOMEPROVIDER
public:
    class BlendedMultiNoiseBiomeProvider& operator=(class BlendedMultiNoiseBiomeProvider const &) = delete;
    BlendedMultiNoiseBiomeProvider(class BlendedMultiNoiseBiomeProvider const &) = delete;
    BlendedMultiNoiseBiomeProvider() = delete;
#endif

public:
    /**
     * @hash   -251789290
     * @symbol ??0BlendedMultiNoiseBiomeProvider@@QEAA@AEBUOverworldNoises3d@@VParameterList@@AEAVSeamlessChunkBlendingAttenuatorFactory@@AEBVBiomeRegistry@@@Z
     */
    MCAPI BlendedMultiNoiseBiomeProvider(struct OverworldNoises3d const &, class ParameterList, class SeamlessChunkBlendingAttenuatorFactory &, class BiomeRegistry const &);
    /**
     * @hash   597502848
     * @symbol ?tryGetBiome@BlendedMultiNoiseBiomeProvider@@QEBAPEBVBiome@@AEBUGetBiomeOptions@@@Z
     */
    MCAPI class Biome const * tryGetBiome(struct GetBiomeOptions const &) const;
    /**
     * @hash   -512006245
     * @symbol ?tryGetBiome@BlendedMultiNoiseBiomeProvider@@QEBAPEBVBiome@@AEBUGetBiomeOptions@@AEBUCacheEntry@ChunkLocalNoiseCache@@PEAUHint@RTree@@@Z
     */
    MCAPI class Biome const * tryGetBiome(struct GetBiomeOptions const &, struct ChunkLocalNoiseCache::CacheEntry const &, struct RTree::Hint *) const;
    /**
     * @hash   -469541398
     * @symbol ??1BlendedMultiNoiseBiomeProvider@@QEAA@XZ
     */
    MCAPI ~BlendedMultiNoiseBiomeProvider();

};