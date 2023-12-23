#include "Character.h"
const float Character::BalloonHeightAdjustment = 85.0f;

void Character::receiveBalloon(Balloon * theBalloon)
{

	this->aBallon = theBalloon;
	this->aBallon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f); // 85.0 is the height of the Balloon, should use a memberfunction in Balloon for this
}

Character::Character(float windowWidth, float windowHeight, sf::Color color, 
	float width, float height, float speed, int health)
	:rectShape(sf::Vector2f(width,height)), aBallon(nullptr), speed(speed), health(health)
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
//new changes:
sf::Vector2f Character::getPosition() const
{
	return this->rectShape.getPosition();
}

sf::Vector2f Character::getSize() const
{
	return this->rectShape.getSize();
}

void Character::setPosition(float x, float y)
{
	this->rectShape.setPosition(x, y);
	if (this->aBallon != nullptr) {
		this->aBallon->setPosition(this->rectShape.getGlobalBounds().left,
			this->rectShape.getGlobalBounds().top - BalloonHeightAdjustment);
	}
}

bool Character::isCollidingWith(const Bullet& bullet)
{
	//this->health--;
	return this->rectShape.getGlobalBounds().intersects(bullet.getBounds());
}

void Character::takeDamage(int damage)
{
	this->health -= damage;
	/*if (health <= 0) {
		std::cout << "Player has been defeated!" << std::endl;
	}*/
}

sf::FloatRect Character::getBounds() const
{
	return this->rectShape.getGlobalBounds();
}
