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
        std::map<ModelTileEnum::TileEnum, ModelTileStateEnum::TileStateEnum> tiles; //mapping tile to its state
    };

    /**
     * parse Board from JSON
     * @param j nlohmann::json containing Board as JSON
     * @param board struct Board that is getting initialised by j
     */
    void from_json(const nlohmann::json &j, struct Board &board);

} //namespace ModelBoard


#endif //GAMEHEXXAGON_BOARD_H
