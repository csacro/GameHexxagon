/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_LOBBYVIEW_H
#define GAMEHEXXAGON_LOBBYVIEW_H


#include <SFMLComponents/Elements/TextField.h>
#include <SFMLComponents/Elements/Button.h>
#include <SFMLComponents/Listener/OnClickListener.h>
#include "ViewToLobbyview.h"
#include "../ViewHandler/LobbyviewToView.h"

class Lobbyview: public ViewToLobbyview {
public:
    /**
     * default Constructor
     */
    Lobbyview() = default;

    /**
     * Constructor
     * @param ltv LobbyviewToView to communicate with ViewHandler
     * @param font sf::Font used to display sf::Text
     * @param windowSize sf::Vector2u which is size of sf::RenderWindow
     */
    Lobbyview(LobbyviewToView &ltv, sf::Font &font, sf::Vector2u windowSize);

    void draw(sf::RenderWindow &renderWindow) override;

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;

    void display(std::string lobbyName, std::string playerOneUserName, std::string playerTwoUserName,
                 bool isStartable) override;

private:
    inline static LobbyviewToView *mToView; //interface to ViewHandler

    //Elements
    inline static TextField lobbyname; //Field to display name of Lobby User is in
    inline static TextField playerOneUsername; //Field to display name of PlayerOne in Lobby
    inline static TextField playerTwoUsername; //Field to display name of PlayerTwo in Lobby
    inline static Button leave; //Button to leave Lobby
    inline static Button start; //Button to start Game

    //Listener
    inline static OnClickListener leaveClick; //for leave
    inline static OnClickListener startClick; //for start

    //Listener methods
    static void leaveClickFunction();
    static void startClickFunction();
};


#endif //GAMEHEXXAGON_LOBBYVIEW_H
