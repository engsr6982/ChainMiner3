// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class StrongholdPiece {

#define AFTER_EXTRA
// Add Member There
public:
enum SmallDoorType;

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STRONGHOLDPIECE
public:
    class StrongholdPiece& operator=(class StrongholdPiece const &) = delete;
    StrongholdPiece(class StrongholdPiece const &) = delete;
    StrongholdPiece() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STRONGHOLDPIECE
    MCVAPI ~StrongholdPiece();
#endif
    MCAPI std::unique_ptr<class StructurePiece> findAndCreatePieceFactory(std::string const &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, int, int, int, int, int);
    MCAPI class StructurePiece * generateAndAddPiece(class SHStartPiece &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, int, int, int, int, int);
    MCAPI std::unique_ptr<class StructurePiece> generatePieceFromSmallDoor(class SHStartPiece &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random const &, int, int, int, int, int);
    MCAPI void generateSmallDoor(class BlockSource &, class Random &, class BoundingBox const &, enum StrongholdPiece::SmallDoorType, int, int, int);
    MCAPI class StructurePiece * generateSmallDoorChildForward(class SHStartPiece &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, int, int);
    MCAPI class StructurePiece * generateSmallDoorChildLeft(class SHStartPiece &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, int, int);
    MCAPI class StructurePiece * generateSmallDoorChildRight(class SHStartPiece &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, int, int);



};