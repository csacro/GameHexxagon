/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_GAMEVIEW_H
#define GAMEHEXXAGON_GAMEVIEW_H


#include <SFMLComponents/Elements/TextField.h>
#include <SFMLComponents/Elements/Button.h>
#include <SFMLComponents/Listener/OnClickListener.h>
#include "ViewToGameview.h"
#include "../ViewHandler/GameviewToView.h"

class Gameview: public ViewToGameview {
public:
    /**
     * default Constructor
     */
    Gameview() = default;

    /**
     * Constructor
     * @param gtv GameviewToView to communicate with ViewHandler
     * @param font sf::Font used to display sf::Text
     * @param windowSize sf::Vector2u which is size of sf::RenderWindow
     */
    Gameview(GameviewToView &gtv, sf::Font &font, sf::Vector2u windowSize);

    void draw(sf::RenderWindow &renderWindow) override;

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;

    void displayPlayerNames(std::string playerOneUserName, std::string playerTwoUserName) override;

    void display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                 ModelBoard::Board board, bool isTurn) override;

    void display(std::string playerOnePoints, std::string playerTwoPoints, TileEnum moveFrom, TileEnum moveTo,
                 ModelBoard::Board board, bool isTie, bool isWinner) override;

private:
    void displayPlayerPoints(std::string &playerOnePoints, std::string &playerTwoPoints);

    inline static GameviewToView *mToView; //interface to ViewHandler

    //Elements
    //TODO: spielfeld
    inline static TextField playerOneUsername; //TextField to display name of playerOne
    inline static TextField playerTwoUsername; //TextField to display name of playerTwo
    inline static TextField playerOnepoints; //TextField to display points of playerOne
    inline static TextField playerTwopoints; //TextField to display points of playerTwo
    inline static Button leave; //Button to leave Game

    //Listener
    //TODO: spielfeld
    inline static OnClickListener leaveClick; //for leave

    //Listener methods
    //TODO: spielfeld
    static void leaveClickFunction(Listener *listener);
};


#endif //GAMEHEXXAGON_GAMEVIEW_H
