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


    int speed, dX , dY;
    bool alive;

public:
    // Constructor and other member functions...
    Entity();
    //Entity(sf::Texture texture, int xPos, int yPos, int speed, int dX, int dY, bool alive);
    Entity(sf::Texture texture, int xPos, int yPos, int speed, bool alive, int dX, int dY);
   

    //to make the class abstract
    /*
    update the xPos and yPos of entity.
    */
    virtual void updateMovment() = 0;

    //Setters&Getters
        // Setters
        // Setters for position
    void setDX(const int dX);
    void setDY(const int dY);
    void setPosition(float xPos, float yPos);
    void setXPos(float xPos);
    void setYPos(float yPos);
    void setTexture(const sf::Texture& texture);
    void setSpeed(int newSpeed);
    void setAlive(bool isAlive);
    void setSprite(const sf::Sprite& newSprite);
        // Setters for widthHeight
    void setWidth(float width);
    void setHeight(float height);


        // Getters
    int getDX() const;
    int getDY() const;
    float getXPos() const;
    float getYPos() const;
    const sf::Texture& getTexture() const;
    int getSpeed() const;

    bool isAlive() const;
    const sf::Sprite& getSprite() const;

    // Getters for widthHeight
    sf::Vector2f getWidthHeight() const;
    float getWidth() const;
    float getHeight() const;

    // Getters for position
    sf::Vector2f getPosition() const;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
