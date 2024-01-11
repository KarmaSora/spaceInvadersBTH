#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Bullet : public Entity{
public:
    Bullet();
    Bullet(float startX, float startY, float speed, int damage);

    // Update the bullet's position
    void update(float deltaTime);

    // Draw the bullet on the window
    void draw(sf::RenderWindow& window) const;

    // Check if the bullet is currently active
    bool isActive() const;

    // Set the bullet to inactive
    void deactivate();

    int getDamage() const;
    sf::FloatRect getBounds() const;

    sf::Vector2f getPosition() const;

    bool hasHit() const;
    void markAsHit();

    void updateMovement() override;
private:
    // Bullet attributes
    sf::RectangleShape shape;
    bool hasHitCharacter;  //Flag to track
    int damage;

    //Private helper method to set the bullet's appearance
    void initShape();
};




#endif