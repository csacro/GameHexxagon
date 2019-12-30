/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_GAME_H
#define GAMEHEXXAGON_GAME_H

#include <string>
#include <nlohmann/json.hpp>
#include "Board.h"
#include "TileEnum.h"

namespace ModelGame {
    /**
     * struct for Game data
     */
    struct Game {
        std::string gameId; //id of Game
        std::string playerOne; //id of playerOne in Game
        std::string playerTwo; //id of playerTwo in Game
        std::string playerOneUserName; //name of playerOne in Game
        std::string playerTwoUserName; //name of playerTwo in Game
        bool playerOneLeft; //true if playerOne left Game
        bool playerTwoLeft; //true if playerTwo left Game
        int playerOnePoints; //number of stones belonging to playerOne
        int playerTwoPoints; //number of stones belonging to playerTwo
        ModelBoard::Board board; //current Board in Game
        int turn; //number of current round
        TileEnum lastMoveFrom; //last stone was moved from there
        TileEnum lastMoveTo; //last stone was moved there
        std::string activePlayer; //id of player who makes next move
        bool tie; //true if neither playerOne nor playerTwo has won
        std::string winner; //id of player who has won
        bool isClosed; //false as long as Game is running
    };

    /**
     * parse Game from JSON
     * @param j nlohmann::json containing Game as JSON
     * @param game struct Game that is getting initialised by j
     */
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
        game.lastMoveFrom = j.at("lastMoveFrom").get<TileEnum>();
        game.lastMoveTo = j.at("lastMoveTo").get<TileEnum>();
        game.activePlayer = j.at("activePlayer").get<std::string>();
        game.tie = j.at("tie").get<bool>();
        game.winner = j.at("winner").get<std::string>();
        game.isClosed = j.at("isClosed").get<bool>();
    }

} //namespace ModelGame


#endif //GAMEHEXXAGON_GAME_H
