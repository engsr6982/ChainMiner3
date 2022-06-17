// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class WaterMovementDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WATERMOVEMENTDESCRIPTION
public:
    class WaterMovementDescription& operator=(class WaterMovementDescription const &) = delete;
    WaterMovementDescription(class WaterMovementDescription const &) = delete;
#endif


public:
    /*0*/ virtual char const * getJsonName() const;
    /*1*/ virtual ~WaterMovementDescription();
    /*2*/ virtual void deserializeData(struct DeserializeDataParams);
    /*3*/ virtual void serializeData(class Json::Value &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WATERMOVEMENTDESCRIPTION
#endif
    MCAPI WaterMovementDescription();



};