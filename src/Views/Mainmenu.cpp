/**
 * @author Carolin Schindler
 */

#include "Mainmenu.h"

Mainmenu::Mainmenu(MainmenuToView &mtv, sf::Font &font, sf::Vector2u windowSize) {
    mToView = &mtv;

    unsigned int width = windowSize.x;
    unsigned int height = windowSize.y;
    sf::String initText("");

    //Elements
    sf::Vector2i pos(width*0.45, height*0.45);
    sf::String serverDefaultText("localhost:4444");
    server = EditField(pos, serverDefaultText, font, 0, 0);

    pos.y = height*0.5;
    connection = Button(pos, initText, font, 0, 0);

    pos.x = width*0.9;
    pos.y = height*0.9;
    sf::String lobbyoverviewText("START");
    lobbyoverview = Button(pos, lobbyoverviewText, font, 0, 0);

    pos.x = width*0.8;
    sf::String endText("END");
    end = Button(pos, endText, font, 0, 0);


    //Listener
    connectionClick = OnClickListener(connection, connectionClickFunction);
    lobbyoverviewClick = OnClickListener(lobbyoverview, lobbyoverviewClickFunction);
    endClick = OnClickListener(end, endClickFunction);
    serverText = OnTextListener(serverTextFunction);


    display(false);
}


void Mainmenu::connectionClickFunction() {
    if(connection.getText() == "CONNECT") {
        mToView->connectServer(server.getText());
    } else {
        mToView->disconnectServer();
    }
}

void Mainmenu::lobbyoverviewClickFunction() {
    mToView->showLobbyoverview();
}

void Mainmenu::endClickFunction() {
    mToView->close();
}

void Mainmenu::serverTextFunction() {
    server.addText(serverText.mLastText);
}


void Mainmenu::draw(sf::RenderWindow &renderWindow) {
    server.draw(renderWindow);
    connection.draw(renderWindow);
    lobbyoverview.draw(renderWindow);
    end.draw(renderWindow);
}

void Mainmenu::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    connectionClick.listen(event, renderWindow);
    lobbyoverviewClick.listen(event, renderWindow);
    endClick.listen(event, renderWindow);
    serverText.listen(event, renderWindow);
}

void Mainmenu::display(bool isConnected) {
    if(!isConnected) {
        server.mEdit = true;
        lobbyoverview.isVisible = false;
        sf::String connectionText("CONNECT");
        connection.setText(connectionText);
    } else {
        server.mEdit = false;
        lobbyoverview.isVisible = true;
        sf::String connectionText("DISCONNECT");
        connection.setText(connectionText);
    }
}
