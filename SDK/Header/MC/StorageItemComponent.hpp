// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class StorageItemComponent {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STORAGEITEMCOMPONENT
public:
    class StorageItemComponent& operator=(class StorageItemComponent const &) = delete;
    StorageItemComponent(class StorageItemComponent const &) = delete;
    StorageItemComponent() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STORAGEITEMCOMPONENT
#endif
    MCAPI StorageItemComponent(class ComponentItem *);
    MCAPI unsigned int calculateAddableCount(class ItemStack const &, class ItemStackBase const &) const;
    MCAPI bool tryAddItemStack(class ItemStack &, class ItemStack &) const;
    MCAPI void tryGenerateUserData(class ItemStack &) const;
    MCAPI class ItemStack tryRemoveItemStack(class ItemStack &) const;
    MCAPI class ItemStack tryRemoveOneFromItemStack(class ItemStack &) const;
    MCAPI bool use(class ItemStack &, class Player &) const;
    MCAPI static unsigned int const DEFAULT_MAX_CARRY_WEIGHT;
    MCAPI static void bindType();
    MCAPI static class HashedString const & getIdentifier();

//private:
    MCAPI unsigned int _calculateAddableCountForBasicStorage(class ItemStack const &, class ItemStackBase const &) const;
    MCAPI unsigned int _calculateAddableCountForBundleStorage(class ItemStack const &, class ItemStackBase const &) const;
    MCAPI unsigned int _getItemListSize(class ItemStack &) const;
    MCAPI unsigned int _getPerItemCost(class ItemStack const &, class ItemStackBase const &) const;
    MCAPI void _storeItemInNewOrExistingSlot(class ItemStack &, class ItemStack &, unsigned int) const;
    MCAPI void _updateRemainingWeight(class ItemStack &, class ItemStack const &, int) const;


private:


};