#include "Character.h"

void Character::receiveBalloon(Balloon * theBalloon)
{
	this->aBallon = theBalloon;
	this->aBallon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f); // 85.0 is the height of the Balloon, should use a memberfunction in Balloon for this
}

Character::Character(float windowWidth, float windowHeight, sf::Color color, float width, float height, float speed)
	:rectShape(sf::Vector2f(width,height)), aBallon(nullptr), speed(speed)
{
	this->rectShape.setFillColor(color);
	this->rectShape.setPosition(windowWidth/2, windowHeight - width);
}

void Character::act()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->rectShape.move(-this->speed, 0);
		if (this->aBallon !=  nullptr)
		{
			this->aBallon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->rectShape.move(this->speed, 0);
		if (this->aBallon != nullptr )
		{
			this->aBallon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f);
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (this->aBallon != nullptr)
		{
			this->releaseBalloon();
		}
	}
}


void Character::releaseBalloon() 
{
	this->aBallon->go();
	this->aBallon = nullptr;
}

void Character::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->rectShape);
}
