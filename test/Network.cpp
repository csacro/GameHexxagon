/**
 * @author Carolin Schindler
 */

#include <gtest/gtest.h>
#include "../src/Client/MessageType.h"
#include "../src/Model/TileEnum.h"


TEST(MessageType, messageTypeToString) {
    EXPECT_EQ("Welcome", messageTypeToString(Welcome));
    EXPECT_EQ("GetAvailableLobbies", messageTypeToString(GetAvailableLobbies));
    EXPECT_EQ("AvailableLobbies", messageTypeToString(AvailableLobbies));
    EXPECT_EQ("CreateNewLobby", messageTypeToString(CreateNewLobby));
    EXPECT_EQ("LobbyCreated", messageTypeToString(LobbyCreated));
    EXPECT_EQ("JoinLobby", messageTypeToString(JoinLobby));
    EXPECT_EQ("LobbyJoined", messageTypeToString(LobbyJoined));
    EXPECT_EQ("LobbyStatus", messageTypeToString(LobbyStatus));
    EXPECT_EQ("LeaveLobby", messageTypeToString(LeaveLobby));
    EXPECT_EQ("StartGame", messageTypeToString(StartGame));
    EXPECT_EQ("GameStarted", messageTypeToString(GameStarted));
    EXPECT_EQ("GameMove", messageTypeToString(GameMove));
    EXPECT_EQ("LeaveGame", messageTypeToString(LeaveGame));
    EXPECT_EQ("Strike", messageTypeToString(Strike));
}

TEST(MessageType, to_json) {
    //return value only depends on correctness of MessageType messageTypeToString (and nlohmann-json)
}

TEST(TileEnum, TileEnumToString) {
    EXPECT_EQ("TILE_1", ModelTileEnum::TileEnumToString(ModelTileEnum::TILE_1));
    EXPECT_EQ("TILE_9", ModelTileEnum::TileEnumToString(ModelTileEnum::TILE_9));
    EXPECT_EQ("TILE_50", ModelTileEnum::TileEnumToString(ModelTileEnum::TILE_50));
    EXPECT_EQ("TILE_61", ModelTileEnum::TileEnumToString(ModelTileEnum::TILE_61));
}

TEST(TileEnum, StringToTileEnum) {
    EXPECT_EQ(ModelTileEnum::TILE_1, ModelTileEnum::StringToTileEnum("TILE_1"));
    EXPECT_EQ(ModelTileEnum::TILE_9, ModelTileEnum::StringToTileEnum("TILE_9"));
    EXPECT_EQ(ModelTileEnum::TILE_50, ModelTileEnum::StringToTileEnum("TILE_50"));
    EXPECT_EQ(ModelTileEnum::TILE_61, ModelTileEnum::StringToTileEnum("TILE_61"));
}

TEST(Lobby, from_json) {
    //TODO
}

TEST(Game, from_json) {
    //TODO
}

TEST(Board, from_json) {
    //TODO
}

