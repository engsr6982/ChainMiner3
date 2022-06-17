// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ShapedRecipe.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ShapedChemistryRecipe : public ShapedRecipe {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SHAPEDCHEMISTRYRECIPE
public:
    class ShapedChemistryRecipe& operator=(class ShapedChemistryRecipe const &) = delete;
    ShapedChemistryRecipe(class ShapedChemistryRecipe const &) = delete;
    ShapedChemistryRecipe() = delete;
#endif


public:
    /*0*/ virtual ~ShapedChemistryRecipe();
    /*6*/ virtual bool matches(class CraftingContainer &, class Level &) const;
    /*8*/ virtual class mce::UUID const & getId() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SHAPEDCHEMISTRYRECIPE
#endif
    MCAPI static class mce::UUID const ID;



};