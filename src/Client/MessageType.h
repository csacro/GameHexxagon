/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_MESSAGETYPE_H
#define GAMEHEXXAGON_MESSAGETYPE_H

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

//TODO

#endif //GAMEHEXXAGON_MESSAGETYPE_H
