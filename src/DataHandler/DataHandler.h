/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_DATAHANDLER_H
#define GAMEHEXXAGON_DATAHANDLER_H


#include <list>
#include "ViewToData.h"
#include "ClientToData.h"
#include "../ViewHandler/DataToView.h"
#include "../Model/Game.h"
#include "../Model/User.h"

class DataHandler: public ViewToData, public ClientToData {
private:
    DataToView *mToView; //interface to ViewHandler

    //storage of data for user
    User mUser;
    std::list<ModelLobby::Lobby> mAvailableLobbies;
    ModelLobby::Lobby mLobby;
    ModelGame::Game mGame;

    //look up table for direct neighbours
    std::map<TileEnum, std::list<TileEnum>> neighboursLut;
    //TODO: neighbours (fill lut)

public:
    /**
     * default Constructor
     */
    DataHandler() = default;

    /**
     * Constructor
     * @param dtv DataToView to communicate with ViewHandler
     */
    DataHandler(DataToView &dtv);

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

    void setUserId(std::string userId) override;

    void forwardAvailableLobbies(std::list<ModelLobby::Lobby> lobbies) override;

    void infoLobbyCreated(std::string lobbyId, bool success) override;

    void infoLobbyJoined(bool success) override;

    void forwardLobbyStatus(ModelLobby::Lobby lobby) override;

    void infoGameStarted() override;

    void forwardGameStatus(ModelGame::Game game) override;

    bool isMoveFromPossible(TileEnum moveFrom) override;

    std::list<TileEnum> getValidDirectNeighbours(TileEnum kachel) override;

    std::list<TileEnum> getValidSecondaryNeighbours(TileEnum kachel) override;
};


#endif //GAMEHEXXAGON_DATAHANDLER_H
