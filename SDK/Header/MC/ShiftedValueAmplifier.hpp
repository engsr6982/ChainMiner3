// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ShiftedValueAmplifier {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SHIFTEDVALUEAMPLIFIER
public:
    class ShiftedValueAmplifier& operator=(class ShiftedValueAmplifier const &) = delete;
    ShiftedValueAmplifier(class ShiftedValueAmplifier const &) = delete;
    ShiftedValueAmplifier() = delete;
#endif


public:
    /*0*/ virtual ~ShiftedValueAmplifier();
    /*1*/ virtual float getAmount(int, float) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SHIFTEDVALUEAMPLIFIER
#endif
    MCAPI ShiftedValueAmplifier(int, float);



};