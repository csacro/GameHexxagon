/**
 * @author Carolin Schindler
 */

#include "TileEnum.h"

namespace ModelTileEnum {
    std::string TileEnumToString(TileEnum tileEnum) {
        return "TILE_" + std::to_string(tileEnum + 1);
    }

    TileEnum StringToTileEnum(std::string s) {
        return (TileEnum)(std::stoi(s) - 1);
    }
} //namespace ModelTileEnum
