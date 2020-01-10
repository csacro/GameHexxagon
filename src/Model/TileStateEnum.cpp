/**
 * @author Carolin Schindler
 */

#include "TileStateEnum.h"

namespace ModelTileStateEnum {

    std::map <std::string, TileStateEnum> tilestateenumMapper = {
            {"FREE",      FREE},
            {"PLAYERONE", PLAYERONE},
            {"PLAYERTWO", PLAYERTWO},
            {"BLOCKED",   BLOCKED}
    };
} //namespace ModelTileStateEnum
