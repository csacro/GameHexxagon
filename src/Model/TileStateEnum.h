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

std::string tilestateenumToString(TileStateEnum mt) {
    for(auto &m: tilestateenumMapper) {
        if(m.second == mt) {
            return m.first;
        }
    }
}
 */

#endif //GAMEHEXXAGON_TILESTATEENUM_H
