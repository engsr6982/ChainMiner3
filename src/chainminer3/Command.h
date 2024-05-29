#include <mc/world/actor/player/Player.h>


namespace chainminer3::command {

void sendPlayerMenu(Player& pl);
void sendBasicSettingMenu(Player& pl);
void sendBlockSwitchMenu(Player& pl, int page = -1);
void registerCommand();


} // namespace chainminer3::command