/**
 * @author Carolin Schindler
 */

#include <iostream>
#include "ViewHandler.h"


ViewHandler::ViewHandler(ListenerRenderWindow &listenerRenderWindow,
        ViewToMainmenu &vtm, ViewToLobbyoverview &vtlo, ViewToLobbyview &vtl, ViewToGameview &vtg,
                         ViewToData &vtd, ViewToClient &vtc) {
    mWindow = &listenerRenderWindow;

    mToMainmenu = &vtm;
    mToLobbyoverview = &vtlo;
    mToLobbyview = &vtl;
    mToGameview = &vtg;
    mToData = &vtd;
    mToClient = &vtc;

    showMainmenu();
}

void ViewHandler::showLobbyview() {
    mToLobbyview->display("", "", "", false);

    mWindow->clearLists();
    mWindow->addElement(mToLobbyview);
    mWindow->addListener(mToLobbyview);
}

void ViewHandler::showGameview() {
    std::list<std::string> lobbystrings = mToData->getLobbyStrings();
    auto it2 = lobbystrings.begin();
    std::advance(it2, 1);
    auto it3 = lobbystrings.begin();
    std::advance(it3, 2);
    mToGameview->displayPlayerNames(*it2, *it3);

    mWindow->clearLists();
    mWindow->addElement(mToGameview);
    mWindow->addListener(mToGameview);
}


void ViewHandler::connectServer(std::string server) {
    mToClient->connect(server);
}

void ViewHandler::disconnectServer() {
    mToClient->disconnect(mToData->getUserId());
}

void ViewHandler::showLobbyoverview() {
    updateLobbyoverview();
    std::list<std::string> emptyList;
    mToLobbyoverview->display(emptyList);

    mWindow->clearLists();
    mWindow->addElement(mToLobbyoverview);
    mWindow->addListener(mToLobbyoverview);
}

void ViewHandler::close() {
    if(mToData->isConnected()) {
        mToClient->disconnect(mToData->getUserId());
    }
    mWindow->close();
}

void ViewHandler::updateLobbyoverview() {
    mToClient->getAvailableLobbies(mToData->getUserId());
}

void ViewHandler::createAndJoinLobby(std::string lobbyName, std::string userName) {
    mToData->setUserName(userName);
    mToClient->createNewLobby(mToData->getUserId(), lobbyName);
}

void ViewHandler::joinLobby(std::string lobbyName, std::string userName) {
    mToData->setUserName(userName);
    std::string lobbyId = mToData->getLobbyId(lobbyName);
    if(!lobbyId.empty()) {
        mToClient->joinLobby(mToData->getUserId(), lobbyId, userName);
    }
}

void ViewHandler::showMainmenu() {
    mWindow->clearLists();
    mWindow->addElement(mToMainmenu);
    mWindow->addListener(mToMainmenu);
}

void ViewHandler::startGame() {
    mToClient->startGame(mToData->getUserId(), mToData->getLobbyId());
}

void ViewHandler::leaveLobby() {
    mToClient->leaveLobby(mToData->getUserId(), mToData->getLobbyId());
    showLobbyoverview();
}

std::list<TileEnum> ViewHandler::getNeighbours(std::list<TileEnum> tiles) {
    //TODO: getNeighbours for spielfed
    return std::list<TileEnum>();
}

void ViewHandler::move(TileEnum moveFrom, TileEnum moveTo) {
    if(mToData->isMoveValid(moveFrom, moveTo)) {
        mToClient->gameMove(mToData->getUserId(), mToData->getGameId(), moveFrom, moveTo);
    }
}

void ViewHandler::leaveGame() {
    mToClient->leaveGame(mToData->getUserId(), mToData->getGameId());
    showLobbyoverview();
}


void ViewHandler::infoConnected(bool isConnected) {
    mToMainmenu->display(isConnected);
    if(!isConnected) {
        showMainmenu();
    }
}

void ViewHandler::gotAvailableLobbies() {
    mToLobbyoverview->display(mToData->getJoinableLobbyNames());
}

void ViewHandler::infoLobbyCreated(bool success) {
    if(success) {
        mToClient->joinLobby(mToData->getUserId(), mToData->getLobbyId(), mToData->getUserName());
    }
}

void ViewHandler::infoLobbyJoined(bool success) {
    if(success) {
        showLobbyview();
    }
}

void ViewHandler::gotLobbyStatus() {
    std::list<std::string> lobbystrings = mToData->getLobbyStrings();
    auto it1 = lobbystrings.begin();
    auto it2 = lobbystrings.begin();
    std::advance(it2, 1);
    auto it3 = lobbystrings.begin();
    std::advance(it3, 2);
    mToLobbyview->display(*it1, *it2, *it3, mToData->isGameStartable());
}

void ViewHandler::infoGameStarted() {
    showGameview();
}

void ViewHandler::gotGameStatus() {
    std::list<std::string> gamestrings = mToData->getGameStrings();
    std::list<bool> gamebools = mToData->getGameBooleans();
    std::list<TileEnum> lastmove = mToData->getLastMove();
    ModelBoard::Board board = mToData->getBoard();
    if(gamebools.size() == 1) {
        mToGameview->display(*gamestrings.begin(), *gamestrings.end(), *lastmove.begin(), *lastmove.end(), board, *gamebools.begin());
    } else {
        mToGameview->display(*gamestrings.begin(), *gamestrings.end(), *lastmove.begin(), *lastmove.end(), board, *gamebools.begin(), *gamebools.end());
    }
}