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
        ModelTileEnum::TileEnum lastMoveFrom; //last stone was moved from there
        ModelTileEnum::TileEnum lastMoveTo; //last stone was moved there
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
    void from_json(const nlohmann::json &j, Game &game);

} //namespace ModelGame


#endif //GAMEHEXXAGON_GAME_H
