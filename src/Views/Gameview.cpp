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

    pos.y = height*0.25;
    pos.x = width*0.35;
    winner = TextField(pos, initText, font, 0.6*height, 0.6*height);

    float diameter = 0.5*height/9;
    float gap = 0.1*height/9;
    float tileDelta = diameter + gap;
    int tileId = 0;
    for(int i = -4; i <= 4; i++) {
        pos.y = height*0.25+gap/2 + (float)abs(i)/2*tileDelta;
        pos.x = width*0.35+gap/2 + (i+4)*tileDelta;
        for(int j = 1; j <= 9-abs(i); j++) {
            tileboard.emplace_back( Tile(TileEnum(tileId), pos.x, pos.y, diameter/2) );
            tileId++;
            pos.y += tileDelta;
        }
    }

    pos.y = height*0.9;
    pos.x = width*0.8;
    leave = Button(pos, initText, font, 0, 0);


    //Listener
    for(Tile &t: tileboard) {
        tileboardClick.emplace_back(OnClickListener(t, tileClickFunction));
    }
    leaveClick = OnClickListener(leave, leaveClickFunction);

    displayPlayerNames("", "");
}

void Gameview::tileClickFunction(Listener *listener) {
    if(mIsTurn) {
        if(isFromSet) {
            //TODO: validate -> move or reset
        } else {
            //TODO: show move help if own stone on field
        }
    }
}

void Gameview::leaveClickFunction(Listener *listener) {
    mToView->leaveGame(leave.getText() == "LEAVE GAME");
}

void Gameview::draw(sf::RenderWindow &renderWindow) {
    for(Tile &t: tileboard) {
        t.draw(renderWindow);
    }
    if(!winner.getText().isEmpty()) {
        winner.draw(renderWindow);
    }
    playerOneUsername.draw(renderWindow);
    playerTwoUsername.draw(renderWindow);
    playerOnepoints.draw(renderWindow);
    playerTwopoints.draw(renderWindow);
    leave.draw(renderWindow);
}

void Gameview::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    for(OnClickListener ocl: tileboardClick) {
        ocl.listen(event, renderWindow);
    }
    leaveClick.listen(event, renderWindow);
}

void Gameview::displayPlayerNames(std::string playerOneUserName, std::string playerTwoUserName) {
    mIsTurn = false;
    isFromSet = false;

    sf::String leaveText("LEAVE GAME");
    leave.setText(leaveText);

    sf::String emptyText("");
    winner.setText(emptyText);

    for(Tile t: tileboard) {
        t.setStoneColor(sf::Color::Transparent);
        t.setHexagonOutlineColor(sf::Color::Transparent);
    }

    sf::String playerOneText(playerOneUserName);
    playerOneUsername.setText(playerOneText);
    sf::String playerTwoText(playerTwoUserName);
    playerTwoUsername.setText(playerTwoText);
}

void Gameview::display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                       ModelBoard::Board board, bool isTurn) {
    displayPlayerPoints(playerOnePoints, playerTwoPoints);

    updateBoard(moveFrom, moveTo, board);

    mIsTurn = isTurn;
}

void Gameview::display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                       ModelBoard::Board board, bool isTie, bool isWinner) {
    sf::String leaveText("CLOSE");
    leave.setText(leaveText);

    displayPlayerPoints(playerOnePoints, playerTwoPoints);

    updateBoard(moveFrom, moveTo, board);

    if(isTie) {
        sf::String tieText("TIE: no one has won");
        winner.setText(tieText);
    } else if (isWinner) {
        sf::String winnerText("WINNER: you have won");
        winner.setText(winnerText);
    } else {
        sf::String loserText("LOSER: you have lost");
        winner.setText(loserText);
    }
}

void Gameview::updateBoard(TileEnum moveFrom, TileEnum moveTo, ModelBoard::Board board) {
    //TODO
}

void Gameview::displayPlayerPoints(std::string &playerOnePoints, std::string &playerTwoPoints) {
    sf::String playerOneText(playerOnePoints);
    playerOnepoints.setText(playerOneText);
    sf::String playerTwoText(playerTwoPoints);
    playerTwopoints.setText(playerTwoText);
}
