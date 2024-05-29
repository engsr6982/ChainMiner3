#pragma once
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/level/block/actor/BlockActor.h"


#ifndef CHAINMINER_PLUGIN_H
#define CHAINMINER_PLUGIN_H
// init
void initEventOnPlayerDestroy();

void initEventOnBlockChanged();

void registerCommand();

// miner
void miner1(int id, BlockPos* pos, bool sub = false);
void miner2(int task_id, const BlockPos* start_pos);

// funcs
std::string getBlockDimAndPos(BlockActor& bli);

#include "mc/nbt/CompoundTag.h" //compile needed

short getEnchantLevel(const std::unique_ptr<CompoundTag>& nbt, short id);

int getDamageFromNbt(const std::unique_ptr<CompoundTag>& nbt);

int toolDamage(ItemStack& tool, int count);

int countTaskList();

// int countPos2Id();

int countChainingBlocks();

#endif // CHAINMINER_PLUGIN_H