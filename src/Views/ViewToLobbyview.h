/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_VIEWTOLOBBYVIEW_H
#define GAMEHEXXAGON_VIEWTOLOBBYVIEW_H


#include <SFMLComponents/WindowViews/WindowView.h>

/**
 * interface to Lobbyview used by ViewHandler
 */
class ViewToLobbyview: public WindowView {
public:
    /**
     * called by ViewHandler to update Lobbyoverview
     * @param lobbyName std::string name of Lobby User is in
     * @param playerOneUserName std::string name of playerOne in Lobby
     * @param playerOneUserName std::string name of playerTwo in Lobby
     * @param isStartable bool is true when User is allowed to start the Game
     */
    virtual void display(std::string lobbyName,
            std::string playerOneUserName, std::string playerTwoUserName,
            bool isStartable)
            = 0;
};


#endif //GAMEHEXXAGON_VIEWTOLOBBYVIEW_H
