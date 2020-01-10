/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_TILESTATEENUM_H
#define GAMEHEXXAGON_TILESTATEENUM_H

/**
 * enumeration of possible states for tiles
 */
enum TileStateEnum {
    FREE, //tile is free
    PLAYERONE, //stone of playerOne on tile
    PLAYERTWO, //stone of playerTwo on tile
    BLOCKED //tile is blocked
};

/* TODO: will need for Board
std::map<std::string, TileStateEnum > tilestateenumMapper = {
        {"FREE", FREE},
        {"PLAYERONE", PLAYERONE},
        {"PLAYERTWO", PLAYERTWO},
        {"BLOCKED", BLOCKED}
};
 */

#endif //GAMEHEXXAGON_TILESTATEENUM_H
