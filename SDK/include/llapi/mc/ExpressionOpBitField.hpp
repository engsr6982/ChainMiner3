/**
 * @file  ExpressionOpBitField.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC structure ExpressionOpBitField.
 *
 */
struct ExpressionOpBitField {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EXPRESSIONOPBITFIELD
public:
    struct ExpressionOpBitField& operator=(struct ExpressionOpBitField const &) = delete;
    ExpressionOpBitField(struct ExpressionOpBitField const &) = delete;
    ExpressionOpBitField() = delete;
#endif

public:
    /**
     * @symbol ?areBitsSet@ExpressionOpBitField@@QEBA_NW4ExpressionOp@@0000000@Z
     * @hash   -913411054
     */
    MCAPI bool areBitsSet(enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp) const;
    /**
     * @symbol ?areBitsSet@ExpressionOpBitField@@QEBA_NW4ExpressionOp@@00000@Z
     * @hash   1340644402
     */
    MCAPI bool areBitsSet(enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp) const;
    /**
     * @symbol ?areBitsSet@ExpressionOpBitField@@QEBA_NW4ExpressionOp@@0000@Z
     * @hash   594140827
     */
    MCAPI bool areBitsSet(enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp) const;
    /**
     * @symbol ?areBitsSet@ExpressionOpBitField@@QEBA_NW4ExpressionOp@@000@Z
     * @hash   16062690
     */
    MCAPI bool areBitsSet(enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp) const;
    /**
     * @symbol ?areBitsSet@ExpressionOpBitField@@QEBA_NW4ExpressionOp@@00@Z
     * @hash   -1249348293
     */
    MCAPI bool areBitsSet(enum class ExpressionOp, enum class ExpressionOp, enum class ExpressionOp) const;

};