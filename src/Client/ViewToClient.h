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
     * called in order to establish a connection with the server
     * @param server std::string containing servername with portnumber
     */
    virtual void connect(std::string server) = 0;

    /**
     * called in order to send a message to the server requesting all available Lobbies
     * @param userId std::string userId of the User
     */
    virtual void getAvailableLobbies(std::string userId) = 0;

    /**
     * called in order to send a message to the server creating a new Lobby
     * @param userId std::string userId of the User
     * @param lobbyName std::string lobbyName of the Lobby to be created
     */
    virtual void createNewLobby(std::string userId, std::string lobbyName) = 0;

    /**
     * called in order to send a message to the server to join the Lobby with lobbyId
     * @param userId std::string userId of the User
     * @param lobbyId std::string lobbyId of the Lobby to be joined
     * @param userName std::string userName of the User
     */
    virtual void joinLobby(std::string userId, std::string lobbyId, std::string userName) = 0;

    /**
     * called in order to send a message to the server notifying it that user has left Lobby
     * @param userId std::string userId of the User
     * @param lobbyId std::string lobbyId of the Lobby to be left
     */
    virtual void leaveLobby(std::string userId, std::string lobbyId) = 0;

     /**
      * called in order to send a message to the server to start the Game
      * @param userId std::string userId of the User
      * @param lobbyId std::string lobbyId of the Lobby from which Game is started
      */
    virtual void startGame(std::string userId, std::string lobbyId) = 0;

    /**
     * called in order to send a message to the server to inform it about the user's move
     * @param userId std::string userId of the User
     * @param gameId std::string gameId of the Game
     * @param moveFrom TileEnum
     * @param moveTo TileEnum
     */
    virtual void gameMove(std::string userId, std::string gameId, ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo) = 0;

    /**
     * called in order to send a message to the server notifying it that user has left Game
     * @param userId std::string userId of the User
     * @param gameId std::string gameId of the Game to be left
     */
    virtual void leaveGame(std::string userId, std::string gameId) = 0;

    /**
     * called in order to close the connection to the server
     */
    virtual void disconnect() = 0;

};


#endif //GAMEHEXXAGON_VIEWTOCLIENT_H
