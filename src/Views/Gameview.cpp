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
    sf::Vector2i pos(width*0.1, height*0.1);
    playerOneUsername = TextField(pos, initText, font, 0, 0);

    pos.y = height*0.2;
    playerTwoUsername = TextField(pos, initText, font, 0, 0);

    pos.x = width*0.2;
    pos.y = height*0.1;
    playerOnepoints = TextField(pos, initText, font, 0, 0);

    pos.y = height*0.2;
    playerTwopoints = TextField(pos, initText, font, 0, 0);


    //TODO: spielfed
    //left height [0.3*height, 0.8*height] -> 0.6*height
    //left width [0.1*width, 0.9*width] -> 0.9*width


    pos.y = height*0.9;
    pos.x = width*0.8;
    sf::String leaveText("LEAVE GAME");
    leave = Button(pos, leaveText, font, 0, 0);


    //Listener
    leaveClick = OnClickListener(leave, leaveClickFunction);
    //TODO: spielfeld

    displayPlayerNames("", "");
}

void Gameview::leaveClickFunction(Listener *listener) {
    mToView->leaveGame();
}

void Gameview::draw(sf::RenderWindow &renderWindow) {
    //TODO: spielfeld
    playerOneUsername.draw(renderWindow);
    playerTwoUsername.draw(renderWindow);
    playerOnepoints.draw(renderWindow);
    playerTwopoints.draw(renderWindow);
    leave.draw(renderWindow);
}

void Gameview::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    //TODO: spielfeld
    leaveClick.listen(event, renderWindow);
}

void Gameview::displayPlayerNames(std::string playerOneUserName, std::string playerTwoUserName) {
    sf::String playerOneText(playerOneUserName);
    playerOneUsername.setText(playerOneText);
    sf::String playerTwoText(playerTwoUserName);
    playerTwoUsername.setText(playerTwoText);
    //TODO init spielfeld
}

void Gameview::display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                       ModelBoard::Board board, bool isTurn) {
    displayPlayerPoints(playerOnePoints, playerTwoPoints);
    //TODO: move, board, turn

}

void Gameview::display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                       ModelBoard::Board board, bool isTie, bool isWinner) {
    displayPlayerPoints(playerOnePoints, playerTwoPoints);
    //TODO move, board, displayWinner
}

void Gameview::displayPlayerPoints(std::string &playerOnePoints, std::string &playerTwoPoints) {
    sf::String playerOneText(playerOnePoints);
    playerOnepoints.setText(playerOneText);
    sf::String playerTwoText(playerTwoPoints);
    playerTwopoints.setText(playerTwoText);
}
