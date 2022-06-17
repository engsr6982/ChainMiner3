// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class EventResponse {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EVENTRESPONSE
public:
    class EventResponse& operator=(class EventResponse const &) = delete;
    EventResponse(class EventResponse const &) = delete;
    EventResponse() = delete;
#endif


public:
    /*0*/ virtual ~EventResponse();
    /*1*/ virtual std::string const & getName() const;
    /*2*/ virtual void __unk_vfn_2() = 0;
    /*3*/ virtual void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct EventResponseCollection>> &, class Factory<class EventResponse> const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_EVENTRESPONSE
#endif



};