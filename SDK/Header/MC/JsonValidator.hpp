// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class JsonValidator {

#define AFTER_EXTRA
// Add Member There
public:
class Property {
public:
    Property() = delete;
    Property(Property const&) = delete;
    Property(Property const&&) = delete;
};

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_JSONVALIDATOR
public:
    class JsonValidator& operator=(class JsonValidator const &) = delete;
    JsonValidator(class JsonValidator const &) = delete;
    JsonValidator() = delete;
#endif

public:
    MCAPI static bool validate(class JsonValidator::Property const &, class Json::Value const &, std::vector<std::string> *);

protected:

private:

};