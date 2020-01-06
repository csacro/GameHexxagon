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

    /**
     * called after user has decided from which Tile to move to which Tile
     * @param moveFrom TileEnum tile that user moves Stone from
     * @param moveTo TileEnum tile that user moves Stone to
     */
    virtual void move(TileEnum moveFrom, TileEnum moveTo) = 0;

    /**
     * called when the user wants to leave the Game
     * @param sendLeave true if Game is left before there is a winner
     */
    virtual void leaveGame(bool sendLeave) = 0;
}; //TODO: documentation (getNeighbours for spielfeld)


#endif //GAMEHEXXAGON_GAMEVIEWTOVIEW_H
