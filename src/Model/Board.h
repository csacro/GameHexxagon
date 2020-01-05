/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_BOARD_H
#define GAMEHEXXAGON_BOARD_H


#include <map>
#include <nlohmann/json.hpp>
#include "TileEnum.h"
#include "TileStateEnum.h"

namespace ModelBoard {

    /**
     * struct for Board data
     */
    struct Board {
        std::map<TileEnum, TileStateEnum> tiles; //mapping tile to its state
    };

    /**
     * parse Board from JSON
     * @param j nlohmann::json containing Board as JSON
     * @param board struct Board that is getting initialised by j
     */
    //TODO void from_json(const nlohmann::json &j, struct Board &board) {
        //board.tiles = j.at("tiles").get<std::map<TileEnum, TileStateEnum>>();
    //}

} //namespace ModelBoard


#endif //GAMEHEXXAGON_BOARD_H
