/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_GAME_H
#define GAMEHEXXAGON_GAME_H

#include <string>
#include "Board.h"
#include "TileEnum.h"

/**
 * struct for Game data
 */
struct Game {
    std::string gameId; //id of Game
    std::string playerOne; //id of playerOne in Game
    std::string playerTow; //id of playerTwo in Game
    std::string playerOneUserName; //name of playerOne in Game
    std::string playerTowUserName; //name of playerTwo in Game
    int playerOnePoints; //number of stones belonging to playerOne
    int playerTowPoints; //number of stones belonging to playerTwo
    Board board; //current Board in Game
    int trun; //number of current round
    TileEnum lastMoveFrom; //last stone was moved from there
    TileEnum lastMoveTo; //last stone was moved there
    std::string activePlayer; //id of player who makes next move
    bool tie; //true if neither playerOne nor playerTwo has won
    std::string winner; //id of player who has won
    bool isClosed; //false as long as Game is running
};

//TODO

#endif //GAMEHEXXAGON_GAME_H
