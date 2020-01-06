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

    lrw.run(sf::Color::Cyan);

    exit(0);

    //TODO: Thread for Client !?!?!?
    //TODO: Doxygen ???
    //TODO: SonarQube ???
    //TODO: Docker ???

    /*TODO: write tests
     * Schreiben Sie Unit-Tests mindestens f¨ur folgende Funktionalit¨aten des Spiels: Senden und Empfangen von
     * Nachrichten, Einhaltung der Spielregeln.
     * Dies bedeutet f¨ur das Senden und Empfangen von Nachrichten: Testen Sie ob beim Erhalt der Nachricht X die
     * daf¨ur vorgesehene Aktion Y erfolgreich ausgef¨uhrt wird. Testen Sie, ob sich Ihr Programm korrekt verh¨alt, wenn
     * die Nachricht X erwartet wird, allerdings die Nachricht Z empfangen wird. Testen Sie ob eine von Ihnen zu
     * sendende Nachricht X alle im Netzwerkstandard geforderten Eigenschaften besitzt.
     * Dies bedeutet f¨ur die Einhaltung der Spielregeln: Wenn der Spieler zum Beispiel einen Spielzug an Ihre
     * Programmlogik ¨ubergibt, welche diesen Spielzug an den Server ¨ubertragen soll, dann soll Ihre Spiellogik nur
     * valide Spielz¨uge an den Server senden. Pr¨ufen Sie mit Hilfe von Unit-Tests, ob Ihre Programmlogik verbotene
     * Spielz¨uge als solche erkennt und diese zur¨uckweist.
     */
}
