/**
 * @author Carolin Schindler
 */

#include <string>
#include "DataHandler.h"


DataHandler::DataHandler(DataToView &dtv) {
    mToView = &dtv;
}


std::string DataHandler::getUserId() {
    return mUser.userId;
}

std::string DataHandler::getUserName() {
    return mUser.userName;
}

std::string DataHandler::getLobbyId() {
    return mLobby.lobbyId;
}

std::string DataHandler::getGameId() {
    return mGame.gameId;
}

bool DataHandler::isConnected() {
    return mUser.isConnected;
}

void DataHandler::setUserName(std::string userName) {
    mUser.userName = userName;
}

bool DataHandler::isGameStartable() {
    return mUser.userId == mLobby.playerOne && !mLobby.playerTwo.empty();
}

std::list<std::string> DataHandler::getJoinableLobbyNames() {
    std::list<std::string> joinableLobbies;
    for(auto it = mAvailableLobbies.begin(); it != mAvailableLobbies.end(); it++) {
        if(!it->isClosed) {
            joinableLobbies.push_back(it->lobbyName);
        }
    }
    return joinableLobbies;
}

std::string DataHandler::getLobbyId(std::string lobbyName) {
    for(auto it = mAvailableLobbies.begin(); it != mAvailableLobbies.end(); it++) {
        if(it->lobbyName == lobbyName) {
            return it->lobbyId;
        }
    }
    return "";
}

std::list <std::string> DataHandler::getLobbyStrings() {
    return {mLobby.lobbyName, mLobby.playerOneUserName, mLobby.playerTwoUserName};
}

std::list <std::string> DataHandler::getGameStrings() {
    return {std::to_string(mGame.playerOnePoints), std::to_string(mGame.playerTwoPoints)};
}

std::list<bool> DataHandler::getGameBooleans() {
    if(mGame.tie) {
        return {true, false};
    }
    if(!mGame.winner.empty()) {
        return {false, mUser.userId == mGame.winner};
    }
    return {mUser.userId == mGame.activePlayer};
}

std::list <TileEnum> DataHandler::getLastMove() {
    return {mGame.lastMoveFrom, mGame.lastMoveTo};
}

ModelBoard::Board DataHandler::getBoard() {
    return mGame.board;
}

bool DataHandler::isMoveValid(TileEnum moveFrom, TileEnum moveTo) {
    if(isMoveFromPossible(moveFrom)) {
        std::list<TileEnum> direct = getValidDirectNeighbours(moveTo);
        for(TileEnum &tileEnum: direct) {
            if(moveTo == tileEnum) {
                return true;
            }
        }
        std::list<TileEnum> secondary = getValidSecondaryNeighbours(moveTo);
        for(TileEnum &tileEnum: secondary) {
            if(moveTo == tileEnum) {
                return true;
            }
        }
    }
    return false;
}

bool DataHandler::isMoveFromPossible(TileEnum moveFrom) {
    ModelBoard::Board curBoard = mGame.board;
    TileStateEnum myStone = PLAYERTWO;
    if(mUser.userId == mGame.playerOne) {
        myStone = PLAYERONE;
    }
    return curBoard.tiles.at(moveFrom) == myStone && mUser.userId == mGame.activePlayer;
}

std::list<TileEnum> DataHandler::getValidDirectNeighbours(TileEnum kachel) {
    std::list<TileEnum> directNeighbours = neighboursLut.at(kachel);
    for(auto it = directNeighbours.begin(); it != directNeighbours.end(); it++) {
        if(!isMoveToPossible(*it)) {
            directNeighbours.erase(it);
        }
    }
    return directNeighbours;
}

std::list<TileEnum> DataHandler::getValidSecondaryNeighbours(TileEnum kachel) {
    auto directNeighbours = neighboursLut.at(kachel);
    std::list<TileEnum> secondaryNeighbours;
    for(TileEnum te: directNeighbours) {
        secondaryNeighbours.splice(secondaryNeighbours.end(), neighboursLut.at(te));
    }
    for(auto it = secondaryNeighbours.begin(); it != secondaryNeighbours.end(); it++) {
        if(!isMoveToPossible(*it) || std::find(directNeighbours.begin(), directNeighbours.end(), *it) != directNeighbours.end()) {
            secondaryNeighbours.erase(it);
        }
    }
    return std::list<TileEnum>();
}

bool DataHandler::isMoveToPossible(TileEnum tileEnum) {
    ModelBoard::Board b = mGame.board;
    return b.tiles.at(tileEnum) == FREE;
}


void DataHandler::setUserId(std::string userId) {
    mUser.userId = userId;
    mToView->infoConnected(!userId.empty());
}

void DataHandler::forwardAvailableLobbies(std::list<ModelLobby::Lobby> lobbies) {
    mAvailableLobbies = lobbies;
    mToView->gotAvailableLobbies();
}

void DataHandler::infoLobbyCreated(std::string lobbyId, bool success) {
    if(success) {
        mLobby.lobbyId = lobbyId;
    }
    mToView->infoLobbyCreated(success);
}

void DataHandler::infoLobbyJoined(bool success) {
    mToView->infoLobbyJoined(success);
}

void DataHandler::forwardLobbyStatus(ModelLobby::Lobby lobby) {
    mLobby = lobby;
    mToView->gotLobbyStatus();
}

void DataHandler::infoGameStarted() {
    mToView->infoGameStarted();
}

void DataHandler::forwardGameStatus(ModelGame::Game game) {
    mGame = game;
    mToView->gotGameStatus();
}
