/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_LOBBY_H
#define GAMEHEXXAGON_LOBBY_H


#include <string>

/**
 * struct for Lobby data
 */
struct Lobby {
    std::string lobbyId; //id of Lobby
    std::string lobbyName; //name of Lobby
    std::string playerOne; //id of playerOne in Lobby
    std::string playerTwo; //id of playerTwo in Lobby
    std::string playerOneUserName; //name of playerOne in Lobby
    std::string playerTwoUserName; //name of playerTwo in Lobby
    bool isClosed; //false as long as Lobby exists
};

//TODO


#endif //GAMEHEXXAGON_LOBBY_H