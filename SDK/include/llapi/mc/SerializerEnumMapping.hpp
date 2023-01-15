/**
 * @file  SerializerEnumMapping.hpp
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
 * @brief MC class SerializerEnumMapping.
 *
 */
class SerializerEnumMapping {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SERIALIZERENUMMAPPING
public:
    class SerializerEnumMapping& operator=(class SerializerEnumMapping const &) = delete;
    SerializerEnumMapping(class SerializerEnumMapping const &) = delete;
    SerializerEnumMapping() = delete;
#endif

public:
    /**
     * @symbol ?lookup@SerializerEnumMapping@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEA_J@Z
     * @hash   1552660884
     */
    MCAPI bool lookup(std::string const &, __int64 &) const;
    /**
     * @symbol ?lookup@SerializerEnumMapping@@QEBA_N_JAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   656799881
     */
    MCAPI bool lookup(__int64, std::string &) const;
    /**
     * @symbol ??4SerializerEnumMapping@@QEAAAEAV0@$$QEAV0@@Z
     * @hash   -667767558
     */
    MCAPI class SerializerEnumMapping & operator=(class SerializerEnumMapping &&);
    /**
     * @symbol ?toString@SerializerEnumMapping@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -226280344
     */
    MCAPI std::string toString() const;

};