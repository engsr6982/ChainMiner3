// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct GeneDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GENEDEFINITION
public:
    struct GeneDefinition& operator=(struct GeneDefinition const &) = delete;
    GeneDefinition(struct GeneDefinition const &) = delete;
    GeneDefinition() = delete;
#endif

public:
    MCAPI void addGeneticVariant(struct GeneticVariant const &);
    MCAPI ~GeneDefinition();

protected:

private:

};