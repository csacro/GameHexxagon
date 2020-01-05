/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_CLIENT_H
#define GAMEHEXXAGON_CLIENT_H


#include "ViewToClient.h"
#include "../DataHandler/ClientToData.h"

class Client: public ViewToClient {
//TODO: COMPLETE CLASS + FIND WEBSOCKET-API
private:
    ClientToData *mToData;

public:
    /**
     * default Constructor
     */
    Client() = default;

    /**
     * Constructor
     * @param dtv DataToView to communicate with ViewHandler
     */
    Client(ClientToData &ctd);

    void connect(std::string server) override;

    void getAvailableLobbies(std::string userId) override;

    void createNewLobby(std::string userId, std::string lobbyName) override;

    void joinLobby(std::string userId, std::string lobbyId, std::string userName) override;

    void leaveLobby(std::string userId, std::string lobbyId) override;

    void startGame(std::string userId, std::string lobbyId) override;

    void gameMove(std::string userId, std::string gameId, TileEnum moveFrom, TileEnum moveTo) override;

    void leaveGame(std::string userId, std::string gameId) override;

    void disconnect(std::string userId) override;
};


#endif //GAMEHEXXAGON_CLIENT_H
