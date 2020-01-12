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
    mToGameview->clearHelp();
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
    if(!mToData->isConnected()) {
        mToClient->connect(server);
    }
}

void ViewHandler::disconnectServer() {
    if(mToData->isConnected()) {
        mToClient->disconnect();
    }
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
        mToClient->disconnect();
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
    } else {
        joinWasNotPossible = lobbyName;
        updateLobbyoverview();
    }
}

void ViewHandler::showMainmenu() {
    mWindow->clearLists();
    mWindow->addElement(mToMainmenu);
    mWindow->addListener(mToMainmenu);
}

void ViewHandler::startGame() {
    if(mToData->isGameStartable()) {
        mToClient->startGame(mToData->getUserId(), mToData->getLobbyId());
    }
}

void ViewHandler::leaveLobby() {
    mToClient->leaveLobby(mToData->getUserId(), mToData->getLobbyId());
    showLobbyoverview();
}

bool ViewHandler::getMoveHelp(ModelTileEnum::TileEnum tile) {
    if(mToData->isMoveFromPossible(tile)) {
        mToGameview->displayHelp(mToData->getValidDirectNeighbours(tile), mToData->getValidSecondaryNeighbours(tile));
        return true;
    }
    return false;
}

bool ViewHandler::move(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo) {
    mToGameview->clearHelp();
    if(mToData->isMoveValid(moveFrom, moveTo)) {
        mToClient->gameMove(mToData->getUserId(), mToData->getGameId(), moveFrom, moveTo);
        return true;
    }
    return false;
}

void ViewHandler::leaveGame(bool sendLeave) {
    if(sendLeave) {
        mToClient->leaveGame(mToData->getUserId(), mToData->getGameId());
    }
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
    if(!joinWasNotPossible.empty()) {
        joinLobby(joinWasNotPossible, mToData->getUserName());
        joinWasNotPossible = "";
    }
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
    std::list<ModelTileEnum::TileEnum> lastmove = mToData->getLastMove();
    ModelBoard::Board board = mToData->getBoard();
    if(gamebools.size() == 1) {
        mToGameview->display(gamestrings.front(), gamestrings.back(), lastmove.front(), lastmove.back(), board, gamebools.front());
    } else {
        mToGameview->display(gamestrings.front(), gamestrings.back(), lastmove.front(), lastmove.back(), board, gamebools.front(), gamebools.back());
    }
}