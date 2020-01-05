/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_VIEWTOCLIENT_H
#define GAMEHEXXAGON_VIEWTOCLIENT_H


#include <string>
#include "../Model/TileEnum.h"

/**
 * interface to Client used by ViewHandler
 */
class ViewToClient {
public:
    virtual void connect(std::string server) = 0;
    virtual void getAvailableLobbies(std::string userId) = 0;
    virtual void createNewLobby(std::string userId, std::string lobbyName) = 0;
    virtual void joinLobby(std::string userId, std::string lobbyId, std::string userName) = 0;
    virtual void leaveLobby(std::string userId, std::string lobbyId) = 0;
    virtual void startGame(std::string userId, std::string lobbyId) = 0;
    virtual void gameMove(std::string userId, std::string gameId, TileEnum moveFrom, TileEnum moveTo) = 0;
    virtual void leaveGame(std::string userId, std::string gameId) = 0;
    virtual void disconnect(std::string userId) = 0;

}; //TODO: documentation


#endif //GAMEHEXXAGON_VIEWTOCLIENT_H
