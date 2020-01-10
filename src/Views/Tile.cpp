/**
 * @author Carolin Schindler
 */

#include <iostream>
#include "Tile.h"


Tile::Tile(ModelTileEnum::TileEnum id, float posx, float posy, float radius) {
    mTileId = id;

    mHexagon.setPointCount(6);
    mHexagon.setFillColor(sf::Color::Blue);
    mHexagon.setRadius(radius);
    mHexagon.setPosition(posx, posy);
    mHexagon.setOutlineThickness(0.1*radius);
    mHexagon.setOutlineColor(sf::Color::Transparent);
    mHexagon.setOrigin(radius, radius);

    mStone.setPointCount(50);
    mStone.setFillColor(sf::Color::Transparent);
    mStone.setRadius(0.6*radius);
    mStone.setOrigin(0.6*radius, 0.6*radius);
    mStone.setPosition(mHexagon.getPosition());

    mHexagon.setRotation(360/12);
}

void Tile::setHexagonOutlineColor(sf::Color color) {
    mHexagon.setOutlineColor(color);
}

void Tile::setStoneColor(sf::Color color) {
    mStone.setFillColor(color);
}

sf::Color Tile::getStoneColor() {
    return mStone.getFillColor();
}

bool Tile::isPointInElement(sf::Vector2i point) {
    sf::FloatRect shape = mHexagon.getGlobalBounds();
    return shape.contains(point.x, point.y);
}

void Tile::draw(sf::RenderWindow &renderWindow) {
    if(isVisible) {
        renderWindow.draw(mHexagon);
        renderWindow.draw(mStone);
    }
}
