/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_DATAHANDLER_H
#define GAMEHEXXAGON_DATAHANDLER_H


#include "ViewToData.h"

class DataHandler: public ViewToData {
//TODO: COMPLETE CLASS

public:
    std::string getUserId() override;

    std::string getUserName() override;

    std::string getLobbyId() override;

    std::string getGameId() override;

    bool isConnected() override;

    void setUserName(std::string userName) override;

    bool isGameStartable() override;

    std::list<std::string> getJoinableLobbyNames() override;

    std::string getLobbyId(std::string lobbyName) override;

    std::list<std::string> getLobbyStrings() override;

    std::list<std::string> getGameStrings() override;

    std::list<bool> getGameBooleans() override;

    std::list<TileEnum> getLastMove() override;

    ModelBoard::Board getBoard() override;

    bool isMoveValid(TileEnum moveFrom, TileEnum moveTo) override;

    std::list<TileEnum> getNeighbours(std::list<TileEnum> kacheln) override;
};


#endif //GAMEHEXXAGON_DATAHANDLER_H
