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

int main() {
    setenv("DISPLAY", "127.0.0.1:0", true);

    ListenerRenderWindow lrw(sf::VideoMode::getDesktopMode(), "Hexxagon", sf::Style::Fullscreen);

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
    Client c;

    ViewHandler v(lrw, m, lo, l, g, d, c);

    d = DataHandler(v);
    c = Client(d);

    m = Mainmenu(v, arial, lrw.getSize());
    lo = Lobbyoverview(v, arial, lrw.getSize());
    l = Lobbyview(v, arial, lrw.getSize());
    g = Gameview(v, arial, lrw.getSize());


    lrw.run(sf::Color(192, 192, 192));

    exit(0);

    //TODO: Thread for Client !?!?!?

    //todo: Doxygen ???
    //todo: SonarQube ???
    //todo: Docker ???

    //TODO: write tests (ViewToData and from_json)
}
