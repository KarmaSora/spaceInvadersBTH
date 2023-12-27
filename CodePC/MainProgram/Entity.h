#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Drawable {

protected:
    sf::RectangleShape rectShape;
private:
    float xPos, yPos;
    //sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f widthHeight;
    sf::Vector2f position;

    int speed;
    int dX, dY;
    bool alive;

public:
    // Constructor and other member functions...
    Entity();
    Entity(sf::Texture texture, int xPos, int yPos, int speed, int dX, int dY, bool alive);
    // Setters
    void setX(float x) { xPos = x; }
    void setY(float y) { yPos = y; }
    //void setImage(const sf::Image& newImage) { image = newImage; }
    void setTexture(const sf::Texture& texture) { this->texture = texture; }
    //void setHeight(int newHeight) { height = newHeight; }
    //void setWidth(int newWidth) { width = newWidth; }
    void setSpeed(int newSpeed) { speed = newSpeed; }
    void setDX(int newDX) { dX = newDX; }
    void setDY(int newDY) { dY = newDY; }
    void setAlive(bool isAlive) { alive = isAlive; }
    void setSprite(const sf::Sprite& newSprite) { sprite = newSprite; }
    // Setters for widthHeight
    void setWidth(float width) {
        widthHeight.x = width;
    }

    void setHeight(float height) {
        widthHeight.y = height;
    }
    // Setters for position
    void setPosition(float x, float y) {
        position.x = x;
        position.y = y;
    }


    // Getters
    float getX() const { return xPos; }
    float getY() const { return yPos; }
    //const sf::Image& getImage() const { return image; }
    const sf::Texture& getImage() const { return this->texture; }
    //int getHeight() const { return height; }
    //int getWidth() const { return width; }
    int getSpeed() const { return speed; }
    int getDX() const { return dX; }
    int getDY() const { return dY; }
    bool isAlive() const { return alive; }
    const sf::Sprite& getSprite() const { return sprite; }  

    // Getters for widthHeight
    sf::Vector2f getWidthHeight() const {
        return widthHeight;
    }

    float getWidth() const {
        return widthHeight.x;
    }

    float getHeight() const {
        return widthHeight.y;
    }

    // Getters for position
    sf::Vector2f getPosition() const {
        return position;
    }

    float getXPos() const {
        return position.x;
    }

    float getYPos() const {
        return position.y;
    }




    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
