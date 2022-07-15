// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Add include headers & pre-declares
class Block;
class Container;
class CompoundTag;
class BlockSource;

#undef BEFORE_EXTRA

class BlockActor {

#define AFTER_EXTRA
// Add new members to class
public:
    
    LIAPI bool refreshData();
    LIAPI bool refreshData(BlockSource* bs);
    LIAPI std::unique_ptr<CompoundTag> getNbt();
    LIAPI bool setNbt(CompoundTag* nbt);
    LIAPI bool setNbt(CompoundTag* nbt, BlockSource* bs);
    static unsigned int getBlockEntityType(Block* block);

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKACTOR
public:
    class BlockActor& operator=(class BlockActor const &) = delete;
    BlockActor(class BlockActor const &) = delete;
    BlockActor() = delete;
#endif


public:
    /*0*/ virtual ~BlockActor();
    /*1*/ virtual void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /*2*/ virtual bool save(class CompoundTag &) const;
    /*3*/ virtual bool saveItemInstanceData(class CompoundTag &);
    /*4*/ virtual void saveBlockData(class CompoundTag &, class BlockSource &) const;
    /*5*/ virtual void loadBlockData(class CompoundTag const &, class BlockSource &, class DataLoadHelper &);
    /*6*/ virtual void onCustomTagLoadDone(class BlockSource &);
    /*7*/ virtual void tick(class BlockSource &);
    /*8*/ virtual void onChanged(class BlockSource &);
    /*9*/ virtual bool isMovable(class BlockSource &);
    /*10*/ virtual bool isCustomNameSaved();
    /*11*/ virtual void onPlace(class BlockSource &);
    /*12*/ virtual void __unk_vfn_12();
    /*13*/ virtual void onRemoved(class BlockSource &);
    /*14*/ virtual void triggerEvent(int, int);
    /*15*/ virtual void clearCache();
    /*16*/ virtual void __unk_vfn_16();
    /*17*/ virtual float getShadowRadius(class BlockSource &) const;
    /*18*/ virtual bool hasAlphaLayer() const;
    /*19*/ virtual class BlockActor * getCrackEntity(class BlockSource &, class BlockPos const &);
    /*20*/ virtual void getDebugText(std::vector<std::string> &, class BlockPos const &);
    /*21*/ virtual std::string const & getCustomName() const;
    /*22*/ virtual std::string const & getFilteredCustomName(class UIProfanityContext const &);
    /*23*/ virtual std::string getName() const;
    /*24*/ virtual void setCustomName(std::string const &);
    /*25*/ virtual std::string getImmersiveReaderText(class BlockSource &);
    /*26*/ virtual int getRepairCost() const;
    /*27*/ virtual class PistonBlockActor * getOwningPiston(class BlockSource &);
    /*28*/ virtual void __unk_vfn_28();
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*31*/ virtual float getDeletionDelayTimeSeconds() const;
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual void __unk_vfn_34();
    /*35*/ virtual std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource &);
    /*36*/ virtual void _onUpdatePacket(class CompoundTag const &, class BlockSource &);
    /*37*/ virtual bool _playerCanUpdate(class Player const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKACTOR
    MCVAPI void eraseLootTable();
    MCVAPI void fixupOnLoad(class LevelChunk &);
    MCVAPI class Container * getContainer();
    MCVAPI class Container const * getContainer() const;
    MCVAPI void onChunkLoaded(class LevelChunk &);
    MCVAPI void onChunkUnloaded(class LevelChunk &);
    MCVAPI void onMove();
    MCVAPI void onNeighborChanged(class BlockSource &, class BlockPos const &);
#endif
    MCAPI BlockActor(enum BlockActorType, class BlockPos const &, std::string const &);
    MCAPI void assignBlockIfNotAssigned(class BlockSource &);
    MCAPI class AABB const & getAABB() const;
    MCAPI class Block const * getBlock() const;
    MCAPI class BlockPos const & getPosition() const;
    MCAPI std::unique_ptr<class BlockActorDataPacket> getServerUpdatePacket(class BlockSource &);
    MCAPI enum BlockActorType const & getType() const;
    MCAPI bool const ignoreLighting() const;
    MCAPI bool isType(enum BlockActorType) const;
    MCAPI void moveTo(class BlockPos const &);
    MCAPI bool onUpdatePacket(class CompoundTag const &, class BlockSource &, class Player const *);
    MCAPI void setBB(class AABB);
    MCAPI void setChanged();
    MCAPI void setCustomNameSaved(bool);
    MCAPI void setIgnoreLighting(bool);
    MCAPI void setMovable(bool);
    MCAPI static bool isType(class BlockActor &, enum BlockActorType);
    MCAPI static class std::shared_ptr<class BlockActor> loadStatic(class Level &, class CompoundTag const &, class DataLoadHelper &);

//protected:
    MCAPI void _resetAABB();

//private:
    MCAPI static class std::map<std::string, enum BlockActorType, struct std::less<std::string>, class std::allocator<struct std::pair<std::string const, enum BlockActorType>>> _createIdClassMap();


protected:

private:
    MCAPI static class std::map<enum BlockActorType, std::string, struct std::less<enum BlockActorType>, class std::allocator<struct std::pair<enum BlockActorType const, std::string>>> const mClassIdMap;
    MCAPI static class std::map<std::string, enum BlockActorType, struct std::less<std::string>, class std::allocator<struct std::pair<std::string const, enum BlockActorType>>> const mIdClassMap;


};