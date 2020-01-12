/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_GAMEVIEW_H
#define GAMEHEXXAGON_GAMEVIEW_H


#include <SFMLComponents/Elements/TextField.h>
#include <SFMLComponents/Elements/Button.h>
#include <SFMLComponents/Listener/OnClickListener.h>
#include "ViewToGameview.h"
#include "../ViewHandler/GameviewToView.h"
#include "Tile.h"

class Gameview: public ViewToGameview {
public:
    /**
     * default Constructor
     */
    Gameview() = default;

    /**
     * Constructor
     * @param gtv GameviewToView to communicate with ViewHandler
     * @param font sf::Font used to display sf::Text
     * @param windowSize sf::Vector2u which is size of sf::RenderWindow
     */
    Gameview(GameviewToView &gtv, sf::Font &font, sf::Vector2u windowSize);

    void draw(sf::RenderWindow &renderWindow) override;

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;

    void displayPlayerNames(std::string playerOneUserName, std::string playerTwoUserName) override;

    void display(std::string playerOnePoints, std::string playerTwoPoints, ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo,
                 ModelBoard::Board board, bool isTurn) override;

    void display(std::string playerOnePoints, std::string playerTwoPoints, ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo,
                 ModelBoard::Board board, bool isTie, bool isWinner) override;

    void displayHelp(std::list<ModelTileEnum::TileEnum> directNeighbours, std::list<ModelTileEnum::TileEnum> secondaryNeighbours) override;

    void clearHelp() override;

private:
    inline static GameviewToView *mToView; //interface to ViewHandler
    inline static bool mIsTurn; //true if it is user's turn
    inline static Tile *from; //Tile from where to make move
    inline static bool isFromSet; //true if Tile from is/was selected

    /**
     * helper function to display the move and the current board
     * @param moveFrom ModelTileEnum::TileEnum from which last Stone was moved
     * @param moveTo ModelTileEnum::TileEnum to which last Stone was moved
     * @param board Board after last Stone was moved
     */
    void updateBoard(ModelTileEnum::TileEnum moveFrom, ModelTileEnum::TileEnum moveTo, ModelBoard::Board board);

    /**
     * helper function to display the Points of playerOne and playerTwo
     * @param playerOnePoints std::string points of playerOne
     * @param playerTwoPoints std::string points of playerTwo
     */
    void displayPlayerPoints(std::string &playerOnePoints, std::string &playerTwoPoints);

    /**
     * helper function to ask for move help and set from
     * @param tile Tile* the user wants to move from
     */
    static void askForMoveHelp(Tile *tile);

    //Elements
    inline static TextField winner; //TextField to display winner
    inline static std::map<ModelTileEnum::TileEnum, Tile> tileboard; //Tiles making up the board
    inline static TextField playerOneUsername; //TextField to display name of playerOne
    inline static TextField playerTwoUsername; //TextField to display name of playerTwo
    inline static TextField playerOnepoints; //TextField to display points of playerOne
    inline static TextField playerTwopoints; //TextField to display points of playerTwo
    inline static Button leave; //Button to leave Game
    inline static TextField mTurn; //TextField to display if it is user's turn and which stones to use

    //Listener
    inline static std::list<OnClickListener> tileboardClick; //for tileboard
    inline static OnClickListener leaveClick; //for leave

    //Listener methods
    static void tileClickFunction(Listener *listener);
    static void leaveClickFunction(Listener *listener);
};


#endif //GAMEHEXXAGON_GAMEVIEW_H
