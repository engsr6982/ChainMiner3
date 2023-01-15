/**
 * @file  FoodItemComponent.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class FoodItemComponent.
 *
 */
class FoodItemComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FOODITEMCOMPONENT
public:
    FoodItemComponent(class FoodItemComponent const &) = delete;
    FoodItemComponent() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FOODITEMCOMPONENT
    /**
     * @symbol ?canAlwaysEat@FoodItemComponent@@UEBA_NXZ
     * @hash   -2117798299
     */
    MCVAPI bool canAlwaysEat() const;
    /**
     * @symbol ?eatItem@FoodItemComponent@@UEAAPEBVItem@@AEAVItemStack@@AEAVActor@@AEAVLevel@@@Z
     * @hash   -2013179198
     */
    MCVAPI class Item const * eatItem(class ItemStack &, class Actor &, class Level &);
    /**
     * @symbol ?getNutrition@FoodItemComponent@@UEBAHXZ
     * @hash   -1867384879
     */
    MCVAPI int getNutrition() const;
    /**
     * @symbol ?getSaturationModifier@FoodItemComponent@@UEBAMXZ
     * @hash   -1262328895
     */
    MCVAPI float getSaturationModifier() const;
    /**
     * @symbol ?use@FoodItemComponent@@UEAA_NAEAVItemStack@@AEAVPlayer@@@Z
     * @hash   968878000
     */
    MCVAPI bool use(class ItemStack &, class Player &);
    /**
     * @symbol ?useTimeDepleted@FoodItemComponent@@UEAAPEBVItem@@AEAVItemStack@@AEAVPlayer@@AEAVLevel@@@Z
     * @hash   737684258
     */
    MCVAPI class Item const * useTimeDepleted(class ItemStack &, class Player &, class Level &);
#endif
    /**
     * @symbol ?getUsingConvertsToItemDescriptor@FoodItemComponent@@QEBA?AVItemDescriptor@@XZ
     * @hash   -884649024
     */
    MCAPI class ItemDescriptor getUsingConvertsToItemDescriptor() const;
    /**
     * @symbol ??4FoodItemComponent@@QEAAAEAV0@AEBV0@@Z
     * @hash   -2438612
     */
    MCAPI class FoodItemComponent & operator=(class FoodItemComponent const &);
    /**
     * @symbol ?bindType@FoodItemComponent@@SAXXZ
     * @hash   -988290257
     */
    MCAPI static void bindType();
    /**
     * @symbol ?getIdentifier@FoodItemComponent@@SAAEBVHashedString@@XZ
     * @hash   -1571927488
     */
    MCAPI static class HashedString const & getIdentifier();
    /**
     * @symbol ?registerVersionUpgrades@FoodItemComponent@@SAXAEAVCerealSchemaUpgradeSet@@@Z
     * @hash   -544120128
     */
    MCAPI static void registerVersionUpgrades(class CerealSchemaUpgradeSet &);

};