/**
 * @author Carolin Schindler
 */

#include "TileEnum.h"

namespace ModelTileEnum {
    std::string TileEnumToString(TileEnum tileEnum) {
        return "TILE_" + std::to_string(tileEnum + 1);
    }

    TileEnum StringToTileEnum(std::string s) {
        int splitpos = s.find("_");
        int tileNumber = std::stoi(s.substr(splitpos+1, s.size()-1));
        return (TileEnum)(tileNumber - 1);
    }
} //namespace ModelTileEnum
