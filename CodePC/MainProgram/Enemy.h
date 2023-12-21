#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
public:
    sf::RectangleShape shape;
    bool isAlive;

    Enemy(float x, float y, const sf::Texture& texture) {
        shape.setSize(sf::Vector2f(60.0f, 60.0f));
        shape.setPosition(x, y);
        shape.setTexture(&texture);
        isAlive = true;
    }

    void move(float offsetX, float offsetY) {
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow& window) {
        if (isAlive) {
            window.draw(shape);
        }
    }
};





#endif