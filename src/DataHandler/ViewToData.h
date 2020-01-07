/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_VIEWTODATA_H
#define GAMEHEXXAGON_VIEWTODATA_H


#include <string>
#include <list>
#include "../Model/TileEnum.h"
#include "../Model/Board.h"

/**
 * interface to data used by ViewHandler
 */
class ViewToData {
public:
    /**
     * getter for user's id
     * @return std::string userId of User
     */
    virtual std::string getUserId() = 0;

    /**
     * getter for user's name
     * @return std::string userName of User
     */
    virtual std::string getUserName() = 0;

    /**
     * getter for lobby's id
     * @return std::string lobbyId of Lobby
     */
    virtual std::string getLobbyId() = 0;

    /**
     * getter for games's id
     * @return std::string gameId of game
     */
    virtual std::string getGameId() = 0;

    /**
     * called when ViewHandler wants to know wether Client is connected to server or not
     * @return bool is true when User (and therefore Client) is connected to server, else false
     */
    virtual bool isConnected() = 0;

    /**
     * setter for user's name
     * @param userName std::string to be set as userName in User
     */
    virtual void setUserName(std::string userName) = 0;

    /**
     * called when ViewHandler wants to know if Game is startable by user
     * @return bool is true when user is allowed to start the Game, else false
     */
    virtual bool isGameStartable() = 0;

    /**
     * called when ViewHandler wants to know the lobbyNames of all Lobbies that are joinable at the moment
     * @return std::list<std::string> lobbyNames of Lobbies that are available and not closed
     */
    virtual std::list<std::string> getJoinableLobbyNames() = 0;

    /**
     * find Lobby with lobbyName in availableLobbies list and return lobbyId of the Lobby
     * @param lobbyName std::string lobbyName of the Lobby whose lobbyId is wanted
     * @return std::string lobbyId of the Lobby with lobbyName in availableLobbies, empty string if no Lobby with lobbyName exists
     */
    virtual std::string getLobbyId(std::string lobbyName) = 0;

    /**
     * called by ViewHandler to get information about Lobby to hand over to Lobbyview to display
     * @return std::list<std::string> {lobbyName, playerOneUserName, playerTwoUserName} in Lobby
     */
    virtual std::list<std::string> getLobbyStrings() = 0;

    /**
     * called by ViewHandler to get information about Game to hand over to Gameview to display
     * @return std::list<std::string> {playerOnePoints, playerTwoPoints} in Game
     */
    virtual std::list<std::string> getGameStrings()  = 0;

    /**
     * called by ViewHandler to get information about Game to hand over to Gameview to display
     * @return std::list<bool> if game is over {isTie, isUserWinner}, else {isUserTurn}
     */
    virtual std::list<bool> getGameBooleans()  = 0;

    /**
     * called by ViewHandler to get information about Game to hand over to Gameview to display
     * @return std::list<TileEnum> {moveFrom, moveTo} in Game
     */
    virtual std::list<TileEnum> getLastMove()  = 0;

    /**
     * getter for game's board
     * @return ModelBoard::Board current Board of Game
     */
    virtual ModelBoard::Board getBoard()  = 0;

    /**
     * checks wether move from moveFrom to moveTo is valid or not
     * @param moveFrom TileEnum from where user wants to move the Stone
     * @param moveTo TileEnum to where user wants to move the Stone
     * @return bool is true when move is valid, else false
     */
    virtual bool isMoveValid(TileEnum moveFrom, TileEnum moveTo)  = 0;

    /**
     * checks wether move from moveFrom is possible
     * @param moveFrom TileEnum from where the User wants to move the Stone
     * @return bool is true when Stone from User is on moveFrom, else false
     */
    virtual bool isMoveFromPossible(TileEnum moveFrom) = 0;

    /**
     * called in order to get all direct neighbours of kachel to where a move can be made
     * @param kachel TileEnum from where the move is going to me made
     * @return std::list<TileEnum> all direct neighbours with TileStateEnum FREE
     */
    virtual std::list<TileEnum> getValidDirectNeighbours(TileEnum kachel)  = 0;

    /**
     * called in order to get all neighbours of neighbours of kachel to where a move can be made
     * @param kachel TileEnum from where the move is going to me made
     * @return std::list<TileEnum> all secondary neighbours with TileStateEnum FREE
     */
    virtual std::list<TileEnum> getValidSecondaryNeighbours(TileEnum kachel) = 0;
};


#endif //GAMEHEXXAGON_VIEWTODATA_H
