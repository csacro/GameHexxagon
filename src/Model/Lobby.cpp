/**
 * @author Carolin Schindler
 */

#include "Lobby.h"

namespace ModelLobby {
    void from_json(const nlohmann::json &j, struct Lobby &lobby) {
        lobby.lobbyId = j.at("lobbyId").get<std::string>();
        lobby.lobbyName = j.at("lobbyName").get<std::string>();
        if(j.find("playerOne") != j.end()) {
            lobby.playerOne = j.at("playerOne").get<std::string>();
            lobby.playerOneUserName = j.at("playerOneUserName").get<std::string>();
        } else {
            lobby.playerOne = "";
            lobby.playerOneUserName = "";
        }
        if(j.find("playerTwo") != j.end()) {
            lobby.playerTwo = j.at("playerTwo").get<std::string>();
            lobby.playerTwoUserName = j.at("playerTwoUserName").get<std::string>();
        } else {
            lobby.playerTwo = "";
            lobby.playerTwoUserName = "";
        }
        lobby.isClosed = j.at("isClosed").get<bool>();
    }
}  //namespace ModelLobby
