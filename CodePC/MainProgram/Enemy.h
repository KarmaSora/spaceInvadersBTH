#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
private:
    sf::RectangleShape shape;
    bool isAlive;
    float speed;
    int direction; // 1 for right, -1 for left
public:
    bool getIsAlive() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    Enemy(float x, float y, const sf::Texture& texture);

    void move();
    void changeDirection();
    void update();
    void draw(sf::RenderWindow& window);
};





#endif