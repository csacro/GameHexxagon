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
    //to fix bug in server (not telling winner but changing state) -> should be done in server
    if(mGame.playerOnePoints == 0) {
        return {false, mUser.userId != mGame.playerOne};
    }
    if(mGame.playerTwoPoints == 0) {
        return {false, mUser.userId != mGame.playerTwo};
    }
    if(mGame.playerOnePoints + mGame.playerTwoPoints == 61-8) {
        if(mGame.playerOnePoints > mGame.playerTwoPoints) {
            return {false, mUser.userId == mGame.playerOne};
        }
        if(mGame.playerOnePoints < mGame.playerTwoPoints) {
            return {false, mUser.userId == mGame.playerTwo};
        }
        return {true, false};
    }
    //to fix bug in server (not telling winner but changing state) -> should be done in server

    if(mGame.tie) {
        return {true, false};
    }
    if(!mGame.winner.empty()) {
        return {false, mUser.userId == mGame.winner};
    }
    return {mUser.userId == mGame.activePlayer};
}

std::list <ModelTileEnum::TileEnum> DataHandler::getLastMove() {
    return {mGame.lastMoveFrom, mGame.lastMoveTo};
}

ModelBoard::Board DataHandler::getBoard() {
    return mGame.board;
}

bool DataHandler::isMoveValid(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo) {
    if(isMoveFromPossible(moveFrom)) {
        std::list<ModelTileEnum::TileEnum> direct = getValidDirectNeighbours(moveFrom);
        for(ModelTileEnum::TileEnum &tileEnumDirect: direct) {
            if(moveTo == tileEnumDirect) {
                return true;
            }
        }
        std::list<ModelTileEnum::TileEnum> secondary = getValidSecondaryNeighbours(moveFrom);
        for(ModelTileEnum::TileEnum &tileEnumSecondary: secondary) {
            if(moveTo == tileEnumSecondary) {
                return true;
            }
        }
    }
    return false;
}

bool DataHandler::isMoveFromPossible(ModelTileEnum::TileEnum moveFrom) {
    ModelTileStateEnum::TileStateEnum myStone = ModelTileStateEnum::PLAYERTWO;
    if(mUser.userId == mGame.playerOne) {
        myStone = ModelTileStateEnum::PLAYERONE;
    }
    return mGame.board.tiles.at(moveFrom) == myStone && mUser.userId == mGame.activePlayer;
}

std::list<ModelTileEnum::TileEnum> DataHandler::getValidDirectNeighbours(ModelTileEnum::TileEnum kachel) {
    std::list<ModelTileEnum::TileEnum> ret;
    std::list<ModelTileEnum::TileEnum> directNeighbours = neighboursLut.at(kachel);
    for(auto it = directNeighbours.begin(); it != directNeighbours.end(); it++) {
        if(isMoveToPossible(*it)) {
            ret.push_back(*it);
        }
    }
    return ret;
}

std::list<ModelTileEnum::TileEnum> DataHandler::getValidSecondaryNeighbours(ModelTileEnum::TileEnum kachel) {
    std::list<ModelTileEnum::TileEnum> ret;
    std::list<ModelTileEnum::TileEnum> directNeighbours = neighboursLut.at(kachel);
    std::list<ModelTileEnum::TileEnum> secondaryNeighbours;
    for(ModelTileEnum::TileEnum &te: directNeighbours) {
        secondaryNeighbours = neighboursLut.at(te);
        for(auto it = secondaryNeighbours.begin(); it != secondaryNeighbours.end(); it++) {
            if(isMoveToPossible(*it) && std::find(directNeighbours.begin(), directNeighbours.end(), *it) == directNeighbours.end()) {
                ret.push_back(*it);
            }
        }
    }

    return ret;
}

bool DataHandler::isMoveToPossible(ModelTileEnum::TileEnum tileEnum) {
    return mGame.board.tiles.at(tileEnum) == ModelTileStateEnum::FREE && mUser.userId == mGame.activePlayer;
}


void DataHandler::setUserId(std::string userId) {
    mUser.isConnected = !userId.empty();
    mUser.userId = userId;
    if(mToView != NULL) {
        mToView->infoConnected(mUser.isConnected);
    }
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
