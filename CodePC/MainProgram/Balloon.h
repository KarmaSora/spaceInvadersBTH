#pragma once
#include "Enemy.h"
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

class Balloon : public sf::Drawable
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
	bool moves;
public:
	Balloon(float speed = 4.0f);
	void go();
	bool isMoving() const;
	void move();
	bool insideWindow() const;
	void stopMoving();
	void setPosition(float xPos, float yPos);
	float getPosX() const;
	float getPosY() const;
	sf::Sprite getSprite() const;
	bool collidedWith(const Obstacle& obstacle);
	bool collidedWith(Enemy& enemy);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
