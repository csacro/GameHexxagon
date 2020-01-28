/**
 * @author Carolin Schindler
 */

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../src/Client/Client.h"
#include "../src/DataHandler/DataHandler.h"
//#include "../src/ViewHandler/ViewHandler.h"


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

ModelBoard::Board testBoard = {}; //TODO: Board (one Tile that has everything for neighbours)
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
    //TODO: EXPECT_EQ(baseGame.board, testBoard)
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

    //active Player
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

    //TODO
}

TEST(DataHandler, isMoveFromPossible) {
    DataHandler d;

    //TODO
}

TEST(DataHandler, getValidDirectNeighbours) {
    DataHandler d;

    //TODO
}

TEST(DataHandler, getValidSecondaryNeighbours) {
    DataHandler d;

    //TODO
}

TEST(ViewHandler, getMoveHelp) {
    //ViewHandler v;

    //TODO
}

TEST(ViewHandler, move) {
    //ViewHandler v;
    //TODO
}