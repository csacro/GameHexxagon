/**
 * @author Carolin Schindler
 */

//TODO
#include <gtest/gtest.h>
#include "../src/Client/Client.h"
#include "../src/DataHandler/DataHandler.h"
#include "../src/ViewHandler/ViewHandler.h"

/*
 * GameViewToView.h/ViewHandler.h:  bool getMoveHelp(ModelTileEnum::TileEnum tile)
 *                                  bool move(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo)
 * ViewToData.h/DataHandler.h:      std::string getLobbyId()
 *                                  std::list<std::string> getLobbyStrings()
 *
 *                                  std::string getGameId()
 *                                  ModelBoard::Board getBoard()
 *                                  std::list<std::string> getGameStrings()
 *                                  std::list<bool> getGameBooleans()
 *                                  std::list<ModelTileEnum::TileEnum> getLastMove()
 *
 *                                  std::list<std::string> getJoinableLobbyNames()
 *                                  std::string getLobbyId(std::string lobbyName)
 *
 *                                  bool isGameStartable()
 *                                  bool isMoveValid(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo)
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