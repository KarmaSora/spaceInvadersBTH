#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Balloon.h"
#include "Bullet.h"

class Character : public Entity {
private:
    Balloon* aBalloon;
    static const float BalloonHeightAdjustment;

    int health;

public:
    Character();
    //Character(float windowWidth, float windowHeight, sf::Color color, float width, float height, float speed = 5.0f, int health = 3);
    Character(std::string texturePath, float xPos, float yPos, int speed, bool alive, int dX, int dY, float windowWidth, float windowHeight,int health = 3);
   //Entity(sf::Texture texture, float xPos, float yPos, int speed, bool alive, int dX, int dY, float windowWidth, float windowHeight);

    void act();
    void receiveBalloon(Balloon* theBalloon) ;
    void releaseBalloon();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    // New getters, setters
    sf::Vector2f getPosition() const override;
    sf::Vector2f getSize() const ;
    void setPosition(float x, float y) override;

    bool isCollidingWith(const Bullet& bullet);
    void takeDamage(int damage);
    sf::FloatRect getBounds() const;

    int getHealth() const;

    void updateMovement() override;
};

/*
//#pragma once
//#include <SFML/Graphics.hpp>
//#include "Balloon.h"
//#include "Bullet.h"
//
//class Character :public sf::Drawable
//{
//private:
//	sf::RectangleShape rectShape;
//	float speed;
//	Balloon *aBallon;
//	void releaseBalloon();
//	//new
//	static const float BalloonHeightAdjustment;
//
//	int health;
//public:
//
//	Character(float windowWidth, float windowHeight, sf::Color color, float width, float height, float speed = 5.0f, int health = 3);
//	void act();
//	void receiveBalloon(Balloon *theBalloon);
//	// Inherited via Drawable
//	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
//
//	//new getters, setters
//	sf::Vector2f getPosition() const;
//	sf::Vector2f getSize() const;
//	void setPosition(float x, float y);
//	
//	bool isCollidingWith(const Bullet& bullet);
//	void takeDamage(int damage);
//	sf::FloatRect getBounds() const;
//
//	int getHealth() const;
//};

*/