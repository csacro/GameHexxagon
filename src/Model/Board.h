/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_BOARD_H
#define GAMEHEXXAGON_BOARD_H


#include <map>
#include "TileEnum.h"
#include "TileStateEnum.h"

/**
 * struct for Board data
 */
struct Board {
    std::map<TileEnum, TileStateEnum> tiles; //mapping tile to its state
};

//TODO


#endif //GAMEHEXXAGON_BOARD_H
