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
    virtual void startGame() = 0;
    virtual void leaveLobby() = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_LOBBYVIEWTOVIEW_H
