/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_LOBBYOVERVIEWTOVIEW_H
#define GAMEHEXXAGON_LOBBYOVERVIEWTOVIEW_H


#include <string>

/**
 * interface to view used by Lobbyoverview
 */
class LobbyoverviewToView {
public:
    virtual void updateLobbyoverview() = 0;
    virtual void createAndJoinLobby(std::string lobbyName, std::string userName) = 0;
    virtual void joinLobby(std::string lobbyName, std::string userName) = 0;
    virtual void showMainmenu() = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_LOBBYOVERVIEWTOVIEW_H
