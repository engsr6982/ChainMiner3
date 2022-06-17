// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "OceanMonumentPiece.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MonumentBuilding : public OceanMonumentPiece {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MONUMENTBUILDING
public:
    class MonumentBuilding& operator=(class MonumentBuilding const &) = delete;
    MonumentBuilding(class MonumentBuilding const &) = delete;
    MonumentBuilding() = delete;
#endif


public:
    /*0*/ virtual ~MonumentBuilding();
    /*2*/ virtual enum StructurePieceType getType() const;
    /*4*/ virtual bool postProcess(class BlockSource &, class Random &, class BoundingBox const &);
    /*5*/ virtual void postProcessMobsAt(class BlockSource &, class Random &, class BoundingBox const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MONUMENTBUILDING
#endif
    MCAPI MonumentBuilding(class Random &, short, int, int, int &);

//private:
    MCAPI void generateEntranceArchs(class BlockSource &, class Random &, class BoundingBox const &);
    MCAPI void generateEntranceWall(class BlockSource &, class Random &, class BoundingBox const &);
    MCAPI void generateLowerWall(class BlockSource &, class Random &, class BoundingBox const &);
    MCAPI void generateMiddleWall(class BlockSource &, class Random &, class BoundingBox const &);
    MCAPI void generateRoofPiece(class BlockSource &, class Random &, class BoundingBox const &);
    MCAPI std::vector<class std::shared_ptr<class RoomDefinition>> generateRoomGraph(class Random &);
    MCAPI void generateUpperWall(class BlockSource &, class Random &, class BoundingBox const &);
    MCAPI void generateWing(bool, int, class BlockSource &, class Random &, class BoundingBox const &);


private:


};