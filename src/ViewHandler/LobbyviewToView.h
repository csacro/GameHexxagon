/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_LOBBYVIEWTOVIEW_H
#define GAMEHEXXAGON_LOBBYVIEWTOVIEW_H


/**
 * interface to ViewHandler used by Lobbyview
 */
class LobbyviewToView {
public:
    /**
     * called when the user wants to start the Game
     * (only possible if two players in Lobby and user is playerOne)
     */
    virtual void startGame() = 0;

    /**
     * called when user wants to leave the Lobby and return to Lobbyoverview
     */
    virtual void leaveLobby() = 0;
};


#endif //GAMEHEXXAGON_LOBBYVIEWTOVIEW_H
