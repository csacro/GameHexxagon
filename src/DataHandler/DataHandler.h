/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_DATAHANDLER_H
#define GAMEHEXXAGON_DATAHANDLER_H


#include <list>
#include "ViewToData.h"
#include "ClientToData.h"
#include "../ViewHandler/DataToView.h"
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
    std::map<ModelTileEnum::TileEnum, std::list<ModelTileEnum::TileEnum>> neighboursLut = {
            {ModelTileEnum::TILE_1, {ModelTileEnum::TILE_2, ModelTileEnum::TILE_6, ModelTileEnum::TILE_7}},
            {ModelTileEnum::TILE_2, {ModelTileEnum::TILE_1, ModelTileEnum::TILE_3, ModelTileEnum::TILE_7, ModelTileEnum::TILE_7, ModelTileEnum::TILE_8}},
            {ModelTileEnum::TILE_3, {ModelTileEnum::TILE_2, ModelTileEnum::TILE_4, ModelTileEnum::TILE_8, ModelTileEnum::TILE_8, ModelTileEnum::TILE_9}},
            {ModelTileEnum::TILE_4, {ModelTileEnum::TILE_3, ModelTileEnum::TILE_5, ModelTileEnum::TILE_9, ModelTileEnum::TILE_9, ModelTileEnum::TILE_10}},
            {ModelTileEnum::TILE_5, {ModelTileEnum::TILE_4, ModelTileEnum::TILE_10, ModelTileEnum::TILE_10, ModelTileEnum::TILE_11}},
            {ModelTileEnum::TILE_6, {ModelTileEnum::TILE_7, ModelTileEnum::TILE_1, ModelTileEnum::TILE_12, ModelTileEnum::TILE_13}},
            {ModelTileEnum::TILE_7, {ModelTileEnum::TILE_6, ModelTileEnum::TILE_8, ModelTileEnum::TILE_1, ModelTileEnum::TILE_2, ModelTileEnum::TILE_13, ModelTileEnum::TILE_14}},
            {ModelTileEnum::TILE_8, {ModelTileEnum::TILE_7, ModelTileEnum::TILE_9, ModelTileEnum::TILE_2, ModelTileEnum::TILE_3, ModelTileEnum::TILE_14, ModelTileEnum::TILE_15}},
            {ModelTileEnum::TILE_9, {ModelTileEnum::TILE_8, ModelTileEnum::TILE_10, ModelTileEnum::TILE_3, ModelTileEnum::TILE_4, ModelTileEnum::TILE_15, ModelTileEnum::TILE_16}},
            {ModelTileEnum::TILE_10, {ModelTileEnum::TILE_9, ModelTileEnum::TILE_11, ModelTileEnum::TILE_4, ModelTileEnum::TILE_5, ModelTileEnum::TILE_16, ModelTileEnum::TILE_17}},
            {ModelTileEnum::TILE_11, {ModelTileEnum::TILE_10, ModelTileEnum::TILE_5, ModelTileEnum::TILE_17, ModelTileEnum::TILE_18}},
            {ModelTileEnum::TILE_12, {ModelTileEnum::TILE_13, ModelTileEnum::TILE_6, ModelTileEnum::TILE_19, ModelTileEnum::TILE_20}},
            {ModelTileEnum::TILE_13, {ModelTileEnum::TILE_12, ModelTileEnum::TILE_14, ModelTileEnum::TILE_6, ModelTileEnum::TILE_7, ModelTileEnum::TILE_20, ModelTileEnum::TILE_21}},
            {ModelTileEnum::TILE_14, {ModelTileEnum::TILE_13, ModelTileEnum::TILE_15, ModelTileEnum::TILE_7, ModelTileEnum::TILE_8, ModelTileEnum::TILE_21, ModelTileEnum::TILE_22}},
            {ModelTileEnum::TILE_15, {ModelTileEnum::TILE_14, ModelTileEnum::TILE_16, ModelTileEnum::TILE_8, ModelTileEnum::TILE_9, ModelTileEnum::TILE_22, ModelTileEnum::TILE_23}},
            {ModelTileEnum::TILE_16, {ModelTileEnum::TILE_15, ModelTileEnum::TILE_17, ModelTileEnum::TILE_9, ModelTileEnum::TILE_10, ModelTileEnum::TILE_23, ModelTileEnum::TILE_24}},
            {ModelTileEnum::TILE_17, {ModelTileEnum::TILE_16, ModelTileEnum::TILE_18, ModelTileEnum::TILE_10, ModelTileEnum::TILE_11, ModelTileEnum::TILE_24, ModelTileEnum::TILE_25}},
            {ModelTileEnum::TILE_18, {ModelTileEnum::TILE_17, ModelTileEnum::TILE_11, ModelTileEnum::TILE_25, ModelTileEnum::TILE_26}},
            {ModelTileEnum::TILE_19, {ModelTileEnum::TILE_20, ModelTileEnum::TILE_12, ModelTileEnum::TILE_27, ModelTileEnum::TILE_28}},
            {ModelTileEnum::TILE_20, {ModelTileEnum::TILE_19, ModelTileEnum::TILE_21, ModelTileEnum::TILE_12, ModelTileEnum::TILE_13, ModelTileEnum::TILE_28, ModelTileEnum::TILE_29}},
            {ModelTileEnum::TILE_21, {ModelTileEnum::TILE_20, ModelTileEnum::TILE_22, ModelTileEnum::TILE_13, ModelTileEnum::TILE_14, ModelTileEnum::TILE_29, ModelTileEnum::TILE_30}},
            {ModelTileEnum::TILE_22, {ModelTileEnum::TILE_21, ModelTileEnum::TILE_23, ModelTileEnum::TILE_14, ModelTileEnum::TILE_15, ModelTileEnum::TILE_30, ModelTileEnum::TILE_31}},
            {ModelTileEnum::TILE_23, {ModelTileEnum::TILE_22, ModelTileEnum::TILE_24, ModelTileEnum::TILE_15, ModelTileEnum::TILE_16, ModelTileEnum::TILE_31, ModelTileEnum::TILE_32}},
            {ModelTileEnum::TILE_24, {ModelTileEnum::TILE_23, ModelTileEnum::TILE_25, ModelTileEnum::TILE_16, ModelTileEnum::TILE_17, ModelTileEnum::TILE_32, ModelTileEnum::TILE_33}},
            {ModelTileEnum::TILE_25, {ModelTileEnum::TILE_24, ModelTileEnum::TILE_26, ModelTileEnum::TILE_17, ModelTileEnum::TILE_18, ModelTileEnum::TILE_33, ModelTileEnum::TILE_34}},
            {ModelTileEnum::TILE_26, {ModelTileEnum::TILE_25, ModelTileEnum::TILE_18, ModelTileEnum::TILE_34, ModelTileEnum::TILE_35}},
            {ModelTileEnum::TILE_27, {ModelTileEnum::TILE_28, ModelTileEnum::TILE_19, ModelTileEnum::TILE_36}},
            {ModelTileEnum::TILE_28, {ModelTileEnum::TILE_27, ModelTileEnum::TILE_29, ModelTileEnum::TILE_19, ModelTileEnum::TILE_20, ModelTileEnum::TILE_36, ModelTileEnum::TILE_37}},
            {ModelTileEnum::TILE_29, {ModelTileEnum::TILE_28, ModelTileEnum::TILE_30, ModelTileEnum::TILE_20, ModelTileEnum::TILE_21, ModelTileEnum::TILE_37, ModelTileEnum::TILE_38}},
            {ModelTileEnum::TILE_30, {ModelTileEnum::TILE_29, ModelTileEnum::TILE_31, ModelTileEnum::TILE_21, ModelTileEnum::TILE_22, ModelTileEnum::TILE_38, ModelTileEnum::TILE_39}},
            {ModelTileEnum::TILE_31, {ModelTileEnum::TILE_30, ModelTileEnum::TILE_32, ModelTileEnum::TILE_22, ModelTileEnum::TILE_23, ModelTileEnum::TILE_39, ModelTileEnum::TILE_40}},
            {ModelTileEnum::TILE_32, {ModelTileEnum::TILE_31, ModelTileEnum::TILE_33, ModelTileEnum::TILE_23, ModelTileEnum::TILE_24, ModelTileEnum::TILE_40, ModelTileEnum::TILE_41}},
            {ModelTileEnum::TILE_33, {ModelTileEnum::TILE_32, ModelTileEnum::TILE_34, ModelTileEnum::TILE_24, ModelTileEnum::TILE_25, ModelTileEnum::TILE_41, ModelTileEnum::TILE_42}},
            {ModelTileEnum::TILE_34, {ModelTileEnum::TILE_33, ModelTileEnum::TILE_35, ModelTileEnum::TILE_25, ModelTileEnum::TILE_26, ModelTileEnum::TILE_42, ModelTileEnum::TILE_43}},
            {ModelTileEnum::TILE_35, {ModelTileEnum::TILE_34, ModelTileEnum::TILE_26, ModelTileEnum::TILE_43}},
            {ModelTileEnum::TILE_36, {ModelTileEnum::TILE_37, ModelTileEnum::TILE_27, ModelTileEnum::TILE_28, ModelTileEnum::TILE_44}},
            {ModelTileEnum::TILE_37, {ModelTileEnum::TILE_36, ModelTileEnum::TILE_38, ModelTileEnum::TILE_28, ModelTileEnum::TILE_29, ModelTileEnum::TILE_44, ModelTileEnum::TILE_45}},
            {ModelTileEnum::TILE_38, {ModelTileEnum::TILE_37, ModelTileEnum::TILE_39, ModelTileEnum::TILE_29, ModelTileEnum::TILE_30, ModelTileEnum::TILE_45, ModelTileEnum::TILE_46}},
            {ModelTileEnum::TILE_39, {ModelTileEnum::TILE_38, ModelTileEnum::TILE_40, ModelTileEnum::TILE_30, ModelTileEnum::TILE_31, ModelTileEnum::TILE_46, ModelTileEnum::TILE_47}},
            {ModelTileEnum::TILE_40, {ModelTileEnum::TILE_39, ModelTileEnum::TILE_41, ModelTileEnum::TILE_31, ModelTileEnum::TILE_32, ModelTileEnum::TILE_47, ModelTileEnum::TILE_48}},
            {ModelTileEnum::TILE_41, {ModelTileEnum::TILE_40, ModelTileEnum::TILE_42, ModelTileEnum::TILE_32, ModelTileEnum::TILE_33, ModelTileEnum::TILE_48, ModelTileEnum::TILE_49}},
            {ModelTileEnum::TILE_42, {ModelTileEnum::TILE_41, ModelTileEnum::TILE_43, ModelTileEnum::TILE_33, ModelTileEnum::TILE_34, ModelTileEnum::TILE_49, ModelTileEnum::TILE_50}},
            {ModelTileEnum::TILE_43, {ModelTileEnum::TILE_42, ModelTileEnum::TILE_34, ModelTileEnum::TILE_35, ModelTileEnum::TILE_50}},
            {ModelTileEnum::TILE_44, {ModelTileEnum::TILE_45, ModelTileEnum::TILE_36, ModelTileEnum::TILE_37, ModelTileEnum::TILE_51}},
            {ModelTileEnum::TILE_45, {ModelTileEnum::TILE_44, ModelTileEnum::TILE_46, ModelTileEnum::TILE_37, ModelTileEnum::TILE_38, ModelTileEnum::TILE_51, ModelTileEnum::TILE_52}},
            {ModelTileEnum::TILE_46, {ModelTileEnum::TILE_45, ModelTileEnum::TILE_47, ModelTileEnum::TILE_38, ModelTileEnum::TILE_39, ModelTileEnum::TILE_52, ModelTileEnum::TILE_53}},
            {ModelTileEnum::TILE_47, {ModelTileEnum::TILE_46, ModelTileEnum::TILE_48, ModelTileEnum::TILE_39, ModelTileEnum::TILE_40, ModelTileEnum::TILE_53, ModelTileEnum::TILE_54}},
            {ModelTileEnum::TILE_48, {ModelTileEnum::TILE_47, ModelTileEnum::TILE_49, ModelTileEnum::TILE_40, ModelTileEnum::TILE_41, ModelTileEnum::TILE_54, ModelTileEnum::TILE_55}},
            {ModelTileEnum::TILE_49, {ModelTileEnum::TILE_48, ModelTileEnum::TILE_50, ModelTileEnum::TILE_41, ModelTileEnum::TILE_42, ModelTileEnum::TILE_55, ModelTileEnum::TILE_56}},
            {ModelTileEnum::TILE_50, {ModelTileEnum::TILE_49, ModelTileEnum::TILE_42, ModelTileEnum::TILE_43, ModelTileEnum::TILE_56}},
            {ModelTileEnum::TILE_51, {ModelTileEnum::TILE_52, ModelTileEnum::TILE_44, ModelTileEnum::TILE_45, ModelTileEnum::TILE_57}},
            {ModelTileEnum::TILE_52, {ModelTileEnum::TILE_51, ModelTileEnum::TILE_53, ModelTileEnum::TILE_45, ModelTileEnum::TILE_46, ModelTileEnum::TILE_57, ModelTileEnum::TILE_58}},
            {ModelTileEnum::TILE_53, {ModelTileEnum::TILE_52, ModelTileEnum::TILE_54, ModelTileEnum::TILE_46, ModelTileEnum::TILE_47, ModelTileEnum::TILE_58, ModelTileEnum::TILE_59}},
            {ModelTileEnum::TILE_54, {ModelTileEnum::TILE_53, ModelTileEnum::TILE_55, ModelTileEnum::TILE_47, ModelTileEnum::TILE_48, ModelTileEnum::TILE_59, ModelTileEnum::TILE_60}},
            {ModelTileEnum::TILE_55, {ModelTileEnum::TILE_54, ModelTileEnum::TILE_56, ModelTileEnum::TILE_48, ModelTileEnum::TILE_49, ModelTileEnum::TILE_60, ModelTileEnum::TILE_61}},
            {ModelTileEnum::TILE_56, {ModelTileEnum::TILE_55, ModelTileEnum::TILE_49, ModelTileEnum::TILE_50, ModelTileEnum::TILE_61}},
            {ModelTileEnum::TILE_57, {ModelTileEnum::TILE_58, ModelTileEnum::TILE_51, ModelTileEnum::TILE_52}},
            {ModelTileEnum::TILE_58, {ModelTileEnum::TILE_57, ModelTileEnum::TILE_59, ModelTileEnum::TILE_52, ModelTileEnum::TILE_53}},
            {ModelTileEnum::TILE_59, {ModelTileEnum::TILE_58, ModelTileEnum::TILE_60, ModelTileEnum::TILE_53, ModelTileEnum::TILE_54}},
            {ModelTileEnum::TILE_60, {ModelTileEnum::TILE_59, ModelTileEnum::TILE_61, ModelTileEnum::TILE_54, ModelTileEnum::TILE_55}},
            {ModelTileEnum::TILE_61, {ModelTileEnum::TILE_60, ModelTileEnum::TILE_55, ModelTileEnum::TILE_56}},
    };

    /**
     * helper function to find out if move to tileEnum is possible
     * @param tileEnum TileEnum to be checked
     * @return bool true if tileEnum is FREE
     */
    bool isMoveToPossible(ModelTileEnum::TileEnum tileEnum);

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

    std::list<ModelTileEnum::TileEnum> getLastMove() override;

    ModelBoard::Board getBoard() override;

    bool isMoveValid(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo) override;

    void setUserId(std::string userId) override;

    void forwardAvailableLobbies(std::list<ModelLobby::Lobby> lobbies) override;

    void infoLobbyCreated(std::string lobbyId, bool success) override;

    void infoLobbyJoined(bool success) override;

    void forwardLobbyStatus(ModelLobby::Lobby lobby) override;

    void infoGameStarted() override;

    void forwardGameStatus(ModelGame::Game game) override;

    bool isMoveFromPossible(ModelTileEnum::TileEnum moveFrom) override;

    std::list<ModelTileEnum::TileEnum> getValidDirectNeighbours(ModelTileEnum::TileEnum kachel) override;

    std::list<ModelTileEnum::TileEnum> getValidSecondaryNeighbours(ModelTileEnum::TileEnum kachel) override;
};


#endif //GAMEHEXXAGON_DATAHANDLER_H
