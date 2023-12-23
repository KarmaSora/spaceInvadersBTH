#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet{
public:
    Bullet();
    Bullet(float startX, float startY, float speed, float damage);

    // Update the bullet's position
    void update(float deltaTime);

    // Draw the bullet on the window
    void draw(sf::RenderWindow& window) const;

    // Check if the bullet is currently active
    bool isActive() const;

    // Set the bullet to inactive
    void deactivate();

    // Get the global bounds of the bullet for collision detection
    //sf::FloatRect getGlobalBounds() const;

    int getDamage() const;
    sf::FloatRect getBounds() const;

    sf::Vector2f getPosition() const;
private:
    // Bullet attributes
    sf::RectangleShape shape;
    float speed;
    bool active;

    int damage;

    // Private helper method to set the bullet's appearance
    void initShape();
};




#endif