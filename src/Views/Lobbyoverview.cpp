/**
 * @author Carolin Schindler
 */

#include <SFML/Graphics/RenderWindow.hpp>
#include "Lobbyoverview.h"


Lobbyoverview::Lobbyoverview(LobbyoverviewToView &lotv, sf::Font &font, sf::Vector2u windowSize) {
    mToView = &lotv;

    unsigned int width = windowSize.x;
    unsigned int height = windowSize.y;
    sf::String initText("");

    //Elements
    sf::Vector2i pos(width*0.45, height*0.33);
    sf::String usernameDefaultText("unknown User");
    userName = EditField(pos, usernameDefaultText, font, 0, 0);

    pos.y = height*0.43;
    sf::String lobbynameDefaultText("unknown Lobby");
    lobbyName = EditField(pos, lobbynameDefaultText, font, 0, 0);

    pos.x = width*0.66;
    pos.y = height*0.355;
    sf::String createandjoinText("CREATE AND JOIN");
    createAndJoin = Button(pos, createandjoinText, font, 0, 0);

    pos.y = height*0.405;
    sf::String joinText("JOIN");
    join = Button(pos, joinText, font, 0, 0);

    pos.y = height*0.5;
    sf::String updateText("UPDATE");
    update = Button(pos, updateText, font, 0, 0);

    pos.x = 0.3;
    availableLobbies = TextField(pos, initText, font, 0.4*width, 0.1*height);

    pos.x = width*0.8;
    pos.y = height*0.9;
    sf::String backText("BACK");
    back = Button(pos, backText, font, 0, 0);


    //Listener
    createandjoinClick = OnClickListener(createAndJoin, createandjoinClickFunction);
    joinClick = OnClickListener(join, joinClickFunction);
    updateClick = OnClickListener(update, updateClickFunction);
    backClick = OnClickListener(back, backClickFunction);
    nameText = OnTextListener(nameTextFunction);
    usernameClick = OnClickListener(userName, usernameClickFunction);
    lobbynameClick = OnClickListener(lobbyName, lobbynameClickFunction);

    std::list<std::string> emptyList;
    display(emptyList);
}

void Lobbyoverview::createandjoinClickFunction() {
    mToView->createAndJoinLobby(lobbyName.getText(), userName.getText());
}

void Lobbyoverview::joinClickFunction() {
    mToView->joinLobby(lobbyName.getText(), userName.getText());
}

void Lobbyoverview::updateClickFunction() {
    mToView->updateLobbyoverview();
}

void Lobbyoverview::backClickFunction() {
    mToView->showMainmenu();
}

void Lobbyoverview::nameTextFunction() {
    userName.addText(nameText.mLastText);
    lobbyName.addText(nameText.mLastText);
}

void Lobbyoverview::usernameClickFunction() {
    userName.mEdit = true;
    lobbyName.mEdit = false;
}

void Lobbyoverview::lobbynameClickFunction() {
    userName.mEdit = false;
    lobbyName.mEdit = true;
}

void Lobbyoverview::draw(sf::RenderWindow &renderWindow) {
    userName.draw(renderWindow);
    lobbyName.draw(renderWindow);
    createAndJoin.draw(renderWindow);
    join.draw(renderWindow);
    update.draw(renderWindow);
    back.draw(renderWindow);
    availableLobbies.draw(renderWindow);
}

void Lobbyoverview::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    createandjoinClick.listen(event, renderWindow);
    joinClick.listen(event, renderWindow);
    updateClick.listen(event, renderWindow);
    backClick.listen(event, renderWindow);
    nameText.listen(event, renderWindow);
    usernameClick.listen(event, renderWindow);
    lobbynameClick.listen(event, renderWindow);
}

void Lobbyoverview::display(std::list<std::string> lobbyNames) {
    userName.mEdit = true;
    sf::String availablelobbiesText("");
    if(!lobbyNames.empty()) {
        for(std::string &name: lobbyNames) {
            availablelobbiesText += name + "\n";
        }
    }
    availableLobbies.setText(availablelobbiesText);
}
