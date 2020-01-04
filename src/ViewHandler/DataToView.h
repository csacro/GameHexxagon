/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_DATATOVIEW_H
#define GAMEHEXXAGON_DATATOVIEW_H


/**
 * interface to view used by DataHandler
 */
class DataToView {
public:
    virtual void infoConnected(bool isConnected) = 0;
    virtual void gotAvailableLobbies() = 0;
    virtual void infoLobbyCreated(bool success) = 0;
    virtual void infoLobbyJoined(bool success) = 0;
    virtual void gotLobbyStatus() = 0;
    virtual void infoGameStarted() = 0;
    virtual void gotGameStatus() = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_DATATOVIEW_H