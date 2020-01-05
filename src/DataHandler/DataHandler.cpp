/**
 * @author Carolin Schindler
 */

#include <string>
#include "DataHandler.h"
#include "../Model/Board.h"

//TODO: COMPLETE IMPL

std::string DataHandler::getUserId() {
    return std::__cxx11::string();
}

std::string DataHandler::getUserName() {
    return std::__cxx11::string();
}

std::string DataHandler::getLobbyId() {
    return std::__cxx11::string();
}

std::string DataHandler::getGameId() {
    return std::__cxx11::string();
}

bool DataHandler::isConnected() {
    return false;
}

void DataHandler::setUserName(std::string userName) {

}

bool DataHandler::isGameStartable() {
    return false;
}

std::list <std::string> DataHandler::getJoinableLobbyNames() {
    return std::list<std::string>();
}

std::string DataHandler::getLobbyId(std::string lobbyName) {
    return std::__cxx11::string();
}

std::list <std::string> DataHandler::getLobbyStrings() {
    return std::list<std::string>();
}

std::list <std::string> DataHandler::getGameStrings() {
    return std::list<std::string>();
}

std::list<bool> DataHandler::getGameBooleans() {
    return std::list<bool>();
}

std::list <TileEnum> DataHandler::getLastMove() {
    return std::list<TileEnum>();
}

ModelBoard::Board DataHandler::getBoard() {
    return ModelBoard::Board();
}

bool DataHandler::isMoveValid(TileEnum moveFrom, TileEnum moveTo) {
    return false;
}

std::list <TileEnum> DataHandler::getNeighbours(std::list <TileEnum> kacheln) {
    return std::list<TileEnum>();
}
