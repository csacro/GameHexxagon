/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_VIEWHANDLER_H
#define GAMEHEXXAGON_VIEWHANDLER_H


#include <SFMLComponents/Window/ListenerRenderWindow.h>
#include "MainmenuToView.h"
#include "../Views/ViewToMainmenu.h"
#include "../Views/ViewToLobbyoverview.h"
#include "../Views/ViewToLobbyview.h"
#include "../Views/ViewToGameview.h"
#include "LobbyoverviewToView.h"
//#include "../Client/ViewToClient.h"
//#include "../DataHandler/ViewToData.h"

class ViewHandler: public MainmenuToView, public LobbyoverviewToView {
public:
    /**
     * Constructor
     * @param renderWindow sf::RenderWindow in which Views are rendered
     * @param vtc ViewToClient to communicate with Client
     * @param vtd ViewToData to communicate with DataHandler
     */
    ViewHandler(ListenerRenderWindow &listenerRenderWindow,
            ViewToMainmenu &vtm, ViewToLobbyoverview &vtlo);

    void connectServer(std::string server) override;

    void disconnectServer(std::string server) override;

    void showLobbyoverview() override;

    void close() override;

    void updateLobbyoverview() override;

    void createAndJoinLobby(std::string lobbyName, std::string userName) override;

    void joinLobby(std::string lobbyName, std::string userName) override;

    void showMainmenu() override;

private:
    ListenerRenderWindow *mWindow; //here Views are rendered
    //ViewToData *mToData; //interface to DataHandler
    //ViewToClient *mToClient; //interface to Client

    ViewToMainmenu *mToMainmenu; //interface to Mainmenu
    ViewToLobbyoverview *mToLobbyoverview; //interface to Lobbyoverview
    ViewToLobbyview *mToLobbyview; //interface to Lobbyview
    ViewToGameview *mToGameview; //interface to Gameview

//TODO: work in progress
};


#endif //GAMEHEXXAGON_VIEWHANDLER_H
