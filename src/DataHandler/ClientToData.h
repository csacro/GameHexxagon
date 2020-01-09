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
    /**
     * to inform the DataHandler about changed connection state
     * @param userId std::string userId that was assigned to the client by server, is empty if connection got closed
     */
    virtual void setUserId(std::string userId) = 0;

    /**
     * to inform the DataHandler about more current list of available Lobbies
     * @param lobbies std::list<ModelLobby::Lobby> list of all Lobbies that are available at the moment
     */
    virtual void forwardAvailableLobbies(std::list<ModelLobby::Lobby> lobbies) = 0;

    /**
     * to inform the DataHandler if the Lobby was created or not
     * @param lobbyId std::string lobbyId of the created Lobby if Lobby was created, else empty string
     * @param success bool is true when the Lobby was created
     */
    virtual void infoLobbyCreated(std::string lobbyId, bool success) = 0;

    /**
     * to inform the DataHandler if the Lobby was joined successfully
     * @param success bool is true when Lobby was joined successfully, else false
     */
    virtual void infoLobbyJoined(bool success) = 0;

    /**
     * to inform the DataHandler about more current status of the Lobby user is in
     * @param lobby ModelLobby::Lobby updated/current Lobby
     */
    virtual void forwardLobbyStatus(ModelLobby::Lobby lobby) = 0;

    /**
     * to inform the DataHandler that the server sent a GameStart message
     */
    virtual void infoGameStarted() = 0;

    /**
     * to inform the DataHandler about more current status of the Game user is in
     * @param game ModelGame::Game updated/current Game
     */
    virtual void forwardGameStatus(ModelGame::Game game) = 0;
};


#endif //GAMEHEXXAGON_CLIENTTODATA_H
