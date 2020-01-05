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
     *
     * @param isConnected
     */
    virtual void infoConnected(bool isConnected) = 0;

    /**
     *
     */
    virtual void gotAvailableLobbies() = 0;

    /**
     *
     * @param success
     */
    virtual void infoLobbyCreated(bool success) = 0;

    /**
     *
     * @param success
     */
    virtual void infoLobbyJoined(bool success) = 0;

    /**
     *
     */
    virtual void gotLobbyStatus() = 0;

    /**
     *
     */
    virtual void infoGameStarted() = 0;

    /**
     *
     */
    virtual void gotGameStatus() = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_DATATOVIEW_H
