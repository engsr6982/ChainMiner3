// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once

struct Tick
{
    unsigned long long t;
    
    constexpr operator unsigned long long() const
    {
        return t;
    }
    
    constexpr operator unsigned long long&()
    {
        return t;
    }
    
    constexpr Tick(unsigned long long v)
        : t(v){};

    constexpr Tick(const Tick& v)
        : t(v.t){};
    
    constexpr Tick()
        : t(0){};
};
