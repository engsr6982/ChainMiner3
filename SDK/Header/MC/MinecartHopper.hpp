// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Minecart.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MinecartHopper : public Minecart {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MINECARTHOPPER
public:
    class MinecartHopper& operator=(class MinecartHopper const &) = delete;
    MinecartHopper(class MinecartHopper const &) = delete;
    MinecartHopper() = delete;
#endif


public:
    /*14*/ virtual ~MinecartHopper();
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
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*267*/ virtual void __unk_vfn_267();
    /*275*/ virtual void __unk_vfn_275();
    /*284*/ virtual void __unk_vfn_284();
    /*285*/ virtual void destroy(class ActorDamageSource const &, bool);
    /*286*/ virtual enum MinecartType getType();
    /*287*/ virtual class Block const * getDefaultDisplayBlock() const;
    /*288*/ virtual void __unk_vfn_288();
    /*289*/ virtual int getDefaultDisplayOffset() const;
    /*290*/ virtual void applyNaturalSlowdown(class BlockSource &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MINECARTHOPPER
#endif
    MCAPI MinecartHopper(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);



};