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
#include "LobbyviewToView.h"
//#include "../Client/ViewToClient.h"
//#include "../DataHandler/ViewToData.h"

class ViewHandler: public MainmenuToView, public LobbyoverviewToView, public LobbyviewToView {
public:
    /**
     * Constructor
     * @param renderWindow sf::RenderWindow in which Views are rendered
     * @param vtc ViewToClient to communicate with Client
     * @param vtd ViewToData to communicate with DataHandler
     */
    ViewHandler(ListenerRenderWindow &listenerRenderWindow,
            ViewToMainmenu &vtm, ViewToLobbyoverview &vtlo, ViewToLobbyview &vtl);

    void connectServer(std::string server) override;

    void disconnectServer(std::string server) override;

    void showLobbyoverview() override;

    void close() override;

    void updateLobbyoverview() override;

    void createAndJoinLobby(std::string lobbyName, std::string userName) override;

    void joinLobby(std::string lobbyName, std::string userName) override;

    void showMainmenu() override;

    void startGame() override;

    void leaveLobby() override;

private:
    ListenerRenderWindow *mWindow; //here Views are rendered
    //ViewToData *mToData; //interface to DataHandler
    //ViewToClient *mToClient; //interface to Client

    ViewToMainmenu *mToMainmenu; //interface to Mainmenu
    ViewToLobbyoverview *mToLobbyoverview; //interface to Lobbyoverview
    ViewToLobbyview *mToLobbyview; //interface to Lobbyview
    ViewToGameview *mToGameview; //interface to Gameview

    /**
     * method to switch View to Lobbyview
     */
    void showLobbyview();

//TODO: work in progress
};


#endif //GAMEHEXXAGON_VIEWHANDLER_H
