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
    virtual void forwardAvailableLobbies(std::list<Lobby> lobbies) = 0;
    virtual void infoLobbyCreated(bool success) = 0;
    virtual void infoLobbyJoined(bool succes) = 0;
    virtual void forwardLobbyStatus(Lobby lobby) = 0;
    virtual void infoGameStarted() = 0;
    virtual void forwardGameStatus(Game game) = 0;
}; //TODO

//TODO


#endif //GAMEHEXXAGON_CLIENTTODATA_H
