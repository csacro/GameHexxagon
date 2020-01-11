/**
 * @author Carolin Schindler
 */

#include "Game.h"

namespace ModelGame {
    void from_json(const nlohmann::json &j, Game &game) {
        game.gameId = j.at("gameId").get<std::string>();
        game.playerOne = j.at("playerOne").get<std::string>();
        game.playerTwo = j.at("playerTwo").get<std::string>();
        game.playerOneUserName = j.at("playerOneUserName").get<std::string>();
        game.playerTwoUserName = j.at("playerTwoUserName").get<std::string>();
        game.playerOneLeft = j.at("playerOneLeft").get<bool>();
        game.playerTwoLeft = j.at("playerTwoLeft").get<bool>();
        game.playerOnePoints = j.at("playerOnePoints").get<int>();
        game.playerTwoPoints = j.at("playerTwoPoints").get<int>();
        game.board = j.at("board").get<ModelBoard::Board>();
        game.turn = j.at("turn").get<int>();
        if(j.find("lastMoveFrom") != j.end()) {
            game.lastMoveFrom = ModelTileEnum::StringToTileEnum(j.at("lastMoveFrom").get<std::string>());
            game.lastMoveTo = ModelTileEnum::StringToTileEnum(j.at("lastMoveTo").get<std::string>());
        } else {
            game.lastMoveFrom = ModelTileEnum::TILE_1;
            game.lastMoveTo = ModelTileEnum::TILE_1;
        }
        game.activePlayer = j.at("activePlayer").get<std::string>();
        game.tie = j.at("tie").get<bool>();
        if(j.find("winner") != j.end()) {
            game.winner = j.at("winner").get<std::string>();
        } else {
            game.winner = "";
        }
        game.isClosed = j.at("isClosed").get<bool>();
    }
}  //namespace ModelGame
