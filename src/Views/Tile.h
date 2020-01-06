/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_TILE_H
#define GAMEHEXXAGON_TILE_H


#include <SFMLComponents/Elements/ClickableElement.h>
#include <SFML/Graphics/CircleShape.hpp>
#include "../Model/TileEnum.h"

class Tile: virtual public ClickableElement {
private:
    TileEnum mTileId; //identification for Tile
    sf::CircleShape mHexagon; //background of the Tile
    sf::CircleShape mStone; //Stone positioned on the Tile

public:
    /**
     * default Constructor
     */
    Tile() = default;

    /**
     * Constructor
     * @param id TileEnum that identifies Tile uniquely
     * @param posx float x-position of upper left corner of mHexagon
     * @param posy float y-position of upper left corner of mHexagon
     * @param radius float radius of mHexagon
     */
    Tile(TileEnum id, float posx, float posy, float radius);

    /**
     * changes the color of the Outline of mHexagon
     * @param color sf::Color that should be set to mStone
     */
    void setHexagonOutlineColor(sf::Color color);

    /**
     * changes the color of mStone
     * @param color sf::Color that should be set to mStone
     */
    void setStoneColor(sf::Color color);

    bool isPointInElement(sf::Vector2i point) override;

    void draw(sf::RenderWindow &renderWindow) override;
};


#endif //GAMEHEXXAGON_TILE_H
