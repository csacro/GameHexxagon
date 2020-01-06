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
    /**
     * called by Gameview to get to know neighbours of all tiles in paramlist
     * @param tiles std::list<TileEnum> containing all Tiles Gameview wants to know neighbours of
     * @return std::list<TileEnum> containing neighbours of all TileEnums in tiles
     */
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
};


#endif //GAMEHEXXAGON_GAMEVIEWTOVIEW_H
