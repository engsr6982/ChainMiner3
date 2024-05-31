#pragma once
#include "mc/nbt/CompoundTag.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/level/block/actor/BlockActor.h"


namespace chainminer3::plugin {


// init
void registerEvent();
void removeListener();

// miner
void miner2(int task_id, const BlockPos* start_pos);


short getEnchantLevel(const std::unique_ptr<CompoundTag>& nbt, short id);

int getDamageFromNbt(const std::unique_ptr<CompoundTag>& nbt);

int toolDamage(ItemStack& tool, int count);

int countTaskList();

int countChainingBlocks();


} // namespace chainminer3::plugin