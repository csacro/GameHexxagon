/**
 * @author Carolin Schindler
 */


#include <SFMLComponents/Window/ListenerRenderWindow.h>
#include <iostream>
#include "ViewHandler/ViewHandler.h"
#include "Views/Mainmenu.h"
#include "Views/Lobbyoverview.h"
#include "Views/Lobbyview.h"

int main() {
    setenv("DISPLAY", "127.0.0.1:0", true);

    ListenerRenderWindow lrw(sf::VideoMode::getDesktopMode(), "Hexxagon", sf::Style::Fullscreen);

    sf::Font arial;
    if (!arial.loadFromFile("../../res/fonts/arial.ttf")) {
        std::cout << "cannot load font" << std::endl;
    }

    Mainmenu m;
    Lobbyoverview lo;
    Lobbyview l;

    ViewHandler v(lrw, m, lo, l);

    m = Mainmenu(v, arial, lrw.getSize());
    lo = Lobbyoverview(v, arial, lrw.getSize());
    l = Lobbyview(v, arial, lrw.getSize());

    lrw.run(sf::Color::Cyan);
}
