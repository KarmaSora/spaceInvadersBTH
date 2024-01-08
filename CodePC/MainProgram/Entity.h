#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Drawable {

protected:
    sf::RectangleShape rectShape;
    void moveRectShape(float x,float y);
    
private:
    //sf::RectangleShape rectShape;
    float xPos, yPos;
    //sf::Image image;
    sf::Texture texture;
    std::string texturePath;
    sf::Sprite sprite;
    sf::Vector2f widthHeight;
    sf::Vector2f position;


    int speed, dX , dY;
    bool alive;

public:
    // Constructor and other member functions...
    Entity();
    //Entity(sf::Texture texture, int xPos, int yPos, int speed, int dX, int dY, bool alive);
    //Entity(sf::Texture texture, float xPos, float yPos, int speed, bool alive, int dX, int dY, float windowWidth, float windowHeight);
    Entity(std::string texturePath, float xPos, float yPos, int speed, bool alive, int dX, int dY, float windowWidth, float windowHeight);
   

    //to make the class abstract
    /*
    update the xPos and yPos of entity.
    */
    virtual void updateMovement() = 0;

    //Setters&Getters
        // Setters
        // Setters for position
    virtual void setDX(const int dX);
    virtual void setDY(const int dY);
    virtual void setPosition(float xPos, float yPos);
    virtual void setXPos(float xPos);
    virtual void setYPos(float yPos);
     void setTexture(const sf::Texture& texture);
    virtual void setSpeed(int newSpeed);
    virtual void setAlive(bool isAlive);
    virtual void setSprite(const sf::Sprite& newSprite);
    virtual void setPosOfSprite(float xPos, float yPos);
    virtual void setPosOfRect(float xPos, float yPos);

    
        // Setters for widthHeight
    virtual void setWidth(float width);
    virtual void setHeight(float height);


        // Getters
   virtual int getDX() const;
   virtual int getDY() const;
   virtual float getXPos() const;
   virtual float getYPos() const;
   virtual const sf::Texture& getTexture() const;
   virtual int getSpeed() const;

   virtual bool isAlive() const;
   virtual const sf::Sprite& getSprite() const;

    // Getters for widthHeight
    virtual sf::Vector2f getWidthHeight() const;
    virtual float getWidth() const;
    virtual float getHeight() const;

     virtual float getPosXOfSprite();
     virtual float getPosXOfRect();
     virtual float getPosYOfSprite();
     virtual float getPosYOfRect();

    // Getters for position
    virtual sf::Vector2f getPosition() const;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
