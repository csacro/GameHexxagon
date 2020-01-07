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
     * called by Gameview to make ViewHandler get Data to show help for the move
     * @param tile TileEnum the Tile Gameview wants to know move options from
     * @return bool is true when move can be made from tile, else false
     */
    virtual bool getMoveHelp(TileEnum tile) = 0;

    /**
     * called after user has decided from which Tile to move to which Tile
     * @param moveFrom TileEnum tile that user moves Stone from
     * @param moveTo TileEnum tile that user moves Stone to
     * @return bool is true when move can be be made from moveFrom to moveTo, else false
     */
    virtual bool move(TileEnum moveFrom, TileEnum moveTo) = 0;

    /**
     * called when the user wants to leave the Game
     * @param sendLeave true if Game is left before there is a winner
     */
    virtual void leaveGame(bool sendLeave) = 0;
};


#endif //GAMEHEXXAGON_GAMEVIEWTOVIEW_H
