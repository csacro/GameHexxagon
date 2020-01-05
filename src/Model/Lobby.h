/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_LOBBY_H
#define GAMEHEXXAGON_LOBBY_H


#include <string>
#include <nlohmann/json.hpp>

namespace ModelLobby {

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

    /**
     * parse Lobby from JSON
     * @param j nlohmann::json containing Lobby as JSON
     * @param lobby struct Lobby that is getting initialised by j
     */
    /*TODO void from_json(const nlohmann::json &j, struct Lobby &lobby) {
        lobby.lobbyId = j.at("lobbyId").get<std::string>();
        lobby.lobbyName = j.at("lobbyName").get<std::string>();
        lobby.playerOne = j.at("playerOne").get<std::string>();
        lobby.playerOneUserName = j.at("playerOneUserName").get<std::string>();
        lobby.playerTwo = j.at("playerTwo").get<std::string>();
        lobby.playerTwoUserName = j.at("playerTwoUserName").get<std::string>();
        lobby.isClosed = j.at("isClosed").get<bool>();
    }*/

} //namespace ModelLobby


#endif //GAMEHEXXAGON_LOBBY_H