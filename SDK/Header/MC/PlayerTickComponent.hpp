// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct PlayerTickComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYERTICKCOMPONENT
public:
    struct PlayerTickComponent& operator=(struct PlayerTickComponent const &) = delete;
    PlayerTickComponent(struct PlayerTickComponent const &) = delete;
    PlayerTickComponent() = delete;
#endif

public:
    MCAPI PlayerTickComponent(struct PlayerTickComponent &&);
    MCAPI PlayerTickComponent(std::unique_ptr<struct IPlayerTickPolicy>);
    MCAPI struct PlayerTickComponent & operator=(struct PlayerTickComponent &&);
    MCAPI ~PlayerTickComponent();

protected:

private:

};