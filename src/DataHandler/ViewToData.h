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
    virtual std::string getUserId() = 0;
    virtual std::string getUserName() = 0;
    virtual std::string getLobbyId() = 0;
    virtual std::string getGameId() = 0;
    virtual bool isConnected() = 0;
    virtual void setUserName(std::string userName) = 0;
    virtual bool isGameStartable() = 0;
    virtual std::list<std::string> getJoinableLobbyNames() = 0;
    virtual std::string getLobbyId(std::string lobbyName) = 0;
    virtual std::list<std::string> getLobbyStrings() = 0;
    virtual std::list<std::string> getGameStrings()  = 0;
    virtual std::list<bool> getGameBooleans()  = 0;
    virtual std::list<TileEnum> getLastMove()  = 0;
    virtual ModelBoard::Board getBoard()  = 0;
    virtual bool isMoveValid(TileEnum moveFrom, TileEnum moveTo)  = 0;
    virtual std::list<TileEnum> getNeighbours(std::list<TileEnum> kacheln)  = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_VIEWTODATA_H
