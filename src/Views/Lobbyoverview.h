/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_LOBBYOVERVIEW_H
#define GAMEHEXXAGON_LOBBYOVERVIEW_H


#include <SFMLComponents/Elements/Button.h>
#include <SFMLComponents/Elements/EditField.h>
#include <SFMLComponents/Listener/OnClickListener.h>
#include <SFMLComponents/Listener/OnTextListener.h>
#include "ViewToLobbyoverview.h"
#include "../ViewHandler/LobbyoverviewToView.h"

class Lobbyoverview: public ViewToLobbyoverview {
public:
    /**
     * default Constructor
     */
    Lobbyoverview() = default;

    /**
     * Constructor
     * @param lotv LobbyoverviewToView to communicate with ViewHandler
     * @param font sf::Font used to display sf::Text
     * @param windowSize sf::Vector2u which is size of sf::RenderWindow
     */
    Lobbyoverview(LobbyoverviewToView &lotv, sf::Font &font, sf::Vector2u windowSize);

    void draw(sf::RenderWindow &renderWindow) override;

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;

    void display(std::list<std::string> lobbyNames) override;

private:
    inline static LobbyoverviewToView *mToView; //interface to ViewHandler

    //Elements
    inline static EditField userName; //Field to input name of User
    inline static EditField lobbyName; //Field to input name of Lobby
    inline static Button createAndJoin; //Button to create and join Lobby with lobbyName and userName
    inline static Button join; //Button to join Lobby with lobbyName and userName
    inline static Button update; //Button to update list of available Lobbies
    inline static Button back; //Button to go back to Mainmenu
    inline static TextField availableLobbies; //Field to display available Lobbies

    //Listener
    inline static OnClickListener createandjoinClick; //for createAndJoin
    inline static OnClickListener joinClick; //for join
    inline static OnClickListener updateClick; //for update
    inline static OnClickListener backClick; //for back
    inline static OnTextListener nameText; //text input (to userName or lobbyName)
    inline static OnClickListener usernameClick; //for userName
    inline static OnClickListener lobbynameClick; //for lobbyName

    //Listener methods
    static void createandjoinClickFunction(Listener *listener);
    static void joinClickFunction(Listener *listener);
    static void updateClickFunction(Listener *listener);
    static void backClickFunction(Listener *listener);
    static void nameTextFunction(Listener *listener);
    static void usernameClickFunction(Listener *listener);
    static void lobbynameClickFunction(Listener *listener);
};


#endif //GAMEHEXXAGON_LOBBYOVERVIEW_H
