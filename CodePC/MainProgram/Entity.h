#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Drawable {

protected:
    /*Code suggested by Betty
    void moveRectShape(float x, float y);
    */
    //sf::RectangleShape rectShape;
    
private:
    sf::RectangleShape rectShape;

    float xPos, yPos;
    //sf::Image image;
    sf::Texture texture;
    std::string texturePath;
    //sf::Sprite sprite;
    sf::Vector2f widthHeight;
    sf::Vector2f position;


    int speed, dX , dY;
    bool alive;

public:
    // Constructor and other member functions...
    Entity();
    Entity(std::string texturePath, float xPos, float yPos, int speed, bool alive, int dX, int dY, float windowWidth, float windowHeight);
   
    //functions to contorl sf::rectangle rectShape
    sf::RectangleShape getRectangle();
    void setRectangle(const sf::RectangleShape &rectShape);
    sf::Vector2f getPosition();
    //virtual void setPosition(float xPos, float yPos);
    void setSize(const sf::Vector2f size);
    sf::Vector2f getSize();
    sf::FloatRect getGlobalBounds();


    //to make the class abstract
    /*
    update the xPos and yPos of entity.
    */
    virtual void updateMovement() = 0; 

    //Setters&Getters
        // Setters
        // Setters for position
    void setDX(const int dX);
    void setDY(const int dY);
    virtual void setPosition(float xPos, float yPos); 
    void setXPos(float xPos);
    void setYPos(float yPos);
    void setTexture(const sf::Texture& texture, bool resetRect=false);
    void setSpeed(int newSpeed);
    void setAlive(bool isAlive);
    void setPosOfRect(float xPos, float yPos);
    void setFillColor(sf::Color color);
    sf::Color getFillColor();
    virtual void move(float offsetX, float offsetY);


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

    // Getters for widthHeight
     sf::Vector2f getWidthHeight() const;
     float getWidth() const;
     float getHeight() const;

      float getPosXOfRect();
      float getPosYOfRect();

    // Getters for position
     virtual sf::Vector2f getPosition() const;

     void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
