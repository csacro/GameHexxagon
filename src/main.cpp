/**
 * @author Carolin Schindler
 */


#include <SFMLComponents/Window/ListenerRenderWindow.h>
#include <iostream>
#include "ViewHandler/ViewHandler.h"
#include "Views/Mainmenu.h"

int main() {
    ListenerRenderWindow lrw(sf::VideoMode::getDesktopMode(), "Hexxagon", sf::Style::Fullscreen);

    sf::Font arial;
    //todo: change relative path
    if (!arial.loadFromFile("../res/fonts/arial.ttf")) {
        std::cout << "cannot load font" << std::endl;
    }

    Mainmenu m;

    ViewHandler v(lrw, m);

    m = Mainmenu(v, arial, lrw.getSize());

    lrw.run(sf::Color::Cyan);
}
