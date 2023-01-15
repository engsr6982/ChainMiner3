/**
 * @file  RemoveActorPacket.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class RemoveActorPacket.
 *
 */
class RemoveActorPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_REMOVEACTORPACKET
public:
    class RemoveActorPacket& operator=(class RemoveActorPacket const &) = delete;
    RemoveActorPacket(class RemoveActorPacket const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1773410553
     */
    virtual ~RemoveActorPacket();
    /**
     * @vftbl  1
     * @symbol ?getId@RemoveActorPacket@@UEBA?AW4MinecraftPacketIds@@XZ
     * @hash   -1060967067
     */
    virtual enum class MinecraftPacketIds getId() const;
    /**
     * @vftbl  2
     * @symbol ?getName@RemoveActorPacket@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -1797896174
     */
    virtual std::string getName() const;
    /**
     * @vftbl  3
     * @symbol ?write@RemoveActorPacket@@UEBAXAEAVBinaryStream@@@Z
     * @hash   -1636926315
     */
    virtual void write(class BinaryStream &) const;
    /**
     * @vftbl  6
     * @symbol ?_read@RemoveActorPacket@@EEAA?AW4StreamReadResult@@AEAVReadOnlyBinaryStream@@@Z
     * @hash   -1839426731
     */
    virtual enum class StreamReadResult _read(class ReadOnlyBinaryStream &);
    /**
     * @symbol ??0RemoveActorPacket@@QEAA@XZ
     * @hash   1729230309
     */
    MCAPI RemoveActorPacket();
    /**
     * @symbol ??0RemoveActorPacket@@QEAA@UActorUniqueID@@@Z
     * @hash   1771606722
     */
    MCAPI RemoveActorPacket(struct ActorUniqueID);

};