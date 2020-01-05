/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_CLIENTTODATA_H
#define GAMEHEXXAGON_CLIENTTODATA_H


#include <string>
#include <list>
#include "../Model/Lobby.h"
#include "../Model/Game.h"

/**
 * interface to data used by Client
 */
class ClientToData {
public:
    virtual void setUserId(std::string userId) = 0;
    virtual void forwardAvailableLobbies(std::list<ModelLobby::Lobby> lobbies) = 0;
    virtual void infoLobbyCreated(std::string lobbyId, bool success) = 0;
    virtual void infoLobbyJoined(bool success) = 0;
    virtual void forwardLobbyStatus(ModelLobby::Lobby lobby) = 0;
    virtual void infoGameStarted() = 0;
    virtual void forwardGameStatus(ModelGame::Game game) = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_CLIENTTODATA_H
