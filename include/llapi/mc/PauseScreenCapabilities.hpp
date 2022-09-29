/**
 * @file  PauseScreenCapabilities.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC structure PauseScreenCapabilities.
 *
 */
struct PauseScreenCapabilities {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PAUSESCREENCAPABILITIES
public:
    struct PauseScreenCapabilities& operator=(struct PauseScreenCapabilities const &) = delete;
    PauseScreenCapabilities(struct PauseScreenCapabilities const &) = delete;
    PauseScreenCapabilities() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol __unk_destructor_0
     */
    virtual ~PauseScreenCapabilities();
    /**
     * @hash   -409154335
     * @vftbl  1
     * @symbol ?isOfType@?$TypedScreenCapabilities@UPauseScreenCapabilities@@@@UEBA_NV?$typeid_t@VIScreenCapabilities@@@@@Z
     */
    virtual bool isOfType(class typeid_t<class IScreenCapabilities>) const;

};