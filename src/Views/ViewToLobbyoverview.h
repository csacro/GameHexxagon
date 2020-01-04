/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_VIEWTOLOBBYOVERVIEW_H
#define GAMEHEXXAGON_VIEWTOLOBBYOVERVIEW_H

#include <list>
#include <string>
#include <SFMLComponents/WindowViews/WindowView.h>

/**
 * interface to Lobbyoverview used by ViewHandler
 */
class ViewToLobbyoverview: public WindowView {
public:
    /**
     * called by ViewHandler to update Lobbyoverview
     * @param lobbyNames std::vector<std::string> containing names of available Lobbies
     */
    virtual void display(std::vector<std::string> lobbyNames) = 0;
};


#endif //GAMEHEXXAGON_VIEWTOLOBBYOVERVIEW_H
