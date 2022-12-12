/**
 * @file  ActorOnLadderTest.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "FilterTest.hpp"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class ActorOnLadderTest.
 *
 */
class ActorOnLadderTest : public FilterTest {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORONLADDERTEST
public:
    class ActorOnLadderTest& operator=(class ActorOnLadderTest const &) = delete;
    ActorOnLadderTest(class ActorOnLadderTest const &) = delete;
    ActorOnLadderTest() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol __unk_destructor_0
     */
    virtual ~ActorOnLadderTest();
    /**
     * @hash   675193386
     * @vftbl  2
     * @symbol ?evaluate@ActorOnLadderTest@@UEBA_NAEBUFilterContext@@@Z
     */
    virtual bool evaluate(struct FilterContext const &) const;
    /**
     * @hash   -1122234040
     * @vftbl  4
     * @symbol ?getName@ActorOnLadderTest@@UEBA?AV?$basic_string_span@$$CBD$0?0@gsl@@XZ
     */
    virtual class gsl::basic_string_span<char const, -1> getName() const;

};