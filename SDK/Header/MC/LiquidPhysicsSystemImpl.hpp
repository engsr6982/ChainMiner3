// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class LiquidPhysicsSystemImpl {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LIQUIDPHYSICSSYSTEMIMPL
public:
    class LiquidPhysicsSystemImpl& operator=(class LiquidPhysicsSystemImpl const &) = delete;
    LiquidPhysicsSystemImpl(class LiquidPhysicsSystemImpl const &) = delete;
    LiquidPhysicsSystemImpl() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LIQUIDPHYSICSSYSTEMIMPL
#endif
    MCAPI static void _getLiquidBlocksInAABB(std::vector<struct LiquidPhysicsSystemImpl::LiquidBlockEntry> &, class IConstBlockSource const &, class AABB const &, enum MaterialType);



};