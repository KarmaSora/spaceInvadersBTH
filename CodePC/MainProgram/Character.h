#pragma once
#include <SFML/Graphics.hpp>
#include "Balloon.h"

class Character :public sf::Drawable
{
private:
	sf::RectangleShape rectShape;
	float speed;
	Balloon *aBallon;
	void releaseBalloon();
public:
	Character(float windowWidth, float windowHeight, sf::Color color, float width, float height,
		float speed = 5.0f);
	void act();
	void receiveBalloon(Balloon *theBalloon);
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};
