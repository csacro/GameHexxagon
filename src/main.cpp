/**
 * @author Carolin Schindler
 */


#include <SFMLComponents/Window/ListenerRenderWindow.h>
#include <iostream>
#include "ViewHandler/ViewHandler.h"
#include "Views/Mainmenu.h"
#include "Views/Lobbyoverview.h"
#include "Views/Lobbyview.h"
#include "Views/Gameview.h"
#include "DataHandler/DataHandler.h"
#include "Client/Client.h"

//TODO: Gameview position of Elements
//TODO: TextField fix positioning (SFMLComponents and maybe "\n")
//todo: atm join not possible -> update; better: join not possible -> update -> try join again


//todo: SFMLComponents thread safe lists in ListenerRenderWindow
//todo: after request block ViewWindow until display

int main() {
    setenv("DISPLAY", "127.0.0.1:0", true);

    ListenerRenderWindow lrw(sf::VideoMode::getDesktopMode(), "Hexxagon", sf::Style::Fullscreen);
    //ListenerRenderWindow lrw(sf::VideoMode(1280, 720/2.2), "Hexxagon", sf::Style::Default);
    //ListenerRenderWindow lrw(sf::VideoMode(2048/2, 1152/2.2), "Hexxagon", sf::Style::Default);

    sf::Font arial;
    if (!arial.loadFromFile("../../res/fonts/arial.ttf")) {
        std::cout << "cannot load font" << std::endl;
        exit(2);
    }

    Mainmenu m;
    Lobbyoverview lo;
    Lobbyview l;
    Gameview g;

    DataHandler d;
    ViewHandler v;

    Client c(d);
    v = ViewHandler(lrw, m, lo, l, g, d, c);
    d = DataHandler(v);

    m = Mainmenu(v, arial, lrw.getSize());
    lo = Lobbyoverview(v, arial, lrw.getSize());
    l = Lobbyview(v, arial, lrw.getSize());
    g = Gameview(v, arial, lrw.getSize());


    lrw.run(sf::Color(192, 192, 192));

    exit(0);
}
