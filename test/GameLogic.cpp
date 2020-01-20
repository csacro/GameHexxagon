/**
 * @author Carolin Schindler
 */

//TODO
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../src/Client/Client.h"
#include "../src/DataHandler/DataHandler.h"
#include "../src/ViewHandler/ViewHandler.h"

/*
 * GameViewToView.h/ViewHandler.h:  bool getMoveHelp(ModelTileEnum::TileEnum tile)
 *                                  bool move(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo)
 * ViewToData.h/DataHandler.h:      bool isMoveValid(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo)
 *                                  bool isMoveFromPossible(ModelTileEnum::TileEnum moveFrom)
 *                                  std::list<ModelTileEnum::TileEnum > getValidDirectNeighbours(ModelTileEnum::TileEnum kachel)
 *                                  std::list<ModelTileEnum::TileEnum > getValidSecondaryNeighbours(ModelTileEnum::TileEnum kachel)
 */

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

/*
//TODO: create Game(s) (think about Board and turn and Winner/Tie)

TEST(DataHandler, getGameId) {
    DataHandler d;

    //TODO
}

TEST(DataHandler, getBoard) {
    DataHandler d;

    //TODO
}

TEST(DataHandler, getGameStrings) {
    DataHandler d;

    //TODO: {playerOnePoints, playerTwoPoints}
}

TEST(DataHandler, getGameBooleans) {
    DataHandler d;

    //TODO: if game is over {isTie, isUserWinner}, else {isUserTurn}
}

TEST(DataHandler, getLastMove) {
    DataHandler d;

    //TODO
}
 */
