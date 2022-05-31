// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ChestBlockActor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CHESTBLOCKACTOR
public:
    class ChestBlockActor& operator=(class ChestBlockActor const &) = delete;
    ChestBlockActor(class ChestBlockActor const &) = delete;
    ChestBlockActor() = delete;
#endif

public:
    /*
    inline bool canPushInItem(class BlockSource & a0, int a1, int a2, class ItemInstance const & a3) const{
        bool (ChestBlockActor::*rv)(class BlockSource &, int, int, class ItemInstance const &) const;
        *((void**)&rv) = dlsym("?canPushInItem@ChestBlockActor@@UEBA_NAEAVBlockSource@@HHAEBVItemInstance@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0), std::forward<int>(a1), std::forward<int>(a2), std::forward<class ItemInstance const &>(a3));
    }
    inline bool canPullOutItem(class BlockSource & a0, int a1, int a2, class ItemInstance const & a3) const{
        bool (ChestBlockActor::*rv)(class BlockSource &, int, int, class ItemInstance const &) const;
        *((void**)&rv) = dlsym("?canPullOutItem@ChestBlockActor@@UEBA_NAEAVBlockSource@@HHAEBVItemInstance@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0), std::forward<int>(a1), std::forward<int>(a2), std::forward<class ItemInstance const &>(a3));
    }
    inline void onNeighborChanged(class BlockSource & a0, class BlockPos const & a1){
        void (ChestBlockActor::*rv)(class BlockSource &, class BlockPos const &);
        *((void**)&rv) = dlsym("?onNeighborChanged@ChestBlockActor@@UEAAXAEAVBlockSource@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0), std::forward<class BlockPos const &>(a1));
    }
    inline void setItemWithForceBalance(int a0, class ItemStack const & a1, bool a2){
        void (ChestBlockActor::*rv)(int, class ItemStack const &, bool);
        *((void**)&rv) = dlsym("?setItemWithForceBalance@ChestBlockActor@@UEAAXHAEBVItemStack@@_N@Z");
        return (this->*rv)(std::forward<int>(a0), std::forward<class ItemStack const &>(a1), std::forward<bool>(a2));
    }
    inline int getMaxStackSize() const{
        int (ChestBlockActor::*rv)() const;
        *((void**)&rv) = dlsym("?getMaxStackSize@ChestBlockActor@@UEBAHXZ");
        return (this->*rv)();
    }
    inline  ~ChestBlockActor(){
         (ChestBlockActor::*rv)();
        *((void**)&rv) = dlsym("??1ChestBlockActor@@UEAA@XZ");
        return (this->*rv)();
    }
    inline bool _canOpenThis(class BlockSource & a0) const{
        bool (ChestBlockActor::*rv)(class BlockSource &) const;
        *((void**)&rv) = dlsym("?_canOpenThis@ChestBlockActor@@MEBA_NAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline bool _detectEntityObstruction(class BlockSource & a0) const{
        bool (ChestBlockActor::*rv)(class BlockSource &) const;
        *((void**)&rv) = dlsym("?_detectEntityObstruction@ChestBlockActor@@MEBA_NAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource & a0){
        std::unique_ptr<class BlockActorDataPacket> (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?_getUpdatePacket@ChestBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void _onUpdatePacket(class CompoundTag const & a0, class BlockSource & a1){
        void (ChestBlockActor::*rv)(class CompoundTag const &, class BlockSource &);
        *((void**)&rv) = dlsym("?_onUpdatePacket@ChestBlockActor@@MEAAXAEBVCompoundTag@@AEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class CompoundTag const &>(a0), std::forward<class BlockSource &>(a1));
    }
    inline void addContentChangeListener(class ContainerContentChangeListener * a0){
        void (ChestBlockActor::*rv)(class ContainerContentChangeListener *);
        *((void**)&rv) = dlsym("?addContentChangeListener@ChestBlockActor@@UEAAXPEAVContainerContentChangeListener@@@Z");
        return (this->*rv)(std::forward<class ContainerContentChangeListener *>(a0));
    }
    inline void clearCache(){
        void (ChestBlockActor::*rv)();
        *((void**)&rv) = dlsym("?clearCache@ChestBlockActor@@UEAAXXZ");
        return (this->*rv)();
    }
    inline int clearInventory(int a0){
        int (ChestBlockActor::*rv)(int);
        *((void**)&rv) = dlsym("?clearInventory@ChestBlockActor@@UEAAHH@Z");
        return (this->*rv)(std::forward<int>(a0));
    }
    inline class Container const * getContainer() const{
        class Container const * (ChestBlockActor::*rv)() const;
        *((void**)&rv) = dlsym("?getContainer@ChestBlockActor@@UEBAPEBVContainer@@XZ");
        return (this->*rv)();
    }
    inline class Container * getContainer(){
        class Container * (ChestBlockActor::*rv)();
        *((void**)&rv) = dlsym("?getContainer@ChestBlockActor@@UEAAPEAVContainer@@XZ");
        return (this->*rv)();
    }
    inline int getContainerSize() const{
        int (ChestBlockActor::*rv)() const;
        *((void**)&rv) = dlsym("?getContainerSize@ChestBlockActor@@UEBAHXZ");
        return (this->*rv)();
    }
    inline class BlockActor * getCrackEntity(class BlockSource & a0, class BlockPos const & a1){
        class BlockActor * (ChestBlockActor::*rv)(class BlockSource &, class BlockPos const &);
        *((void**)&rv) = dlsym("?getCrackEntity@ChestBlockActor@@UEAAPEAVBlockActor@@AEAVBlockSource@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0), std::forward<class BlockPos const &>(a1));
    }
    inline void getDebugText(std::vector<std::string> & a0, class BlockPos const & a1){
        void (ChestBlockActor::*rv)(std::vector<std::string> &, class BlockPos const &);
        *((void**)&rv) = dlsym("?getDebugText@ChestBlockActor@@UEAAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<std::vector<std::string> &>(a0), std::forward<class BlockPos const &>(a1));
    }
    inline class ItemStack const & getItem(int a0) const{
        class ItemStack const & (ChestBlockActor::*rv)(int) const;
        *((void**)&rv) = dlsym("?getItem@ChestBlockActor@@UEBAAEBVItemStack@@H@Z");
        return (this->*rv)(std::forward<int>(a0));
    }
    inline std::string getName() const{
        std::string (ChestBlockActor::*rv)() const;
        *((void**)&rv) = dlsym("?getName@ChestBlockActor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ");
        return (this->*rv)();
    }
    inline class AABB getObstructionAABB() const{
        class AABB (ChestBlockActor::*rv)() const;
        *((void**)&rv) = dlsym("?getObstructionAABB@ChestBlockActor@@MEBA?AVAABB@@XZ");
        return (this->*rv)();
    }
    inline void initializeContainerContents(class BlockSource & a0){
        void (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?initializeContainerContents@ChestBlockActor@@UEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void load(class Level & a0, class CompoundTag const & a1, class DataLoadHelper & a2){
        void (ChestBlockActor::*rv)(class Level &, class CompoundTag const &, class DataLoadHelper &);
        *((void**)&rv) = dlsym("?load@ChestBlockActor@@UEAAXAEAVLevel@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z");
        return (this->*rv)(std::forward<class Level &>(a0), std::forward<class CompoundTag const &>(a1), std::forward<class DataLoadHelper &>(a2));
    }
    inline void loadItems(class CompoundTag const & a0, class Level & a1){
        void (ChestBlockActor::*rv)(class CompoundTag const &, class Level &);
        *((void**)&rv) = dlsym("?loadItems@ChestBlockActor@@UEAAXAEBVCompoundTag@@AEAVLevel@@@Z");
        return (this->*rv)(std::forward<class CompoundTag const &>(a0), std::forward<class Level &>(a1));
    }
    inline void onChanged(class BlockSource & a0){
        void (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?onChanged@ChestBlockActor@@UEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void onMove(){
        void (ChestBlockActor::*rv)();
        *((void**)&rv) = dlsym("?onMove@ChestBlockActor@@UEAAXXZ");
        return (this->*rv)();
    }
    inline void onPlace(class BlockSource & a0){
        void (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?onPlace@ChestBlockActor@@UEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void onRemoved(class BlockSource & a0){
        void (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?onRemoved@ChestBlockActor@@UEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void playCloseSound(class BlockSource & a0){
        void (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?playCloseSound@ChestBlockActor@@MEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void playOpenSound(class BlockSource & a0){
        void (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?playOpenSound@ChestBlockActor@@MEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void removeContentChangeListener(class ContainerContentChangeListener * a0){
        void (ChestBlockActor::*rv)(class ContainerContentChangeListener *);
        *((void**)&rv) = dlsym("?removeContentChangeListener@ChestBlockActor@@UEAAXPEAVContainerContentChangeListener@@@Z");
        return (this->*rv)(std::forward<class ContainerContentChangeListener *>(a0));
    }
    inline bool save(class CompoundTag & a0) const{
        bool (ChestBlockActor::*rv)(class CompoundTag &) const;
        *((void**)&rv) = dlsym("?save@ChestBlockActor@@UEBA_NAEAVCompoundTag@@@Z");
        return (this->*rv)(std::forward<class CompoundTag &>(a0));
    }
    inline bool saveItemInstanceData(class CompoundTag & a0){
        bool (ChestBlockActor::*rv)(class CompoundTag &);
        *((void**)&rv) = dlsym("?saveItemInstanceData@ChestBlockActor@@UEAA_NAEAVCompoundTag@@@Z");
        return (this->*rv)(std::forward<class CompoundTag &>(a0));
    }
    inline bool saveItems(class CompoundTag & a0) const{
        bool (ChestBlockActor::*rv)(class CompoundTag &) const;
        *((void**)&rv) = dlsym("?saveItems@ChestBlockActor@@UEBA_NAEAVCompoundTag@@@Z");
        return (this->*rv)(std::forward<class CompoundTag &>(a0));
    }
    inline void serverInitItemStackIds(int a0, int a1, class std::function<void (int, class ItemStack const &)> a2){
        void (ChestBlockActor::*rv)(int, int, class std::function<void (int, class ItemStack const &)>);
        *((void**)&rv) = dlsym("?serverInitItemStackIds@ChestBlockActor@@UEAAXHHV?$function@$$A6AXHAEBVItemStack@@@Z@std@@@Z");
        return (this->*rv)(std::forward<int>(a0), std::forward<int>(a1), std::forward<class std::function<void (int, class ItemStack const &)>>(a2));
    }
    inline void setContainerChanged(int a0){
        void (ChestBlockActor::*rv)(int);
        *((void**)&rv) = dlsym("?setContainerChanged@ChestBlockActor@@UEAAXH@Z");
        return (this->*rv)(std::forward<int>(a0));
    }
    inline void setItem(int a0, class ItemStack const & a1){
        void (ChestBlockActor::*rv)(int, class ItemStack const &);
        *((void**)&rv) = dlsym("?setItem@ChestBlockActor@@UEAAXHAEBVItemStack@@@Z");
        return (this->*rv)(std::forward<int>(a0), std::forward<class ItemStack const &>(a1));
    }
    inline void startOpen(class Player & a0){
        void (ChestBlockActor::*rv)(class Player &);
        *((void**)&rv) = dlsym("?startOpen@ChestBlockActor@@UEAAXAEAVPlayer@@@Z");
        return (this->*rv)(std::forward<class Player &>(a0));
    }
    inline void stopOpen(class Player & a0){
        void (ChestBlockActor::*rv)(class Player &);
        *((void**)&rv) = dlsym("?stopOpen@ChestBlockActor@@UEAAXAEAVPlayer@@@Z");
        return (this->*rv)(std::forward<class Player &>(a0));
    }
    inline void tick(class BlockSource & a0){
        void (ChestBlockActor::*rv)(class BlockSource &);
        *((void**)&rv) = dlsym("?tick@ChestBlockActor@@UEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource &>(a0));
    }
    inline void triggerEvent(int a0, int a1){
        void (ChestBlockActor::*rv)(int, int);
        *((void**)&rv) = dlsym("?triggerEvent@ChestBlockActor@@UEAAXHH@Z");
        return (this->*rv)(std::forward<int>(a0), std::forward<int>(a1));
    }
    */
    MCAPI ChestBlockActor(enum BlockActorType, std::string const &, enum BlockActorRendererId, class BlockPos const &, bool);
    MCAPI bool canOpen(class BlockSource &) const;
    MCAPI bool canPairWith(class BlockActor *, class BlockSource &);
    MCAPI void forceCloseChest(class BlockSource &);
    MCAPI int getOpenCount() const;
    MCAPI float getOpenness() const;
    MCAPI class BlockPos const & getPairedChestPosition();
    MCAPI bool isFindable() const;
    MCAPI bool isLargeChest() const;
    MCAPI void onMove(class BlockSource &, class BlockPos const &, class BlockPos const &);
    MCAPI void openBy(class Player &);
    MCAPI void pairWith(class ChestBlockActor *, bool);
    MCAPI void setFindable(bool);
    MCAPI void unpair(class BlockSource &);

protected:
    MCAPI void _getCenter(float &, float &, float &);

private:
    MCAPI void _closeChest(class BlockSource &, class Player *);
    MCAPI bool _saveClientSideState(class CompoundTag &) const;
    MCAPI void _tryToPairWith(class BlockSource &, class BlockPos const &);
    MCAPI void _unpair();

};