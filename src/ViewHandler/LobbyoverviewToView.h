/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_LOBBYOVERVIEWTOVIEW_H
#define GAMEHEXXAGON_LOBBYOVERVIEWTOVIEW_H


#include <string>

/**
 * interface to ViewHandler used by Lobbyoverview
 */
class LobbyoverviewToView {
public:
    /**
     * called when the user wants to get new data for the Lobbies that are joinable
     */
    virtual void updateLobbyoverview() = 0;

    /**
     * called when the user wants to create a new Lobby and then automatically joins the Lobby
     * @param lobbyName std::string name of the Lobby to be created
     * @param userName std::string name going to be displayed for the user in the Lobbyview and Gameview
     */
    virtual void createAndJoinLobby(std::string lobbyName, std::string userName) = 0;

    /**
     * called when the user wants to join a Lobby
     * @param lobbyName std::string name of the Lobby the user wants to join
     * (Lobby with lobbyName might not exist)
     * @param userName std::string name going to be displayed for the user in the Lobbyview and Gameview
     */
    virtual void joinLobby(std::string lobbyName, std::string userName) = 0;

    /**
     * called when the user wants to go back to the Mainmenu
     */
    virtual void showMainmenu() = 0;
};


#endif //GAMEHEXXAGON_LOBBYOVERVIEWTOVIEW_H
