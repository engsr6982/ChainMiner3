// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PerlinNoise {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PERLINNOISE
public:
    class PerlinNoise& operator=(class PerlinNoise const &) = delete;
    PerlinNoise() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PERLINNOISE
#endif
    MCAPI PerlinNoise(class PerlinNoise const &);
    MCAPI PerlinNoise(class IRandom &, int, int);
    MCAPI PerlinNoise(class IRandom &, struct YBlendingBugSettings, int, int);
    MCAPI PerlinNoise(unsigned int, int, int);
    MCAPI void getRegion(float *, class Vec2 const &, int, int, class Vec2 const &, float) const;
    MCAPI void getRegion(float *, class Vec3 const &, int, int, int, class Vec3 const &) const;
    MCAPI float getValue(class Vec3 const &) const;
    MCAPI float getValueNormalized(class Vec3 const &) const;
    MCAPI ~PerlinNoise();

//private:
    MCAPI void _init(class IRandom &, struct YBlendingBugSettings);


private:


};