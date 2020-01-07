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
            tileboard.emplace(TileEnum(tileId), Tile(TileEnum(tileId), pos.x, pos.y, diameter/2));
            tileId++;
            pos.y += tileDelta;
        }
    }

    pos.y = height*0.9;
    pos.x = width*0.8;
    leave = Button(pos, initText, font, 0, 0);


    //Listener
    for(auto &m: tileboard) {
        auto *tile = &m.second;
        tileboardClick.emplace_back(OnClickListener(*tile, tileClickFunction));
    }
    leaveClick = OnClickListener(leave, leaveClickFunction);

    displayPlayerNames("", "");
}

void Gameview::tileClickFunction(Listener *listener) {
    if(mIsTurn) {
        Tile *mClickedTile = dynamic_cast<Tile*>(dynamic_cast<OnClickListener*>(listener)->mClickableElement);
        if(isFromSet) {
            if(!mToView->move(from->mTileId, mClickedTile->mTileId)) {
                askForMoveHelp(mClickedTile);
            }
        } else {
            askForMoveHelp(mClickedTile);
        }
    }
}

void Gameview::leaveClickFunction(Listener *listener) {
    mToView->leaveGame(leave.getText() == "LEAVE GAME");
}

void Gameview::draw(sf::RenderWindow &renderWindow) {
    if(!winner.getText().isEmpty()) {
        winner.draw(renderWindow);
    } else {
        for(auto &m: tileboard) {
            auto *tile = &m.second;
            tile->draw(renderWindow);
        }
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

    for(auto m: tileboard) {
        m.second.setStoneColor(sf::Color::Transparent);
        m.second.setHexagonOutlineColor(sf::Color::Transparent);
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

void Gameview::displayHelp(std::list<TileEnum> directNeighbours, std::list<TileEnum> secondaryNeighbours) {
    for(TileEnum tileEnum: secondaryNeighbours) {
        tileboard.at(tileEnum).setHexagonOutlineColor(sf::Color::Yellow);
    }
    for(TileEnum tileEnum: directNeighbours) {
        tileboard.at(tileEnum).setHexagonOutlineColor(sf::Color::Green);
    }
}

void Gameview::clearHelp() {
    for(auto &m: tileboard) {
        auto *tile = &m.second;
        tile->setHexagonOutlineColor(sf::Color::Transparent);
    }
}

void Gameview::updateBoard(TileEnum moveFrom, TileEnum moveTo, ModelBoard::Board board) {
    isFromSet = false;

    for(auto &m: tileboard) {
        auto *tile = &m.second;
        switch(board.tiles.at(tile->mTileId)) {
            case PLAYERONE:
                tile->setStoneColor(sf::Color::Red);
                break;
            case PLAYERTWO:
                tile->setStoneColor(sf::Color::White);
                break;
            case FREE:
                tile->setStoneColor(sf::Color::Transparent);
                break;
            case BLOCKED:
                tile->isVisible = false;
                break;
        }
    }
}

void Gameview::displayPlayerPoints(std::string &playerOnePoints, std::string &playerTwoPoints) {
    sf::String playerOneText(playerOnePoints);
    playerOnepoints.setText(playerOneText);
    sf::String playerTwoText(playerTwoPoints);
    playerTwopoints.setText(playerTwoText);
}

void Gameview::askForMoveHelp(Tile *tile) {
    if(mToView->getMoveHelp(tile->mTileId)) {
        from = tile;
        isFromSet = true;
    }
}
