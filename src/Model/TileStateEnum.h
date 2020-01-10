/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_TILESTATEENUM_H
#define GAMEHEXXAGON_TILESTATEENUM_H


#include <string>
#include <map>

namespace ModelTileStateEnum {
    /**
     * enumeration of possible states for tiles
     */
    enum TileStateEnum {
        FREE, //tile is free
        PLAYERONE, //stone of playerOne on tile
        PLAYERTWO, //stone of playerTwo on tile
        BLOCKED //tile is blocked
    };

    /**
     * map maps TileStateEnum with std::string values
     */
    extern std::map <std::string, TileStateEnum> tilestateenumMapper;
} //namespace ModelTileStateEnum

#endif //GAMEHEXXAGON_TILESTATEENUM_H
