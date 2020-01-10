/**
 * @author Carolin Schindler
 */

#include "Board.h"

namespace ModelBoard {
    void from_json(const nlohmann::json &j, struct Board &board) {

        ModelTileEnum::TileEnum te;
        ModelTileStateEnum::TileStateEnum tse;
        for(int i = 1; i <= 61; i++) {
            te = ModelTileEnum::StringToTileEnum(std::to_string(i));
            tse = ModelTileStateEnum::tilestateenumMapper.at(j.at("tiles").at(TileEnumToString(te)).get<std::string>());
            board.tiles.emplace(te, tse);
        }
    }
}  //namespace ModelBoard
