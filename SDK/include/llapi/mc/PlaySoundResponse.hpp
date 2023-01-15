/**
 * @file  PlaySoundResponse.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class PlaySoundResponse.
 *
 */
class PlaySoundResponse {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYSOUNDRESPONSE
public:
    class PlaySoundResponse& operator=(class PlaySoundResponse const &) = delete;
    PlaySoundResponse(class PlaySoundResponse const &) = delete;
    PlaySoundResponse() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -314528406
     */
    virtual ~PlaySoundResponse();
    /**
     * @vftbl  1
     * @symbol ?getName@PlaySoundResponse@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   979298781
     */
    virtual std::string const & getName() const;
    /**
     * @vftbl  2
     * @symbol ?executeAction@PlaySoundResponse@@UEBAXAEAVRenderParams@@@Z
     * @hash   916385201
     */
    virtual void executeAction(class RenderParams &) const;
    /**
     * @vftbl  3
     * @symbol ?buildSchema@PlaySoundResponse@@UEBAXAEAV?$shared_ptr@V?$JsonSchemaObjectNode@VEmptyClass@JsonUtil@@UEventResponseCollection@@@JsonUtil@@@std@@AEBV?$Factory@VEventResponse@@$$V@@@Z
     * @hash   1496735643
     */
    virtual void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct EventResponseCollection>> &, class Factory<class EventResponse> const &) const;
    /**
     * @symbol ?NameID@PlaySoundResponse@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   -653871619
     */
    MCAPI static std::string const NameID;

};