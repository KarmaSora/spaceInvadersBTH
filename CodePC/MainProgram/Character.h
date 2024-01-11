#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Balloon.h"
#include "Bullet.h"

class Character : public Entity {
private:
    Balloon* aBalloon;
    static const float BALLOONHEIGHTADJUSTMENT;

    int health;

public:
    Character();
    Character(std::string texturePath, float xPos, float yPos, float speed, bool alive, int dX, int dY, float windowWidth, float windowHeight,int health = 3);

    void act();
    void receiveBalloon(Balloon* theBalloon) ;
    void releaseBalloon();


    // New getters, setters
    void setPosition(float xPos, float yPos) override;


    bool isCollidingWith(const Bullet& bullet);
    void takeDamage(int damage);
    sf::FloatRect getBounds();

    int getHealth() const;

    void updateMovement() override;
};
