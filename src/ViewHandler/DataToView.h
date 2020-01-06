/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_DATATOVIEW_H
#define GAMEHEXXAGON_DATATOVIEW_H


/**
 * interface to ViewHandler used by DataHandler
 */
class DataToView {
public:
    /**
     * to inform ViewHandler about changed connection state to server
     * @param isConnected bool is true when connected to server, else false
     */
    virtual void infoConnected(bool isConnected) = 0;

    /**
     * to inform ViewHandler that more up to date list of available Lobbies is available
     */
    virtual void gotAvailableLobbies() = 0;

    /**
     * to inform ViewHandler about success of creating Lobby
     * @param success bool is true when Lobby got created successfully, else false
     */
    virtual void infoLobbyCreated(bool success) = 0;

    /**
     * to inform ViewHandler about success of joining Lobby
     * @param success bool is true when Lobby got joined successfully, else false
     */
    virtual void infoLobbyJoined(bool success) = 0;

    /**
     * to inform ViewHandler that more up to date status of Lobby is available
     */
    virtual void gotLobbyStatus() = 0;

    /**
     * to inform ViewHandler that Game has been started
     */
    virtual void infoGameStarted() = 0;

    /**
     * to inform ViewHandler that more up to date status of Game is available
     */
    virtual void gotGameStatus() = 0;
};


#endif //GAMEHEXXAGON_DATATOVIEW_H
