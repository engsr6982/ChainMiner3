#include "plugin/MyPlugin.h"

#include <memory>

#include "ll/api/mod/RegisterHelper.h"

// ChainMiner3
#include "chainminer3/Command.h"
#include "chainminer3/Config.h"
#include "chainminer3/Economic.h"
#include "chainminer3/PlayerSetting.h"
#include "chainminer3/Plugin.h"


namespace my_plugin {

static std::unique_ptr<MyPlugin> instance;

MyPlugin& MyPlugin::getInstance() { return *instance; }

bool MyPlugin::load() {
    getSelf().getLogger().info("Loading...");
    // Code for loading the plugin goes here.

    chainminer3::config::initConfig();

    return true;
}

bool MyPlugin::enable() {
    getSelf().getLogger().info("Enabling...");
    // Code for enabling the plugin goes here.

    chainminer3::command::registerCommand();
    chainminer3::plugin::registerEventListener();

    return true;
}

bool MyPlugin::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the plugin goes here.

    chainminer3::plugin::removeEventListener();

    return true;
}

} // namespace my_plugin

LL_REGISTER_MOD(my_plugin::MyPlugin, my_plugin::instance);
