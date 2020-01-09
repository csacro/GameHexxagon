/**
 * @author Carolin Schindler
 */

#include "Lobby.h"

namespace ModelLobby {
    void from_json(const nlohmann::json &j, struct Lobby &lobby) {
        lobby.lobbyId = j.at("lobbyId").get<std::string>();
        lobby.lobbyName = j.at("lobbyName").get<std::string>();
        lobby.playerOne = j.at("playerOne").get<std::string>();
        lobby.playerOneUserName = j.at("playerOneUserName").get<std::string>();
        lobby.playerTwo = j.at("playerTwo").get<std::string>();
        lobby.playerTwoUserName = j.at("playerTwoUserName").get<std::string>();
        lobby.isClosed = j.at("isClosed").get<bool>();
    }
}  //namespace ModelLobby
