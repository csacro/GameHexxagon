/**
 * @author Carolin Schindler
 */

#include <iostream>
#include "ViewHandler.h"
#include "../Views/Mainmenu.h"
#include "../Views/Lobbyoverview.h"
#include "../Views/Lobbyview.h"
#include "../Views/Gameview.h"


ViewHandler::ViewHandler(ListenerRenderWindow &listenerRenderWindow,
        ViewToMainmenu &vtm, ViewToLobbyoverview &vtlo) {
    mWindow = &listenerRenderWindow;

    mToMainmenu = &vtm;
    mToLobbyoverview = &vtlo;

    //showMainmenu();
    showLobbyoverview();
}

void ViewHandler::connectServer(std::string server) {
    //TODO
}

void ViewHandler::disconnectServer(std::string server) {
    //TODO
}

void ViewHandler::showLobbyoverview() {
    //mWindow->clearLists();
    mWindow->addElement(mToLobbyoverview);
    mWindow->addListener(mToLobbyoverview);
}

void ViewHandler::close() {
    //TODO: if (connected): disconnect with server
    //TODO onConnect: disconnect with server
    //TODO onDisconnected: window.close()
}

void ViewHandler::updateLobbyoverview() {
    //TODO
}

void ViewHandler::createAndJoinLobby(std::string lobbyName, std::string userName) {
    //TODO
}

void ViewHandler::joinLobby(std::string lobbyName, std::string userName) {
    //TODO
}

void ViewHandler::showMainmenu() {
    mWindow->clearLists();
    mWindow->addElement(mToMainmenu);
    mWindow->addListener(mToMainmenu);
}