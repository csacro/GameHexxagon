/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_GAMEVIEW_H
#define GAMEHEXXAGON_GAMEVIEW_H


#include "ViewToGameview.h"
#include "../ViewHandler/GameviewToView.h"

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

    void display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                 ModelBoard::Board board, bool isTurn) override;

    void display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                 ModelBoard::Board board, bool isTie, bool isWinner) override;

private:
    inline static GameviewToView *mToView; //interface to ViewHandler

    //Elements
    //TODO

    //Listener
    //TODO

    //Listener methods
    //TODO
};


#endif //GAMEHEXXAGON_GAMEVIEW_H
