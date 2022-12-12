/**
 * @file  Description.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC structure Description.
 *
 */
struct Description {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DESCRIPTION
public:
    struct Description& operator=(struct Description const &) = delete;
    Description(struct Description const &) = delete;
    Description() = delete;
#endif

public:
    /**
     * @hash   -456647117
     * @vftbl  0
     * @symbol ?getJsonName@TrustDescription@@UEBAPEBDXZ
     */
    virtual char const * getJsonName() const = 0;
    /**
     * @vftbl  1
     * @symbol __unk_destructor_1
     */
    virtual ~Description();
    /**
     * @hash   -1261970005
     * @vftbl  2
     * @symbol ?deserializeData@Description@@UEAAXUDeserializeDataParams@@@Z
     */
    virtual void deserializeData(struct DeserializeDataParams);
    /**
     * @hash   -384235040
     * @vftbl  3
     * @symbol ?serializeData@TrustDescription@@UEBAXAEAVValue@Json@@@Z
     */
    virtual void serializeData(class Json::Value &) const = 0;
    /**
     * @hash   -368024937
     * @symbol ?parseDescription@Description@@QEAAPEAU1@UDeserializeDataParams@@@Z
     */
    MCAPI struct Description * parseDescription(struct DeserializeDataParams);

};