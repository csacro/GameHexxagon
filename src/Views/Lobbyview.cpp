/**
 * @author Carolin Schindler
 */

#include <iostream>
#include "Lobbyview.h"


Lobbyview::Lobbyview(LobbyviewToView &ltv, sf::Font &font, sf::Vector2u windowSize) {
    mToView = &ltv;

    unsigned int width = windowSize.x;
    unsigned int height = windowSize.y;
    sf::String initText("");

    //Elements
    sf::Vector2i pos(width*0.45, height*0.45);
    lobbyname = TextField(pos, initText, font, 0, 0);

    pos.y = height*0.55;
    playerOneUsername = TextField(pos, initText, font, 0, 0);

    pos.y = height*0.65;
    playerTwoUsername = TextField(pos, initText, font, 0, 0);

    pos.x = width*0.9;
    pos.y = height*0.9;
    sf::String startText("START GAME");
    start = Button(pos, startText, font, 0, 0);

    pos.x = width*0.8;
    sf::String leaveText("LEAVE LOBBY");
    leave = Button(pos, leaveText, font, 0, 0);

    //Listener
    leaveClick = OnClickListener(leave, leaveClickFunction);
    startClick = OnClickListener(start, startClickFunction);


    std::vector<std::string> emptyList;
    display("", "", "", false);
}


void Lobbyview::leaveClickFunction(Listener *listener) {
    mToView->leaveLobby();
}

void Lobbyview::startClickFunction(Listener *listener) {
    mToView->startGame();
}

void Lobbyview::draw(sf::RenderWindow &renderWindow) {
    lobbyname.draw(renderWindow);
    playerOneUsername.draw(renderWindow);
    playerTwoUsername.draw(renderWindow);
    start.draw(renderWindow);
    leave.draw(renderWindow);
}

void Lobbyview::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    startClick.listen(event, renderWindow);
    leaveClick.listen(event, renderWindow);
}

void Lobbyview::display(std::string lobbyName,
        std::string playerOneUserName, std::string playerTwoUserName,
        bool isStartable) {
    sf::String lobbyText(lobbyName);
    lobbyname.setText(lobbyText);
    sf::String playerOneText(playerOneUserName);
    playerOneUsername.setText(playerOneText);
    sf::String playerTwoText(playerTwoUserName);
    playerTwoUsername.setText(playerTwoText);

    start.isVisible = isStartable;
}
