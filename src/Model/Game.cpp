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
        game.playerOnePoints = j.at("playerOnePoints");
        game.playerTwoPoints = j.at("playerTwoPoints");
        game.board = j.at("board").get<ModelBoard::Board>();
        game.turn = j.at("turn").get<bool>();
        game.lastMoveFrom = (TileEnum)(std::stoi(j.at("lastMoveFrom").get<std::string>()) -1);
        game.lastMoveTo = (TileEnum)(std::stoi(j.at("lastMoveTo").get<std::string>()) -1);
        game.activePlayer = j.at("activePlayer").get<std::string>();
        game.tie = j.at("tie").get<bool>();
        game.winner = j.at("winner").get<std::string>();
        game.isClosed = j.at("isClosed").get<bool>();
    }
}  //namespace ModelGame