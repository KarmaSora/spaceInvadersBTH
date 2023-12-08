#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

class Balloon :public sf::Drawable
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
	bool collidedWith(const Obstacle& obstacle);
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const override;
};
