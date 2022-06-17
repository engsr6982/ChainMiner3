// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SculkPatchFeature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCULKPATCHFEATURE
public:
    class SculkPatchFeature& operator=(class SculkPatchFeature const &) = delete;
    SculkPatchFeature(class SculkPatchFeature const &) = delete;
    SculkPatchFeature() = delete;
#endif


public:
    /*0*/ virtual ~SculkPatchFeature();
    /*1*/ virtual class std::optional<class BlockPos> place(class IBlockWorldGenAPI &, class BlockPos const &, class Random &, class RenderParams &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCULKPATCHFEATURE
#endif

//private:
    MCAPI class std::optional<class BlockPos> _getNearestSolidNeighborPos(class IBlockWorldGenAPI &, class BlockPos const &) const;


private:


};