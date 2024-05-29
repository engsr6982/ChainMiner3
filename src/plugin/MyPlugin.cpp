#include "plugin/MyPlugin.h"

#include <memory>

#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"

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
    chainminer3::plugin::initEventOnPlayerDestroy();

    return true;
}

bool MyPlugin::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the plugin goes here.

    chainminer3::plugin::removeListener();

    return true;
}

} // namespace my_plugin

LL_REGISTER_PLUGIN(my_plugin::MyPlugin, my_plugin::instance);
