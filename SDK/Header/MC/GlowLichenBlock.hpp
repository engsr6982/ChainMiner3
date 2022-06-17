// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "MultifaceBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class GlowLichenBlock : public MultifaceBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GLOWLICHENBLOCK
public:
    class GlowLichenBlock& operator=(class GlowLichenBlock const &) = delete;
    GlowLichenBlock(class GlowLichenBlock const &) = delete;
    GlowLichenBlock() = delete;
#endif


public:
    /*0*/ virtual ~GlowLichenBlock();
    /*19*/ virtual void __unk_vfn_19();
    /*28*/ virtual void __unk_vfn_28();
    /*29*/ virtual void __unk_vfn_29();
    /*31*/ virtual void __unk_vfn_31();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*35*/ virtual void __unk_vfn_35();
    /*36*/ virtual void __unk_vfn_36();
    /*37*/ virtual void __unk_vfn_37();
    /*38*/ virtual void __unk_vfn_38();
    /*39*/ virtual void __unk_vfn_39();
    /*40*/ virtual void __unk_vfn_40();
    /*41*/ virtual void __unk_vfn_41();
    /*43*/ virtual void __unk_vfn_43();
    /*44*/ virtual void __unk_vfn_44();
    /*45*/ virtual void __unk_vfn_45();
    /*46*/ virtual void __unk_vfn_46();
    /*47*/ virtual void __unk_vfn_47();
    /*48*/ virtual void __unk_vfn_48();
    /*58*/ virtual void __unk_vfn_58();
    /*59*/ virtual void __unk_vfn_59();
    /*72*/ virtual void __unk_vfn_72();
    /*79*/ virtual void __unk_vfn_79();
    /*83*/ virtual bool onFertilized(class BlockSource &, class BlockPos const &, class Actor *, enum FertilizerType) const;
    /*85*/ virtual bool canBeFertilized(class BlockSource &, class BlockPos const &, class Block const &) const;
    /*99*/ virtual int getResourceCount(class Randomize &, class Block const &, int) const;
    /*104*/ virtual void __unk_vfn_104();
    /*124*/ virtual void __unk_vfn_124();
    /*126*/ virtual void __unk_vfn_126();
    /*127*/ virtual void __unk_vfn_127();
    /*132*/ virtual void __unk_vfn_132();
    /*148*/ virtual void __unk_vfn_148();
    /*153*/ virtual class BlockLegacy & init();
    /*165*/ virtual void __unk_vfn_165();
    /*179*/ virtual void __unk_vfn_179();
    /*180*/ virtual void __unk_vfn_180();
    /*183*/ virtual void playerDestroy(class Player &, class BlockPos const &, class Block const &) const;
    /*187*/ virtual void __unk_vfn_187();
    /*199*/ virtual void __unk_vfn_199();
    /*203*/ virtual class Block const & getMultifaceBlock() const;
    /*204*/ virtual class MultifaceSpreader const & getMultifaceSpreader() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_GLOWLICHENBLOCK
    MCVAPI bool canBeSilkTouched() const;
#endif
    MCAPI GlowLichenBlock(std::string const &, int, class Material const &);



};