// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ItemActor : public Actor {

#define AFTER_EXTRA
// Add Member There
public:
    LIAPI ItemStack* getItemStack();
    LIAPI int getDespawnTime();
    LIAPI bool setDespawnTime(int);
    LIAPI int getLatestSpawnTime();
#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMACTOR
public:
    class ItemActor& operator=(class ItemActor const &) = delete;
    ItemActor(class ItemActor const &) = delete;
    ItemActor() = delete;
#endif


public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~ItemActor();
    /*20*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*39*/ virtual bool isFireImmune() const;
    /*40*/ virtual void __unk_vfn_40();
    /*47*/ virtual std::unique_ptr<class AddActorBasePacket> tryCreateAddActorPacket();
    /*48*/ virtual void normalTick();
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*81*/ virtual void __unk_vfn_81();
    /*87*/ virtual void __unk_vfn_87();
    /*88*/ virtual void playerTouch(class Player &);
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*141*/ virtual void handleEntityEvent(enum ActorEvent, int);
    /*171*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*175*/ virtual class AABB getLiquidAABB(enum MaterialType) const;
    /*181*/ virtual void __unk_vfn_181();
    /*195*/ virtual void __unk_vfn_195();
    /*198*/ virtual bool canSynchronizeNewEntity() const;
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*267*/ virtual void __unk_vfn_267();
    /*268*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*271*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*272*/ virtual void addAdditionalSaveData(class CompoundTag &) const;
    /*275*/ virtual void __unk_vfn_275();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMACTOR
    MCVAPI bool canMakeStepSound() const;
#endif
    MCAPI ItemActor(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI void postNormalTick();
    MCAPI void setSourceEntity(class Actor const *);
    MCAPI static class ItemActor * tryGetFromEntity(class EntityContext &, bool);

//private:
    MCAPI void _addComponents();
    MCAPI void _dropContents();
    MCAPI bool _merge(class ItemActor *);
    MCAPI void _validateItem();


private:
    MCAPI static int const LIFETIME;


};