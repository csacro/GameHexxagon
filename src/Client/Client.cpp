/**
 * @author Carolin Schindler
 */

#include "Client.h"
#include "MessageType.h"

Client::Client(ClientToData &ctd) {
    mToData = &ctd;
}

void Client::onReceiveMessage(std::string message) {
    std::cout << message << std::endl;
    auto json = nlohmann::json::parse(message);
    MessageType messageType = messagetypeMapper.at(json.at("messageType").get<std::string>());

    std::cout << messageType << std::endl;

    switch(messageType) {
        case Welcome:
            std::cout << "received: Welcome"<< std::endl;
            mToData->setUserId(json.at("userId").get<std::string>());
            break;
        case AvailableLobbies:
            std::cout << "received: AvailableLobbies"<< std::endl;
            mToData->forwardAvailableLobbies(json.at("availableLobbies").get<std::list<ModelLobby::Lobby>>());
            break;
        case LobbyCreated:
            std::cout << "received: LobbyCreated"<< std::endl;
            mToData->infoLobbyCreated(json.at("lobbyId").get<std::string>(), json.at("successfullyCreated").get<bool>());
            break;
        case LobbyJoined:
            std::cout << "received: LobbyJoined"<< std::endl;
            mToData->infoLobbyJoined(json.at("successfullyJoined").get<bool>());
            break;
        case LobbyStatus:
            std::cout << "received: LobbyStatus"<< std::endl;
            mToData->forwardLobbyStatus(json.at("lobby").get<ModelLobby::Lobby>());
            break;
        case GameStarted:
            std::cout << "received: GameStarted"<< std::endl;
            mToData->infoGameStarted();
            break;
        case GameStatus:
            std::cout << "received: GameStatus"<< std::endl;
            mToData->forwardGameStatus(json.get<ModelGame::Game>());
            break;
        case Strike:
            std::cout << "received: Strike"<< std::endl;
            //do nothing handled by closeListener
            break;
    }
}


void Client::connect(std::string server) {
    std::cout << "connect" << std::endl;
    int splitpos = server.find(":");
    std::string servername = server.substr(0, splitpos);
    uint16_t port = std::stoi(server.substr(splitpos+1, server.size()-1));
    network::WebSocketClient client(servername, "/", port, "");

    mWebSocketClient.emplace(servername, "/", port, "");
    mWebSocketClient->receiveListener.operator()(std::bind(&Client::onReceiveMessage, this, std::placeholders::_1));
    mWebSocketClient->closeListener.operator()(std::bind(&Client::disconnect, this));
}

void Client::getAvailableLobbies(std::string userId) {
    std::cout << "getAvailableLobbies" << std::endl;
    nlohmann::json j;
    j = GetAvailableLobbies;
    j["userId"] = userId;
    mWebSocketClient->send(j.dump());
}

void Client::createNewLobby(std::string userId, std::string lobbyName) {
    std::cout << "createNewLobby" << std::endl;
    nlohmann::json j;
    j = CreateNewLobby;
    j["userId"] = userId;
    j["lobbyName"] = lobbyName;
    mWebSocketClient->send(j.dump());
}

void Client::joinLobby(std::string userId, std::string lobbyId, std::string userName) {
    std::cout << "joinLobby" << std::endl;
    nlohmann::json j;
    j = JoinLobby;
    j["userId"] = userId;
    j["lobbyId"] = lobbyId;
    j["userName"] = userName;
    mWebSocketClient->send(j.dump());
    std::cout << "sent join lobby" << std::endl;
}

void Client::leaveLobby(std::string userId, std::string lobbyId) {
    std::cout << "leaveLobby" << std::endl;
    nlohmann::json j;
    j = LeaveLobby;
    j["userId"] = userId;
    j["lobbyId"] = lobbyId;
    mWebSocketClient->send(j.dump());
}

void Client::startGame(std::string userId, std::string lobbyId) {
    std::cout << "startGame" << std::endl;
    nlohmann::json j;
    j = StartGame;
    j["userId"] = userId;
    j["lobbyId"] = lobbyId;
    mWebSocketClient->send(j.dump());
}

void Client::gameMove(std::string userId, std::string gameId, ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo) {
    std::cout << "gameMove" << std::endl;
    nlohmann::json j;
    j = GameMove;
    j["userId"] = userId;
    j["gameId"] = gameId;
    j["moveFrom"] = ModelTileEnum::TileEnumToString(moveFrom);
    j["moveTo"] = ModelTileEnum::TileEnumToString(moveTo);
    mWebSocketClient->send(j.dump());
}

void Client::leaveGame(std::string userId, std::string gameId) {
    std::cout << "leaveGame" << std::endl;
    nlohmann::json j;
    j = LeaveGame;
    j["userId"] = userId;
    j["gameId"] = gameId;
    mWebSocketClient->send(j.dump());
}

void Client::disconnect() {
    std::cout << "disconnect" << std::endl;
    if(mWebSocketClient.has_value()) {
        mWebSocketClient.reset();
    }
    mToData->setUserId("");
}
