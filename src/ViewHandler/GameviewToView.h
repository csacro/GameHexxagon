/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_GAMEVIEWTOVIEW_H
#define GAMEHEXXAGON_GAMEVIEWTOVIEW_H


#include <list>
#include "../Model/TileEnum.h"

/**
 * interface to ViewHandler used by Gameview
 */
class GameviewToView {
public:
    virtual std::list<TileEnum> getNeighbours(std::list<TileEnum> tiles) = 0;
    virtual void move(TileEnum moveFrom, TileEnum moveTo) = 0;
    virtual void leaveGame() = 0;
}; //TODO: documentation


#endif //GAMEHEXXAGON_GAMEVIEWTOVIEW_H
