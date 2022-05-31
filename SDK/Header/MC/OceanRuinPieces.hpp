// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Bedrock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class OceanRuinPieces {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_OCEANRUINPIECES
public:
    class OceanRuinPieces& operator=(class OceanRuinPieces const &) = delete;
    OceanRuinPieces(class OceanRuinPieces const &) = delete;
    OceanRuinPieces() = delete;
#endif

public:
    MCAPI static void addPieces(class gsl::not_null<class Bedrock::NonOwnerPointer<class StructureManager>>, class BlockPos const &, enum Rotation const &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, struct OceanRuinConfiguration const &);

protected:

private:
    MCAPI static class gsl::basic_string_span<char const, -1> BIG_RUIN_LOOT;
    MCAPI static class gsl::basic_string_span<char const, -1> RUIN_LOOT;
    MCAPI static class gsl::basic_string_span<char const, -1> STRUCTURE_BIG_RUIN1_BRICK;
    MCAPI static class gsl::basic_string_span<char const, -1> STRUCTURE_BIG_RUIN8_BRICK;
    MCAPI static class gsl::basic_string_span<char const, -1> STRUCTURE_RUIN_2_BRICK;
    MCAPI static class gsl::basic_string_span<char const, -1> STRUCTURE_RUIN_3_BRICK;
    MCAPI static void _addClusterRuins(class gsl::not_null<class Bedrock::NonOwnerPointer<class StructureManager>>, class Random &, enum Rotation const &, class BlockPos const &, struct OceanRuinConfiguration const &, std::vector<std::unique_ptr<class StructurePiece>> &);
    MCAPI static void _addPiece(class gsl::not_null<class Bedrock::NonOwnerPointer<class StructureManager>>, class BlockPos const &, enum Rotation const &, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &, struct OceanRuinConfiguration const &, bool, float);
    MCAPI static std::vector<class BlockPos> _allPositions(class Random &, int, int, int);
    MCAPI static class gsl::basic_string_span<char const, -1> bigRuinsBrick[];
    MCAPI static class gsl::basic_string_span<char const, -1> bigRuinsCracked[];
    MCAPI static class gsl::basic_string_span<char const, -1> bigRuinsMossy[];
    MCAPI static class gsl::basic_string_span<char const, -1> bigWarmRuins[];
    MCAPI static class LegacyStructureSettings mSettings;
    MCAPI static class gsl::basic_string_span<char const, -1> ruinsBrick[];
    MCAPI static class gsl::basic_string_span<char const, -1> ruinsCracked[];
    MCAPI static class gsl::basic_string_span<char const, -1> ruinsMossy[];
    MCAPI static class gsl::basic_string_span<char const, -1> warmRuins[];

};