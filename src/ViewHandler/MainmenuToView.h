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
    virtual void connectServer(std::string server) = 0;
    virtual void disconnectServer() = 0;
    virtual void showLobbyoverview() = 0;
    virtual void close() = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_MAINMENUTOVIEW_H
