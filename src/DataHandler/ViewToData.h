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
     * TODO: documentation
     * @return std::list<std::string>
     */
    virtual std::list<std::string> getJoinableLobbyNames() = 0;

    /**
     * TODO: documentation
     * @param lobbyName std::string
     * @return std::string
     */
    virtual std::string getLobbyId(std::string lobbyName) = 0;

    /**
     * TODO: documentation
     * @return std::list<std::string>
     */
    virtual std::list<std::string> getLobbyStrings() = 0;

    /**
     * TODO: documentation
     * @return std::list<std::string>
     */
    virtual std::list<std::string> getGameStrings()  = 0;

    /**
     * TODO: documentation
     * @return std::list<bool>
     */
    virtual std::list<bool> getGameBooleans()  = 0;

    /**
     * TODO: documentation
     * @return std::list<TileEnum>
     */
    virtual std::list<TileEnum> getLastMove()  = 0;

    /**
     * getter for game's board
     * @return ModelBoard::Board current Board of Game
     */
    virtual ModelBoard::Board getBoard()  = 0;

    /**
     * TODO: documentation
     * @param moveFrom TileEnum
     * @param moveTo TileEnum
     * @return bool
     */
    virtual bool isMoveValid(TileEnum moveFrom, TileEnum moveTo)  = 0;

    /**
     * TODO: documentation
     * @param moveFrom TileEnum
     * @return bool
     */
    virtual bool isMoveFromPossible(TileEnum moveFrom) = 0;

    /**
     * TODO: documentation
     * @param kachel TileEnum
     * @return std::list<TileEnum>
     */
    virtual std::list<TileEnum> getValidDirectNeighbours(TileEnum kachel)  = 0;

    /**
     * TODO: documentation
     * @param kachel TileEnum
     * @return std::list<TileEnum>
     */
    virtual std::list<TileEnum> getValidSecondaryNeighbours(TileEnum kachel) = 0;
};


#endif //GAMEHEXXAGON_VIEWTODATA_H
