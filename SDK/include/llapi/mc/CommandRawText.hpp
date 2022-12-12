/**
 * @file  CommandRawText.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class CommandRawText.
 *
 */
class CommandRawText {

#define AFTER_EXTRA
// Add Member There
    std::string text;

public:
inline operator std::string()const
{
    return text;
}
#define DISABLE_CONSTRUCTOR_PREVENTION_COMMANDRAWTEXT
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMMANDRAWTEXT
public:
    class CommandRawText& operator=(class CommandRawText const &) = delete;
    CommandRawText(class CommandRawText const &) = delete;
    CommandRawText() = delete;
#endif

public:
    /**
     * @hash   566110524
     * @symbol ?getText@CommandRawText@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     */
    MCAPI std::string const & getText() const;

};