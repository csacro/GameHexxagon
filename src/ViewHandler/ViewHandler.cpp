/**
 * @author Carolin Schindler
 */

#include "ViewHandler.h"
#include "../Views/Mainmenu.h"
#include "../Views/Lobbyoverview.h"
#include "../Views/Lobbyview.h"
#include "../Views/Gameview.h"


ViewHandler::ViewHandler(ListenerRenderWindow &listenerRenderWindow, ViewToMainmenu &vtm) {
    mWindow = &listenerRenderWindow;

    mToMainmenu = &vtm;

    mWindow->addElement(mToMainmenu);
    mWindow->addListener(mToMainmenu);
}

void ViewHandler::connectServer(std::string server) {
    //TODO
}

void ViewHandler::disconnectServer(std::string server) {
    //TODO
}

void ViewHandler::showLobbyoverview() {
    //TODO
}

void ViewHandler::close() {
    //TODO: if (connected): disconnect with server
    //TODO onConnect: disconnect with server
    //TODO onDisconnected: window.close()
}
