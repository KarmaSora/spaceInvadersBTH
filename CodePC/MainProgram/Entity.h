#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Drawable {
private:
    float xPos, yPos;
    sf::Image image;
    int height, width;
    int speed;
    int dX, dY;
    bool alive;

public:
    // Constructor and other member functions...

    // Setters
    void setX(float x) { xPos = x; }
    void setY(float y) { yPos = y; }
    void setImage(const sf::Image& newImage) { image = newImage; }
    void setHeight(int newHeight) { height = newHeight; }
    void setWidth(int newWidth) { width = newWidth; }
    void setSpeed(int newSpeed) { speed = newSpeed; }
    void setDX(int newDX) { dX = newDX; }
    void setDY(int newDY) { dY = newDY; }
    void setAlive(bool isAlive) { alive = isAlive; }

    // Getters
    float getX() const { return xPos; }
    float getY() const { return yPos; }
    const sf::Image& getImage() const { return image; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }
    int getSpeed() const { return speed; }
    int getDX() const { return dX; }
    int getDY() const { return dY; }
    bool isAlive() const { return alive; }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
