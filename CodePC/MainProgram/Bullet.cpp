#include "Bullet.h"

Bullet::Bullet()
	: damage(1), hasHitCharacter(false)
{
	Entity::setSpeed(0.f);
	Entity::setAlive(false);
	initShape();
}

Bullet::Bullet(float startX, float startY, float speed, int damage)
	: damage(damage), hasHitCharacter(false)
{
	Entity::setSpeed(speed);
	Entity::setAlive(true);
	initShape();
	//shape.setPosition(startX, startY);
	Entity::setPosition(startX, startY);
}





bool Bullet::isActive() const
{
	return Entity::isAlive();
}

void Bullet::deactivate()
{
	Entity::setAlive(false);
}


int Bullet::getDamage() const
{
	return this->damage;
}

sf::FloatRect Bullet::getBounds() 
{

	return Entity::getGlobalBounds();
}

sf::Vector2f Bullet::getPosition() const
{
	return Entity::getPosition();
}

bool Bullet::hasHit() const
{
	return hasHitCharacter;
}

void Bullet::markAsHit()
{
	hasHitCharacter = true;
}

void Bullet::updateMovement()
{
	float movement = Entity::getSpeed() + 0.5f;
	Entity::move(0.f, movement);
	if (Entity::getPosition().y > 600.f) {
		deactivate();
	}
}

void Bullet::initShape()
{
	Entity::setSize(sf::Vector2f(5, 10));
	Entity::setFillColor(sf::Color::Red);
	Entity::setOutlineColor(sf::Color::White);
	Entity::setOutlineThickness(1.f);
}
