// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScanSurfaceFeature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCANSURFACEFEATURE
public:
    class ScanSurfaceFeature& operator=(class ScanSurfaceFeature const &) = delete;
    ScanSurfaceFeature(class ScanSurfaceFeature const &) = delete;
    ScanSurfaceFeature() = delete;
#endif

public:
    /*0*/ virtual ~ScanSurfaceFeature();
    /*1*/ virtual class std::optional<class BlockPos> place(class IBlockWorldGenAPI &, class BlockPos const &, class Random &, class RenderParams &) const;

protected:

private:

};