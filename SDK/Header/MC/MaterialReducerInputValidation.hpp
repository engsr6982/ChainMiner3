// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ContainerValidationBase.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MaterialReducerInputValidation : public ContainerValidationBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MATERIALREDUCERINPUTVALIDATION
public:
    class MaterialReducerInputValidation& operator=(class MaterialReducerInputValidation const &) = delete;
    MaterialReducerInputValidation(class MaterialReducerInputValidation const &) = delete;
    MaterialReducerInputValidation() = delete;
#endif


public:
    /*0*/ virtual ~MaterialReducerInputValidation();
    /*1*/ virtual bool isValidSlotForContainer(class ContainerScreenContext const &, class Container const &, int) const;
    /*2*/ virtual bool isItemAllowedInSlot(class ContainerScreenContext const &, int, class ItemStackBase const &, int) const;
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual bool isItemAllowedToAdd(class ItemStack const &) const;
    /*5*/ virtual void __unk_vfn_5();
    /*6*/ virtual bool canItemMoveToContainer(class ItemStackBase const &) const;
    /*7*/ virtual void __unk_vfn_7();
    /*8*/ virtual int getContainerOffset(class ContainerScreenContext const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MATERIALREDUCERINPUTVALIDATION
    MCVAPI bool canDestroy(class ContainerScreenContext const &) const;
    MCVAPI int getAvailableSetCount(int, class ItemStackBase const &) const;
#endif
    MCAPI MaterialReducerInputValidation(class ContainerScreenContext const &);



};