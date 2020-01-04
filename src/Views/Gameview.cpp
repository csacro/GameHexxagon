/**
 * @author Carolin Schindler
 */

#include "Gameview.h"


Gameview::Gameview(GameviewToView &gtv, sf::Font &font, sf::Vector2u windowSize) {
    mToView = &gtv;

    unsigned int width = windowSize.x;
    unsigned int height = windowSize.y;
    sf::String initText("");


    //Elements
    //TODO


    //Listener
    //TODO


    //TODO display call?
}

void Gameview::draw(sf::RenderWindow &renderWindow) {
//TODO
}

void Gameview::listen(sf::Event event, sf::RenderWindow &renderWindow) {
//TODO
}

void Gameview::displayPlayerNames(std::string playerOneUserName, std::string playerTwoUserName) {
//TODO
}

void Gameview::display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                       ModelBoard::Board board, bool isTurn) {
//TODO
}

void Gameview::display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                       ModelBoard::Board board, bool isTie, bool isWinner) {
//TODO
}
