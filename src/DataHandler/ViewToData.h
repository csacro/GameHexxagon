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
     *
     * @return
     */
    virtual std::string getUserId() = 0;

    /**
     *
     * @return
     */
    virtual std::string getUserName() = 0;

    /**
     *
     * @return
     */
    virtual std::string getLobbyId() = 0;

    /**
     *
     * @return
     */
    virtual std::string getGameId() = 0;

    /**
     *
     * @return
     */
    virtual bool isConnected() = 0;

    /**
     *
     * @param userName
     */
    virtual void setUserName(std::string userName) = 0;

    /**
     *
     * @return
     */
    virtual bool isGameStartable() = 0;

    /**
     *
     * @return
     */
    virtual std::list<std::string> getJoinableLobbyNames() = 0;

    /**
     *
     * @param lobbyName
     * @return
     */
    virtual std::string getLobbyId(std::string lobbyName) = 0;

    /**
     *
     * @return
     */
    virtual std::list<std::string> getLobbyStrings() = 0;

    /**
     *
     * @return
     */
    virtual std::list<std::string> getGameStrings()  = 0;

    /**
     *
     * @return
     */
    virtual std::list<bool> getGameBooleans()  = 0;

    /**
     *
     * @return
     */
    virtual std::list<TileEnum> getLastMove()  = 0;

    /**
     *
     * @return
     */
    virtual ModelBoard::Board getBoard()  = 0;

    /**
     *
     * @param moveFrom
     * @param moveTo
     * @return
     */
    virtual bool isMoveValid(TileEnum moveFrom, TileEnum moveTo)  = 0;

    /**
     *
     * @param kacheln
     * @return
     */
    virtual std::list<TileEnum> getNeighbours(std::list<TileEnum> kacheln)  = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_VIEWTODATA_H
