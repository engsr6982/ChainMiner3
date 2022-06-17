// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Bedrock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class EntityEnterVolumeSystem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ENTITYENTERVOLUMESYSTEM
public:
    class EntityEnterVolumeSystem& operator=(class EntityEnterVolumeSystem const &) = delete;
    EntityEnterVolumeSystem(class EntityEnterVolumeSystem const &) = delete;
    EntityEnterVolumeSystem() = delete;
#endif


public:
    /*0*/ virtual ~EntityEnterVolumeSystem();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void tick(class EntityRegistry &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ENTITYENTERVOLUMESYSTEM
#endif
    MCAPI EntityEnterVolumeSystem(class gsl::not_null<class Bedrock::NonOwnerPointer<class ILevel const>>);

//private:
    MCAPI void _tick(class EntityContext &, class VolumeBoundsComponent &) const;


private:


};