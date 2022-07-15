// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "WaterAnimal.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Dolphin : public WaterAnimal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DOLPHIN
public:
    class Dolphin& operator=(class Dolphin const &) = delete;
    Dolphin(class Dolphin const &) = delete;
    Dolphin() = delete;
#endif


public:
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~Dolphin();
    /*40*/ virtual void __unk_vfn_40();
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*81*/ virtual void __unk_vfn_81();
    /*87*/ virtual void __unk_vfn_87();
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*181*/ virtual void __unk_vfn_181();
    /*193*/ virtual bool canBePulledIntoVehicle() const;
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*267*/ virtual void __unk_vfn_267();
    /*275*/ virtual void __unk_vfn_275();
    /*284*/ virtual void __unk_vfn_284();
    /*299*/ virtual void aiStep();
    /*312*/ virtual void __unk_vfn_312();
    /*316*/ virtual void __unk_vfn_316();
    /*342*/ virtual bool createAIGoals();
    /*348*/ virtual float _getWalkTargetValue(class BlockPos const &);
    /*350*/ virtual void __unk_vfn_350();
    /*364*/ virtual void __unk_vfn_364();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DOLPHIN
#endif
    MCAPI Dolphin(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);



};