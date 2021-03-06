/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_VIEWTOGAMEVIEW_H
#define GAMEHEXXAGON_VIEWTOGAMEVIEW_H


#include <string>
#include <list>
#include <SFMLComponents/WindowViews/WindowView.h>
#include "../Model/TileEnum.h"
#include "../Model/Board.h"

/**
 * interface to Gameview used by ViewHandler
 */
class ViewToGameview: public WindowView {
public:
    /**
     * called by ViewHandler to update players' name in Gameview
     * @param playerOneUserName std::string name of playerOne
     * @param playerTwoUserName std::string name of playerTow
     */
    virtual void displayPlayerNames(std::string playerOneUserName, std::string playerTwoUserName) = 0;

    /**
     * called by ViewHandler to update Gameview
     * @param playerOnePoints st::string playerOne's points
     * @param playerTwoPoints st::string playerTwo's points
     * @param moveFrom TileEnum from which Stone was moved
     * @param moveTo TileEnum to which Stone was moved
     * @param board Board complete Board to be displayed
     * @param isTurn bool is true when it is User's turn
     */
    virtual void display(std::string playerOnePoints, std::string playerTwoPoints,
                         ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo, ModelBoard::Board board,
            bool isTurn)
            = 0;

    /**
     * called by ViewHandler to update Gameview and make Gameview show Winner
     * @param playerOnePoints st::string playerOne's points
     * @param playerTwoPoints st::string playerTwo's points
     * @param moveFrom TileEnum from which Stone was moved
     * @param moveTo TileEnum to which Stone was moved
     * @param board Board complete Board to be displayed
     * @param isTie is true when neither playerOne nor playerTwo has won
     * @param isWinner is true when User has won, else false
     */
    virtual void display(std::string playerOnePoints, std::string playerTwoPoints,
                         ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo, ModelBoard::Board board,
             bool isTie, bool isWinner)
             = 0;
    /**
     * called by ViewHandler to make Gameview able to display help for the current move
     * (help got requested earlier by Gameview)
     * @param directNeighbours std::list<TileEnum> containing all direct neighbours tiles of the requested tile to which a move can be made
     * @param secondaryNeighbours std::list<TileEnum> containing all neighbours of neighbours ot the request tile to which a move can be made
     */
    virtual void displayHelp(std::list<ModelTileEnum::TileEnum> directNeighbours, std::list<ModelTileEnum::TileEnum> secondaryNeighbours) = 0;

    /**
     * called by ViewHandler to clear everything that has been drawn by Gameview in order to display help
     */
    virtual void clearHelp() = 0;
};


#endif //GAMEHEXXAGON_VIEWTOGAMEVIEW_H
