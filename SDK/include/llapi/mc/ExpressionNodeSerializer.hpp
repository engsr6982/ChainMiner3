/**
 * @file  ExpressionNodeSerializer.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC namespace ExpressionNodeSerializer.
 *
 */
namespace ExpressionNodeSerializer {

#define AFTER_EXTRA

#undef AFTER_EXTRA
    /**
     * @symbol ?fromFloat@ExpressionNodeSerializer@@YAXAEAVExpressionNode@@M@Z
     * @hash   1776569208
     */
    MCAPI void fromFloat(class ExpressionNode &, float);
    /**
     * @symbol ?fromProxy@ExpressionNodeSerializer@@YAXAEAVExpressionNode@@UExpressionNodeProxy@1@@Z
     * @hash   821807269
     */
    MCAPI void fromProxy(class ExpressionNode &, struct ExpressionNodeSerializer::ExpressionNodeProxy);
    /**
     * @symbol ?fromString@ExpressionNodeSerializer@@YAXAEAVExpressionNode@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBedrockLoadContext@@@Z
     * @hash   -1371353521
     */
    MCAPI void fromString(class ExpressionNode &, std::string const &, class BedrockLoadContext const &);
    /**
     * @symbol ?toProxy@ExpressionNodeSerializer@@YA?AUExpressionNodeProxy@1@AEBVExpressionNode@@@Z
     * @hash   -891490321
     */
    MCAPI struct ExpressionNodeSerializer::ExpressionNodeProxy toProxy(class ExpressionNode const &);

};