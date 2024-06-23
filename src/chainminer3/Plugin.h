#pragma once
#include "ll/api/chrono/GameChrono.h"
#include "ll/api/event/Event.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/ListenerBase.h"
#include "ll/api/event/player/PlayerDestroyBlockEvent.h"
#include "ll/api/schedule/Scheduler.h"
#include "ll/api/schedule/Task.h"
#include "ll/api/service/Bedrock.h"
#include "mc/nbt/CompoundTag.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/BlockSource.h"
#include "mc/world/level/Level.h"
#include "mc/world/level/block/ActorBlock.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/level/block/actor/BlockActor.h"
#include "mc/world/level/dimension/Dimension.h"
#include "mc/world/level/material/Material.h"


namespace chainminer3::plugin {

// core functions
void registerEventListener();
void removeEventListener();

void addSchedulderTask(Player* player, Block const* block, BlockPos const blockPos);

void miner2(int task_id, const BlockPos start_pos);


// tools functions
int randomInt();

std::string getBlockDimAndPos(ll::event::PlayerDestroyBlockEvent& e);

int toolDamage(ItemStack& tool, int count);

int countTaskList();

int countChainingBlocks();

} // namespace chainminer3::plugin