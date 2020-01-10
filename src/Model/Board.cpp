/**
 * @author Carolin Schindler
 */

#include "Board.h"

namespace ModelBoard {
    void from_json(const nlohmann::json &j, struct Board &board) {
        //TODO (no json for Tile(State)Enum): board.tiles = j.at("tiles").get<std::map<TileEnum, TileStateEnum>>();
    }
}  //namespace ModelBoard
