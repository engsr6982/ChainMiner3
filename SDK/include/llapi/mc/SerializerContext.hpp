/**
 * @file  SerializerContext.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "reflection.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class SerializerContext.
 *
 */
class SerializerContext {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SERIALIZERCONTEXT
public:
    class SerializerContext& operator=(class SerializerContext const &) = delete;
    SerializerContext(class SerializerContext const &) = delete;
#endif

public:
    /**
     * @symbol ??0SerializerContext@@QEAA@XZ
     * @hash   -873711959
     */
    MCAPI SerializerContext();
    /**
     * @symbol ?clear@SerializerContext@@QEAAXXZ
     * @hash   533079583
     */
    MCAPI void clear();
    /**
     * @symbol ?consumeContext@SerializerContext@@QEAAX$$QEAV1@@Z
     * @hash   -1902841592
     */
    MCAPI void consumeContext(class SerializerContext &&);
    /**
     * @symbol ?detachContext@SerializerContext@@QEAA?AV1@XZ
     * @hash   731583598
     */
    MCAPI class SerializerContext detachContext();
    /**
     * @symbol ?getErrors@SerializerContext@@QEBA?AV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@XZ
     * @hash   -264303573
     */
    MCAPI std::vector<std::string> getErrors() const;
    /**
     * @symbol ?log@SerializerContext@@QEAA?AW4ResultCode@details@reflection@@W4234@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   -889406402
     */
    MCAPI enum class reflection::details::ResultCode log(enum class reflection::details::ResultCode, std::string);
    /**
     * @symbol ??4SerializerContext@@QEAAAEAV0@$$QEAV0@@Z
     * @hash   -670811410
     */
    MCAPI class SerializerContext & operator=(class SerializerContext &&);
    /**
     * @symbol ?popContext@SerializerContext@@QEAAXXZ
     * @hash   1005644351
     */
    MCAPI void popContext();
    /**
     * @symbol ?pushContext@SerializerContext@@QEAAAEAV1@U?$pair@W4ContextType@SerializerContext@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@Z
     * @hash   1892281332
     */
    MCAPI class SerializerContext & pushContext(struct std::pair<enum class SerializerContext::ContextType, std::string>);
    /**
     * @symbol ??1SerializerContext@@QEAA@XZ
     * @hash   1523826601
     */
    MCAPI ~SerializerContext();
    /**
     * @symbol ?contextString@SerializerContext@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@U?$pair@W4ContextType@SerializerContext@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$allocator@U?$pair@W4ContextType@SerializerContext@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@@3@@Z
     * @hash   1039320924
     */
    MCAPI static std::string contextString(std::vector<struct std::pair<enum class SerializerContext::ContextType, std::string>> const &);

};