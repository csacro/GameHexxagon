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
     *
     * @param server
     */
    virtual void connect(std::string server) = 0;

    /**
     *
     * @param userId
     */
    virtual void getAvailableLobbies(std::string userId) = 0;

    /**
     *
     * @param userId
     * @param lobbyName
     */
    virtual void createNewLobby(std::string userId, std::string lobbyName) = 0;

    /**
     *
     * @param userId
     * @param lobbyId
     * @param userName
     */
    virtual void joinLobby(std::string userId, std::string lobbyId, std::string userName) = 0;

    /**
     *
     * @param userId
     * @param lobbyId
     */
    virtual void leaveLobby(std::string userId, std::string lobbyId) = 0;

    /**
     *
     * @param userId
     * @param lobbyId
     */
    virtual void startGame(std::string userId, std::string lobbyId) = 0;

    /**
     *
     * @param userId
     * @param gameId
     * @param moveFrom
     * @param moveTo
     */
    virtual void gameMove(std::string userId, std::string gameId, TileEnum moveFrom, TileEnum moveTo) = 0;

    /**
     *
     * @param userId
     * @param gameId
     */
    virtual void leaveGame(std::string userId, std::string gameId) = 0;

    /**
     *
     * @param userId
     */
    virtual void disconnect(std::string userId) = 0;

}; //TODO: documentation


#endif //GAMEHEXXAGON_VIEWTOCLIENT_H
