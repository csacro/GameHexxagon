/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_MAINMENU_H
#define GAMEHEXXAGON_MAINMENU_H


#include <SFMLComponents/Elements/Button.h>
#include <SFMLComponents/Elements/EditField.h>
#include <SFMLComponents/Listener/OnClickListener.h>
#include <SFMLComponents/Listener/OnTextListener.h>
#include "ViewToMainmenu.h"
#include "../ViewHandler/MainmenuToView.h"

class Mainmenu: public ViewToMainmenu {
public:
    /**
     * default Constructor
     */
     Mainmenu() = default;

    /**
     * Constructor
     * @param mtv MainmenuToView to communicate with ViewHandler
     * @param font sf::Font used to display sf::Text
     * @param windowSize sf::Vector2u which is size of sf::RenderWindow
     */
    Mainmenu(MainmenuToView &mtv, sf::Font &font, sf::Vector2u windowSize);

    void draw(sf::RenderWindow &renderWindow) override;

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;

    void display(bool isConnected) override;

private:
    inline static MainmenuToView *mToView; //interface to ViewHandler

    //Elements
    inline static EditField server; //Field to input address to connect to if not connected
    inline static Button connection; //Button to connect with server or disconnect if connected
    inline static Button lobbyoverview; //Button to switch to Lobbyoverview
    inline static Button end; //Button to close Window

    //Listener
    inline static OnClickListener connectionClick; //for connection
    inline static OnClickListener lobbyoverviewClick; //for lobbyoverview
    inline static OnClickListener endClick; //for end
    inline static OnTextListener serverText; //text input (to server)

    //Listener methods
    static void connectionClickFunction(Listener *listener);
    static void lobbyoverviewClickFunction(Listener *listener);
    static void endClickFunction(Listener *listener);
    static void serverTextFunction(Listener *listener);
};


#endif //GAMEHEXXAGON_MAINMENU_H
