// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "WaterAnimal.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class Tadpole : public WaterAnimal {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TADPOLE
public:
    class Tadpole& operator=(class Tadpole const &) = delete;
    Tadpole(class Tadpole const &) = delete;
    Tadpole() = delete;
#endif


public:
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~Tadpole();
    /*40*/ virtual void __unk_vfn_40();
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*81*/ virtual void __unk_vfn_81();
    /*87*/ virtual void __unk_vfn_87();
    /*94*/ virtual void __unk_vfn_94();
    /*97*/ virtual void __unk_vfn_97();
    /*104*/ virtual void __unk_vfn_104();
    /*106*/ virtual void __unk_vfn_106();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*180*/ virtual void __unk_vfn_180();
    /*194*/ virtual void __unk_vfn_194();
    /*219*/ virtual void __unk_vfn_219();
    /*220*/ virtual void __unk_vfn_220();
    /*245*/ virtual void __unk_vfn_245();
    /*248*/ virtual void __unk_vfn_248();
    /*264*/ virtual void __unk_vfn_264();
    /*272*/ virtual void __unk_vfn_272();
    /*281*/ virtual void __unk_vfn_281();
    /*310*/ virtual void __unk_vfn_310();
    /*314*/ virtual void __unk_vfn_314();
    /*348*/ virtual void __unk_vfn_348();
    /*362*/ virtual void __unk_vfn_362();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TADPOLE
#endif
    MCAPI Tadpole(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);



};