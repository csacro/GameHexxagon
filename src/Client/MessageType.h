/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_MESSAGETYPE_H
#define GAMEHEXXAGON_MESSAGETYPE_H


#include <nlohmann/json.hpp>

/**
 * specifies values for MessageType in Message
 */
enum MessageType {
    Welcome,
    GetAvailableLobbies,
    AvailableLobbies,
    CreateNewLobby,
    LobbyCreated,
    JoinLobby,
    LobbyJoined,
    LobbyStatus,
    LeaveLobby,
    StartGame,
    GameStarted,
    GameStatus,
    GameMove,
    LeaveGame,
    Strike
};

std::map<std::string, MessageType> messagetypeMapper = {
        {"Welcome", Welcome},
        {"GetAvailableLobbies", GetAvailableLobbies},
        {"AvailableLobbies", AvailableLobbies},
        {"CreateNewLobby", CreateNewLobby},
        {"LobbyCreated", LobbyCreated},
        {"JoinLobby", JoinLobby},
        {"LobbyJoined", LobbyJoined},
        {"LobbyStatus", LobbyStatus},
        {"LeaveLobby", LeaveLobby},
        {"StartGame", StartGame},
        {"GameStarted", GameStarted},
        {"GameStatus", GameStatus},
        {"GameMove", GameMove},
        {"LeaveGame", LeaveGame},
        {"Strike", Strike}
};

std::string messageTypeToString(MessageType mt) {
    for(auto &m: messagetypeMapper) {
        if(m.second == mt) {
            return m.first;
        }
    }
}

/**
 * parse MessageType to JSON
 * @param j nlohmann::json that is getting created with messageType
 * @param messageType MessageType that is parsed to JSON
 */
void to_json(nlohmann::json &j, const MessageType messageType) {
    j["messageType"] = messageTypeToString(messageType);
}

#endif //GAMEHEXXAGON_MESSAGETYPE_H
