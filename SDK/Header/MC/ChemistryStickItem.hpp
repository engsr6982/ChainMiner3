// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Item.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ChemistryStickItem : public Item {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CHEMISTRYSTICKITEM
public:
    class ChemistryStickItem& operator=(class ChemistryStickItem const &) = delete;
    ChemistryStickItem(class ChemistryStickItem const &) = delete;
    ChemistryStickItem() = delete;
#endif


public:
    /*0*/ virtual ~ChemistryStickItem();
    /*7*/ virtual void __unk_vfn_7();
    /*10*/ virtual void __unk_vfn_10();
    /*13*/ virtual void __unk_vfn_13();
    /*15*/ virtual void __unk_vfn_15();
    /*30*/ virtual class Item & setMaxDamage(int);
    /*51*/ virtual void __unk_vfn_51();
    /*53*/ virtual void __unk_vfn_53();
    /*61*/ virtual bool isValidRepairItem(class ItemStackBase const &, class ItemStackBase const &, class BaseGameVersion const &) const;
    /*66*/ virtual void __unk_vfn_66();
    /*70*/ virtual void __unk_vfn_70();
    /*71*/ virtual void __unk_vfn_71();
    /*72*/ virtual void __unk_vfn_72();
    /*75*/ virtual void __unk_vfn_75();
    /*79*/ virtual void __unk_vfn_79();
    /*80*/ virtual void __unk_vfn_80();
    /*84*/ virtual class ItemStack & use(class ItemStack &, class Player &) const;
    /*86*/ virtual enum ItemUseMethod useTimeDepleted(class ItemStack &, class Level *, class Player *) const;
    /*89*/ virtual void hurtActor(class ItemStack &, class Actor &, class Mob &) const;
    /*93*/ virtual bool mineBlock(class ItemStack &, class Block const &, int, int, int, class Actor *) const;
    /*101*/ virtual bool inventoryTick(class ItemStack &, class Level &, class Actor &, int, bool) const;
    /*105*/ virtual void fixupCommon(class ItemStackBase &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CHEMISTRYSTICKITEM
    MCVAPI bool showsDurabilityInCreative() const;
    MCVAPI bool uniqueAuxValues() const;
#endif
    MCAPI ChemistryStickItem(std::string const &, int);
    MCAPI static enum ItemColor getColorType(int);
    MCAPI static bool isActive(int);
    MCAPI static bool isChemistryStick(class ItemStackBase const &);

//protected:
    MCAPI std::string _getColorName(int) const;
    MCAPI bool _tick(class ItemStack &, unsigned __int64) const;

//private:
    MCAPI void _storeActivationTimestamp(class ItemStack &, unsigned __int64, int) const;


protected:

private:
    MCAPI static std::string const ACTIVATION_TIMESTAMP_TAG;
    MCAPI static int const ACTIVE_BIT;
    MCAPI static int const COLOR_BITS;
    MCAPI static int const COLOR_MASK;
    MCAPI static int const DAMAGE_BITS;
    MCAPI static int const DAMAGE_MASK;
    MCAPI static int const DAMAGE_START_BIT;


};