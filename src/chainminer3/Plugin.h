#pragma once
#include "mc/nbt/CompoundTag.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/level/block/actor/BlockActor.h"


namespace chainminer3::plugin {


// init
void initEventOnPlayerDestroy();

void initEventOnBlockChanged();

// miner
void miner1(int id, BlockPos* pos, bool sub = false);
void miner2(int task_id, const BlockPos* start_pos);

// funcs
// std::string getBlockDimAndPos(int dimid, BlockPos& pos);


short getEnchantLevel(const std::unique_ptr<CompoundTag>& nbt, short id);

int getDamageFromNbt(const std::unique_ptr<CompoundTag>& nbt);

int toolDamage(ItemStack& tool, int count);

int countTaskList();

// int countPos2Id();

int countChainingBlocks();


} // namespace chainminer3::plugin