// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "NetherFortressPiece.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NBBridgeEndFiller : public NetherFortressPiece {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NBBRIDGEENDFILLER
public:
    class NBBridgeEndFiller& operator=(class NBBridgeEndFiller const &) = delete;
    NBBridgeEndFiller(class NBBridgeEndFiller const &) = delete;
    NBBridgeEndFiller() = delete;
#endif


public:
    /*0*/ virtual ~NBBridgeEndFiller();
    /*1*/ virtual void moveBoundingBox(int, int, int);
    /*2*/ virtual enum StructurePieceType getType() const;
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual bool postProcess(class BlockSource &, class Random &, class BoundingBox const &);
    /*5*/ virtual void __unk_vfn_5();
    /*6*/ virtual int getWorldX(int, int);
    /*7*/ virtual int getWorldZ(int, int);
    /*8*/ virtual void placeBlock(class BlockSource &, class Block const &, int, int, int, class BoundingBox const &);
    /*9*/ virtual void __unk_vfn_9();
    /*10*/ virtual void generateBox(class BlockSource &, class BoundingBox const &, int, int, int, int, int, int, class Block const &, class Block const &, bool);
    /*11*/ virtual void addHardcodedSpawnAreas(class LevelChunk &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NBBRIDGEENDFILLER
#endif
    MCAPI static std::unique_ptr<class NetherFortressPiece> createPiece(std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, int, int, int, int, int);



};