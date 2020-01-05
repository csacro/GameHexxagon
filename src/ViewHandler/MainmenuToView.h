/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_MAINMENUTOVIEW_H
#define GAMEHEXXAGON_MAINMENUTOVIEW_H


#include <string>

/**
 * interface to view used by Mainmenu
 */
class MainmenuToView {
public:
    /**
     * called when user wants to connect to the server
     * @param server std::string the address of the server to connect to
     */
    virtual void connectServer(std::string server) = 0;

    /**
     * called when user wants to disconnect with the server
     */
    virtual void disconnectServer() = 0;

    /**
     * called when the user wants to switch from Mainmenu to Lobbyoverview
     * (only possible when connected)
     */
    virtual void showLobbyoverview() = 0;

    /**
     * called when the user wants to close the application
     * (when connected disconnect with server)
     */
    virtual void close() = 0;

};


#endif //GAMEHEXXAGON_MAINMENUTOVIEW_H
