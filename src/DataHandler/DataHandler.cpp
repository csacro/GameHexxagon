/**
 * @author Carolin Schindler
 */

#include <string>
#include "DataHandler.h"
#include "../Model/Board.h"


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
    //TODO: winner / turn logic
    return std::list<bool>();
}

std::list <TileEnum> DataHandler::getLastMove() {
    return {mGame.lastMoveFrom, mGame.lastMoveTo};
}

ModelBoard::Board DataHandler::getBoard() {
    return mGame.board;
}

bool DataHandler::isMoveValid(TileEnum moveFrom, TileEnum moveTo) {
    //TODO: isMoveValid for spielfeld
    return false;
}

std::list <TileEnum> DataHandler::getNeighbours(std::list <TileEnum> kacheln) {
    //TODO: getNeighbours for spielfeld
    return std::list<TileEnum>();
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
