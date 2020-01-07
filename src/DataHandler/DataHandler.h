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
    std::map<TileEnum, std::list<TileEnum>> neighboursLut = {
            {TILE_1, {TILE_2, TILE_6, TILE_7}},
            {TILE_2, {TILE_1, TILE_3, TILE_7, TILE_7, TILE_8}},
            {TILE_3, {TILE_2, TILE_4, TILE_8, TILE_8, TILE_9}},
            {TILE_4, {TILE_3, TILE_5, TILE_9, TILE_9, TILE_10}},
            {TILE_5, {TILE_4, TILE_10, TILE_10, TILE_11}},
            {TILE_6, {TILE_7, TILE_1, TILE_12, TILE_13}},
            {TILE_7, {TILE_6, TILE_8, TILE_1, TILE_2, TILE_13, TILE_14}},
            {TILE_8, {TILE_7, TILE_9, TILE_2, TILE_3, TILE_14, TILE_15}},
            {TILE_9, {TILE_8, TILE_10, TILE_3, TILE_4, TILE_15, TILE_16}},
            {TILE_10, {TILE_9, TILE_11, TILE_4, TILE_5, TILE_16, TILE_17}},
            {TILE_11, {TILE_10, TILE_5, TILE_17, TILE_18}},
            {TILE_12, {TILE_13, TILE_6, TILE_19, TILE_20}},
            {TILE_13, {TILE_12, TILE_14, TILE_6, TILE_7, TILE_20, TILE_21}},
            {TILE_14, {TILE_13, TILE_15, TILE_7, TILE_8, TILE_21, TILE_22}},
            {TILE_15, {TILE_14, TILE_16, TILE_8, TILE_9, TILE_22, TILE_23}},
            {TILE_16, {TILE_15, TILE_17, TILE_9, TILE_10, TILE_23, TILE_24}},
            {TILE_17, {TILE_16, TILE_18, TILE_10, TILE_11, TILE_24, TILE_25}},
            {TILE_18, {TILE_17, TILE_11, TILE_25, TILE_26}},
            {TILE_19, {TILE_20, TILE_12, TILE_27, TILE_28}},
            {TILE_20, {TILE_19, TILE_21, TILE_12, TILE_13, TILE_28, TILE_29}},
            {TILE_21, {TILE_20, TILE_22, TILE_13, TILE_14, TILE_29, TILE_30}},
            {TILE_22, {TILE_21, TILE_23, TILE_14, TILE_15, TILE_30, TILE_31}},
            {TILE_23, {TILE_22, TILE_24, TILE_15, TILE_16, TILE_31, TILE_32}},
            {TILE_24, {TILE_23, TILE_25, TILE_16, TILE_17, TILE_32, TILE_33}},
            {TILE_25, {TILE_24, TILE_26, TILE_17, TILE_18, TILE_33, TILE_34}},
            {TILE_26, {TILE_25, TILE_18, TILE_34, TILE_35}},
            {TILE_27, {TILE_28, TILE_19, TILE_36}},
            {TILE_28, {TILE_27, TILE_29, TILE_19, TILE_20, TILE_36, TILE_37}},
            {TILE_29, {TILE_28, TILE_30, TILE_20, TILE_21, TILE_37, TILE_38}},
            {TILE_30, {TILE_29, TILE_31, TILE_21, TILE_22, TILE_38, TILE_39}},
            {TILE_31, {TILE_30, TILE_32, TILE_22, TILE_23, TILE_39, TILE_40}},
            {TILE_32, {TILE_31, TILE_33, TILE_23, TILE_24, TILE_40, TILE_41}},
            {TILE_33, {TILE_32, TILE_34, TILE_24, TILE_25, TILE_41, TILE_42}},
            {TILE_34, {TILE_33, TILE_35, TILE_25, TILE_26, TILE_42, TILE_43}},
            {TILE_35, {TILE_34, TILE_26, TILE_43}},
            {TILE_36, {TILE_37, TILE_27, TILE_28, TILE_44}},
            {TILE_37, {TILE_36, TILE_38, TILE_28, TILE_29, TILE_44, TILE_45}},
            {TILE_38, {TILE_37, TILE_39, TILE_29, TILE_30, TILE_45, TILE_46}},
            {TILE_39, {TILE_38, TILE_40, TILE_30, TILE_31, TILE_46, TILE_47}},
            {TILE_40, {TILE_39, TILE_41, TILE_31, TILE_32, TILE_47, TILE_48}},
            {TILE_41, {TILE_40, TILE_42, TILE_32, TILE_33, TILE_48, TILE_49}},
            {TILE_42, {TILE_41, TILE_43, TILE_33, TILE_34, TILE_49, TILE_50}},
            {TILE_43, {TILE_42, TILE_34, TILE_35, TILE_50}},
            {TILE_44, {TILE_45, TILE_36, TILE_37, TILE_51}},
            {TILE_45, {TILE_44, TILE_46, TILE_37, TILE_38, TILE_51, TILE_52}},
            {TILE_46, {TILE_45, TILE_47, TILE_38, TILE_39, TILE_52, TILE_53}},
            {TILE_47, {TILE_46, TILE_48, TILE_39, TILE_40, TILE_53, TILE_54}},
            {TILE_48, {TILE_47, TILE_49, TILE_40, TILE_41, TILE_54, TILE_55}},
            {TILE_49, {TILE_48, TILE_50, TILE_41, TILE_42, TILE_55, TILE_56}},
            {TILE_50, {TILE_49, TILE_42, TILE_43, TILE_56}},
            {TILE_51, {TILE_52, TILE_44, TILE_45, TILE_57}},
            {TILE_52, {TILE_51, TILE_53, TILE_45, TILE_46, TILE_57, TILE_58}},
            {TILE_53, {TILE_52, TILE_54, TILE_46, TILE_47, TILE_58, TILE_59}},
            {TILE_54, {TILE_53, TILE_55, TILE_47, TILE_48, TILE_59, TILE_60}},
            {TILE_55, {TILE_54, TILE_56, TILE_48, TILE_49, TILE_60, TILE_61}},
            {TILE_56, {TILE_55, TILE_49, TILE_50, TILE_61}},
            {TILE_57, {TILE_58, TILE_51, TILE_52}},
            {TILE_58, {TILE_57, TILE_59, TILE_52, TILE_53}},
            {TILE_59, {TILE_58, TILE_60, TILE_53, TILE_54}},
            {TILE_60, {TILE_59, TILE_61, TILE_54, TILE_55}},
            {TILE_61, {TILE_60, TILE_55, TILE_56}},
    };

    /**
     * helper function to find out if move to tileEnum is possible
     * @param tileEnum TileEnum to be checked
     * @return bool true if tileEnum is FREE
     */
    bool isMoveToPossible(TileEnum tileEnum);

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
