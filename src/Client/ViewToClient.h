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
    /**
     * TODO: documentation
     * @param server std::string
     */
    virtual void connect(std::string server) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     */
    virtual void getAvailableLobbies(std::string userId) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     * @param lobbyName std::string
     */
    virtual void createNewLobby(std::string userId, std::string lobbyName) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     * @param lobbyId std::string
     * @param userName std::string
     */
    virtual void joinLobby(std::string userId, std::string lobbyId, std::string userName) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     * @param lobbyId std::string
     */
    virtual void leaveLobby(std::string userId, std::string lobbyId) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     * @param lobbyId std::string
     */
    virtual void startGame(std::string userId, std::string lobbyId) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     * @param gameId std::string
     * @param moveFrom TileEnum
     * @param moveTo TileEnum
     */
    virtual void gameMove(std::string userId, std::string gameId, TileEnum moveFrom, TileEnum moveTo) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     * @param gameId std::string
     */
    virtual void leaveGame(std::string userId, std::string gameId) = 0;

    /**
     * TODO: documentation
     * @param userId std::string
     */
    virtual void disconnect(std::string userId) = 0;

};


#endif //GAMEHEXXAGON_VIEWTOCLIENT_H
