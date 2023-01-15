/**
 * @file  ItemStackRequestActionDrop.hpp
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
 * @brief MC class ItemStackRequestActionDrop.
 *
 */
class ItemStackRequestActionDrop {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMSTACKREQUESTACTIONDROP
public:
    class ItemStackRequestActionDrop& operator=(class ItemStackRequestActionDrop const &) = delete;
    ItemStackRequestActionDrop(class ItemStackRequestActionDrop const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1199759927
     */
    virtual ~ItemStackRequestActionDrop();
    /**
     * @vftbl  1
     * @hash   -1316591615
     */
    virtual void __unk_vfn_1();
    /**
     * @vftbl  2
     * @hash   -2019447582
     */
    virtual void __unk_vfn_2();
    /**
     * @vftbl  3
     * @hash   -1274290317
     */
    virtual void __unk_vfn_3();
    /**
     * @vftbl  4
     * @symbol ?_write@ItemStackRequestActionDrop@@MEBAXAEAVBinaryStream@@@Z
     * @hash   -544397295
     */
    virtual void _write(class BinaryStream &) const;
    /**
     * @vftbl  5
     * @symbol ?_read@ItemStackRequestActionDrop@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
     * @hash   464867209
     */
    virtual bool _read(class ReadOnlyBinaryStream &);
    /**
     * @symbol ??0ItemStackRequestActionDrop@@QEAA@XZ
     * @hash   -1435312149
     */
    MCAPI ItemStackRequestActionDrop();
    /**
     * @symbol ?getRandomly@ItemStackRequestActionDrop@@QEBA_NXZ
     * @hash   612895934
     */
    MCAPI bool getRandomly() const;

};