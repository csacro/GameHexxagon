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
#include "GameviewToView.h"
//#include "../Client/ViewToClient.h"
//#include "../DataHandler/ViewToData.h"

class ViewHandler: public MainmenuToView, public LobbyoverviewToView, public LobbyviewToView, public GameviewToView {
public:
    /**
     * Constructor
     * @param renderWindow sf::RenderWindow in which Views are rendered
     * @param vtm ViewToMainmenu to communicate with Mainmenu
     * @param vtlo ViewToLobbyoverview to communicate with Lobbyoverview
     * @param vtl ViewToLobbyview to communicate with Lobbyview
     * @param vtg ViewToGameview to communicate with Gameview
     * @param vtc ViewToClient to communicate with Client
     * @param vtd ViewToData to communicate with DataHandler
     */
    ViewHandler(ListenerRenderWindow &listenerRenderWindow,
            ViewToMainmenu &vtm, ViewToLobbyoverview &vtlo, ViewToLobbyview &vtl, ViewToGameview &vtg);
    //TODO: vtc and vtd

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

    std::list<TileEnum> getNeighbours(std::list<TileEnum> tiles) override;

    void move(TileEnum moveFrom, TileEnum moveTo) override;

    void leaveGame() override;

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

    /**
     * method to switch View to Gameview
     */
    void showGameview();

};


#endif //GAMEHEXXAGON_VIEWHANDLER_H
