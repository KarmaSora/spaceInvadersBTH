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
	//new
	static const float BalloonHeightAdjustment;
public:
	Character(float windowWidth, float windowHeight, sf::Color color, float width, float height,
		float speed = 5.0f);
	void act();
	void receiveBalloon(Balloon *theBalloon);
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	//new getters, setters
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	void setPosition(float x, float y);
};
