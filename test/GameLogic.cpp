/**
 * @author Carolin Schindler
 */

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../src/Client/Client.h"
#include "../src/DataHandler/DataHandler.h"


TEST(DataHandler, getUserId) {
    DataHandler d;
    std::string id = "asdf123456";

    EXPECT_EQ("", d.getUserId());
    d.setUserId(id);
    EXPECT_EQ(id, d.getUserId());
}

TEST(DataHandler, getUserName) {
    DataHandler d;
    std::string name = "asdf123456";

    EXPECT_EQ("", d.getUserName());
    d.setUserName(name);
    EXPECT_EQ(name, d.getUserName());
}

TEST(DataHandler, isConnectd) {
    DataHandler d;

    EXPECT_FALSE(d.isConnected());
    d.setUserId("someId");
    EXPECT_TRUE(d.isConnected());
    d.setUserId("");
    EXPECT_FALSE(d.isConnected());
}

ModelLobby::Lobby twoPlayerOne = {"twoPlayerOne", "twoPlayerOneName", "playerOneID", "playerTwoID", "Player1", "Player2", false};
ModelLobby::Lobby twoPlayerTwo = {"twoPlayerOne", "twoPlayerTwoName", "playerTwoID", "playerOneID", "Player2", "Player1", true};
ModelLobby::Lobby onePlayerOne = {"onePlayerOne", "onePlayerOneName", "playerOneID", "", "PlayerOneUserName", "", false};
ModelLobby::Lobby onePlayerClosed = {"onePlayerClosed", "onePlayerClosedName", "playerOneID", "", "PlayerOneUserName", "", true};

TEST(DataHandler, getLobbyId) {
    DataHandler d;

    EXPECT_EQ("", d.getLobbyId());
    d.forwardLobbyStatus(onePlayerOne);
    EXPECT_EQ(onePlayerOne.lobbyId, d.getLobbyId());
    d.forwardLobbyStatus(twoPlayerTwo);
    EXPECT_EQ(twoPlayerTwo.lobbyId, d.getLobbyId());
    d.forwardLobbyStatus(twoPlayerOne);
    EXPECT_EQ(twoPlayerOne.lobbyId, d.getLobbyId());
}

TEST(DataHandler, getLobbyStrings) {
    DataHandler d;

    EXPECT_THAT(d.getLobbyStrings(), testing::ElementsAreArray({"", "", ""}));
    d.forwardLobbyStatus(onePlayerOne);
    EXPECT_THAT(d.getLobbyStrings(), testing::ElementsAreArray({onePlayerOne.lobbyName, onePlayerOne.playerOneUserName, onePlayerOne.playerTwoUserName}));
    d.forwardLobbyStatus(twoPlayerTwo);
    EXPECT_THAT(d.getLobbyStrings(), testing::ElementsAreArray({twoPlayerTwo.lobbyName, twoPlayerTwo.playerOneUserName, twoPlayerTwo.playerTwoUserName}));
    d.forwardLobbyStatus(twoPlayerOne);
    EXPECT_THAT(d.getLobbyStrings(), testing::ElementsAreArray({twoPlayerOne.lobbyName, twoPlayerOne.playerOneUserName, twoPlayerOne.playerTwoUserName}));
}

TEST(DataHandler, isGameStartable) {
    DataHandler d;
    d.setUserId(onePlayerOne.playerOne);

    EXPECT_FALSE(d.isGameStartable());
    d.forwardLobbyStatus(onePlayerOne);
    EXPECT_FALSE(d.isGameStartable());
    d.forwardLobbyStatus(twoPlayerTwo);
    EXPECT_FALSE(d.isGameStartable());
    d.forwardLobbyStatus(twoPlayerOne);
    EXPECT_TRUE(d.isGameStartable());
}

std::list<ModelLobby::Lobby> availableLobbies = {onePlayerOne, twoPlayerOne, twoPlayerTwo, onePlayerClosed};

TEST(DataHandler, getJoinableLobbyNames) {
    DataHandler d;

    EXPECT_TRUE(d.getJoinableLobbyNames().empty());
    d.forwardAvailableLobbies(availableLobbies);
    EXPECT_THAT(d.getJoinableLobbyNames(), testing::ElementsAreArray({onePlayerOne.lobbyName}));
}

TEST(DataHandler, getLobbyIdTolobbyName) {
    DataHandler d;

    EXPECT_EQ("", d.getLobbyId(""));
    d.forwardAvailableLobbies(availableLobbies);
    EXPECT_EQ("", d.getLobbyId(""));
    EXPECT_EQ(onePlayerOne.lobbyId, d.getLobbyId(onePlayerOne.lobbyName));
    EXPECT_EQ(onePlayerClosed.lobbyId, d.getLobbyId(onePlayerClosed.lobbyName));
    EXPECT_EQ(twoPlayerOne.lobbyId, d.getLobbyId(twoPlayerOne.lobbyName));
    EXPECT_EQ(twoPlayerTwo.lobbyId, d.getLobbyId(twoPlayerTwo.lobbyName));
}

ModelBoard::Board testBoard = {
    {
        {ModelTileEnum::TILE_61, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_60, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_59, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_58, ModelTileStateEnum::PLAYERONE},
        {ModelTileEnum::TILE_57, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_56, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_55, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_54, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_53, ModelTileStateEnum::PLAYERTWO},
        {ModelTileEnum::TILE_52, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_51, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_50, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_49, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_48, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_47, ModelTileStateEnum::PLAYERONE},
        {ModelTileEnum::TILE_46, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_45, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_44, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_43, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_42, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_41, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_40, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_39, ModelTileStateEnum::PLAYERONE},
        {ModelTileEnum::TILE_38, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_37, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_36, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_35, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_34, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_33, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_32, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_31, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_30, ModelTileStateEnum::PLAYERTWO},
        {ModelTileEnum::TILE_29, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_28, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_27, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_26, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_25, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_24, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_23, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_22, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_21, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_20, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_19, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_18, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_17, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_16, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_15, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_14, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_13, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_12, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_11, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_10, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_9, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_8, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_7, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_6, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_5, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_4, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_3, ModelTileStateEnum::BLOCKED},
        {ModelTileEnum::TILE_2, ModelTileStateEnum::FREE},
        {ModelTileEnum::TILE_1, ModelTileStateEnum::FREE},
    }
};
ModelGame::Game baseGame = {"gameId", "playerOne", "playerTwo", "playerOneUserName", "playerTwoUsername", false, false, 13, 8,
                            testBoard, 10, ModelTileEnum::TileEnum(5), ModelTileEnum::TileEnum(6), "playerOne", false, "", false};

TEST(DataHandler, getGameId) {
    DataHandler d;

    EXPECT_EQ("", d.getGameId());
    d.forwardGameStatus(baseGame);
    EXPECT_EQ(baseGame.gameId, d.getGameId());
}

TEST(DataHandler, getBoard) {
    DataHandler d;

    EXPECT_TRUE(d.getBoard().tiles.empty());
    d.forwardGameStatus(baseGame);
    //TODO EXPECT_EQ(baseGame.board, testBoard);
}

TEST(DataHandler, getGameStrings) {
    DataHandler d;

    EXPECT_THAT(d.getGameStrings(), testing::ElementsAreArray({"6", "6"}));
    d.forwardGameStatus(baseGame);
    EXPECT_THAT(d.getGameStrings(), testing::ElementsAreArray({std::to_string(baseGame.playerOnePoints), std::to_string(baseGame.playerTwoPoints)}));
}

TEST(DataHandler, getGameBooleans) {
    DataHandler d;

    EXPECT_THAT(d.getGameBooleans(), testing::ElementsAreArray({true}));
    //active player
    d.forwardGameStatus(baseGame);
    EXPECT_THAT(d.getGameBooleans(), testing::ElementsAreArray({false}));
    d.setUserId(baseGame.activePlayer);
    EXPECT_THAT(d.getGameBooleans(), testing::ElementsAreArray({true}));
    //winner, loser
    baseGame.winner = "notyou";
    d.forwardGameStatus(baseGame);
    EXPECT_THAT(d.getGameBooleans(), testing::ElementsAreArray({false, false}));
    baseGame.winner = baseGame.activePlayer;
    d.forwardGameStatus(baseGame);
    EXPECT_THAT(d.getGameBooleans(), testing::ElementsAreArray({false, true}));
    //tie
    baseGame.tie = true;
    d.forwardGameStatus(baseGame);
    EXPECT_THAT(d.getGameBooleans(), testing::ElementsAreArray({true, false}));
}

TEST(DataHandler, getLastMove) {
    DataHandler d;

    EXPECT_THAT(d.getLastMove(), testing::ElementsAreArray({ModelTileEnum::TILE_1, ModelTileEnum::TILE_1}));
    d.forwardGameStatus(baseGame);
    EXPECT_THAT(d.getLastMove(), testing::ElementsAreArray({baseGame.lastMoveFrom, baseGame.lastMoveTo}));
}

TEST(DataHandler, isMoveValid) {
    DataHandler d;

    d.forwardGameStatus(baseGame);
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_54));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_40));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_46));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_53));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_39));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_30));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_58));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_31));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_32));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_38));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_41));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_45));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_49));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_52));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_55));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_60));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_58, ModelTileEnum::TILE_60));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_58, ModelTileEnum::TILE_59));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_58, ModelTileEnum::TILE_7));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_53, ModelTileEnum::TILE_52));

    d.setUserId(baseGame.activePlayer);
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_54));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_40));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_46));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_53));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_39));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_30));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_58));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_31));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_32));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_38));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_41));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_45));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_49));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_52));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_55));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_47, ModelTileEnum::TILE_60));
    EXPECT_TRUE(d.isMoveValid(ModelTileEnum::TILE_58, ModelTileEnum::TILE_60));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_58, ModelTileEnum::TILE_59));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_58, ModelTileEnum::TILE_7));
    EXPECT_FALSE(d.isMoveValid(ModelTileEnum::TILE_53, ModelTileEnum::TILE_52));

}

TEST(DataHandler, isMoveFromPossible) {
    DataHandler d;

    d.forwardGameStatus(baseGame);
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_39));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_58));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_30));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_53));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_3));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_29));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_9));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_50));

    d.setUserId(baseGame.activePlayer);
    EXPECT_TRUE(d.isMoveFromPossible(ModelTileEnum::TILE_39));
    EXPECT_TRUE(d.isMoveFromPossible(ModelTileEnum::TILE_58));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_30));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_53));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_3));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_29));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_9));
    EXPECT_FALSE(d.isMoveFromPossible(ModelTileEnum::TILE_50));
}

TEST(DataHandler, getValidDirectNeighbours) {
    DataHandler d;

    d.forwardGameStatus(baseGame);
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_47).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_39).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_58).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_30).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_53).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_3).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_29).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_9).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_50).empty());

    d.setUserId(baseGame.activePlayer);
    EXPECT_THAT(d.getValidDirectNeighbours(ModelTileEnum::TILE_47),
            testing::UnorderedElementsAreArray({ModelTileEnum::TILE_40, ModelTileEnum::TILE_54}));
    EXPECT_THAT(d.getValidDirectNeighbours(ModelTileEnum::TILE_39),
            testing::UnorderedElementsAreArray({ModelTileEnum::TILE_38, ModelTileEnum::TILE_40}));
    EXPECT_THAT(d.getValidDirectNeighbours(ModelTileEnum::TILE_58),
            testing::UnorderedElementsAreArray({ModelTileEnum::TILE_52, ModelTileEnum::TILE_57}));
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_30).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_53).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_3).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_29).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_9).empty());
    EXPECT_TRUE(d.getValidDirectNeighbours(ModelTileEnum::TILE_50).empty());
}

TEST(DataHandler, getValidSecondaryNeighbours) {
    DataHandler d;

    d.forwardGameStatus(baseGame);
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_47).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_39).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_58).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_30).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_53).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_3).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_29).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_9).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_50).empty());

    d.setUserId(baseGame.activePlayer);
    EXPECT_THAT(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_47),
            testing::Each(testing::AnyOf(
                    ModelTileEnum::TILE_32, ModelTileEnum::TILE_38, ModelTileEnum::TILE_41, ModelTileEnum::TILE_45, ModelTileEnum::TILE_49, ModelTileEnum::TILE_52, ModelTileEnum::TILE_55, ModelTileEnum::TILE_60
            )));
    EXPECT_THAT(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_39),
            testing::Each(testing::AnyOf(
                    ModelTileEnum::TILE_21, ModelTileEnum::TILE_22, ModelTileEnum::TILE_23, ModelTileEnum::TILE_32, ModelTileEnum::TILE_37, ModelTileEnum::TILE_41, ModelTileEnum::TILE_45, ModelTileEnum::TILE_49, ModelTileEnum::TILE_52, ModelTileEnum::TILE_54, ModelTileEnum::TILE_55
            )));
    EXPECT_THAT(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_58),
            testing::Each(testing::AnyOf(
                    ModelTileEnum::TILE_45, ModelTileEnum::TILE_51, ModelTileEnum::TILE_54, ModelTileEnum::TILE_55, ModelTileEnum::TILE_60
            )));
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_30).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_53).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_3).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_29).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_9).empty());
    EXPECT_TRUE(d.getValidSecondaryNeighbours(ModelTileEnum::TILE_50).empty());
}

TEST(ViewHandler, getMoveHelp) {
    //return value only depends on correctness of DataHandler isMoveFromPossible
}

TEST(ViewHandler, move) {
    //return value only depends on correctness of DataHandler isMoveValid
}