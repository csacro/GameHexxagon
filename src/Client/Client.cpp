/**
 * @author Carolin Schindler
 */

#include "Client.h"
#include "MessageType.h"

Client::Client(ClientToData &ctd) {
    mToData = &ctd;
}

void Client::onReceiveMessage(std::string message) {
    auto json = nlohmann::json::parse(message);
    MessageType messageType = messagetypeMapper.at(json.at("messageType").get<std::string>());

    switch(messageType) {
        case Welcome:
            mToData->setUserId(json.at("userId").get<std::string>());
            break;
        case AvailableLobbies:
            mToData->forwardAvailableLobbies(json.at("availableLobbies").get<std::list<ModelLobby::Lobby>>());
            break;
        case LobbyCreated:
            mToData->infoLobbyCreated(json.at("lobbyId").get<std::string>(), json.at("successfullyCreated").get<bool>());
            break;
        case LobbyJoined:
            mToData->infoLobbyJoined(json.at("successfullyJoined").get<bool>());
            break;
        case LobbyStatus:
            mToData->forwardLobbyStatus(json.at("lobby").get<ModelLobby::Lobby>());
            break;
        case GameStarted:
            mToData->infoGameStarted();
            break;
        case GameStatus:
            mToData->forwardGameStatus(json.get<ModelGame::Game>());
            break;
        case Strike:
            //do nothing handled by closeListener
            break;
    }
}


void Client::connect(std::string server) {
    int splitpos = server.find(":");
    std::string servername = server.substr(0, splitpos);
    uint16_t port = std::stoi(server.substr(splitpos+1, server.size()-1));
    network::WebSocketClient client(servername, "/", port, "");

    mWebSocketClient.emplace(servername, "/", port, "");
    mWebSocketClient->receiveListener.operator()(std::bind(&Client::onReceiveMessage, this, std::placeholders::_1));
    mWebSocketClient->closeListener.operator()(std::bind(&Client::disconnect, this));
}

void Client::getAvailableLobbies(std::string userId) {
    nlohmann::json j;
    j = GetAvailableLobbies;
    j["userId"] = userId;
    mWebSocketClient->send(j.dump());
}

void Client::createNewLobby(std::string userId, std::string lobbyName) {
    nlohmann::json j;
    j = CreateNewLobby;
    j["userId"] = userId;
    j["lobbyName"] = lobbyName;
    mWebSocketClient->send(j.dump());
}

void Client::joinLobby(std::string userId, std::string lobbyId, std::string userName) {
    nlohmann::json j;
    j = JoinLobby;
    j["userId"] = userId;
    j["lobbyId"] = lobbyId;
    j["userName"] = userName;
    mWebSocketClient->send(j.dump());
}

void Client::leaveLobby(std::string userId, std::string lobbyId) {
    nlohmann::json j;
    j = LeaveLobby;
    j["userId"] = userId;
    j["lobbyId"] = lobbyId;
    mWebSocketClient->send(j.dump());
}

void Client::startGame(std::string userId, std::string lobbyId) {
    nlohmann::json j;
    j = StartGame;
    j["userId"] = userId;
    j["lobbyId"] = lobbyId;
    mWebSocketClient->send(j.dump());
}

void Client::gameMove(std::string userId, std::string gameId, ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo) {
    nlohmann::json j;
    j = GameMove;
    j["userId"] = userId;
    j["gameId"] = gameId;
    j["moveFrom"] = ModelTileEnum::TileEnumToString(moveFrom);
    j["moveTo"] = ModelTileEnum::TileEnumToString(moveTo);
    mWebSocketClient->send(j.dump());
}

void Client::leaveGame(std::string userId, std::string gameId) {
    nlohmann::json j;
    j = LeaveGame;
    j["userId"] = userId;
    j["gameId"] = gameId;
    mWebSocketClient->send(j.dump());
}

void Client::disconnect() {
    if(mWebSocketClient.has_value()) {
        mWebSocketClient.reset();
    }
    mToData->setUserId("");
}
