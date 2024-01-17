#pragma once
#include "Balloon.h"
#include "Bullet.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Character : public Entity {
private:
	Balloon* aBalloon;
	static const float BALLOONHEIGHTADJUSTMENT;

	int health;

public:
	Character();

	void act();
	void receiveBalloon(Balloon* theBalloon);
	void releaseBalloon();


	void setPosition(float xPos, float yPos); //tog bort override


	bool isCollidingWith( Bullet& bullet);
	void takeDamage(int damage);
	sf::FloatRect getBounds();

	int getHealth() const;
	void updateMovement() override;		//override sker  -> dynamisk binding
};
