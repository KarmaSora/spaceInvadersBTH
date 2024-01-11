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
	shape.setPosition(startX, startY);
}


void Bullet::update(float deltaTime)
{
	float movement = Entity::getSpeed() * deltaTime;
	shape.move(0.f, movement);
	if (shape.getPosition().y > 600.f) {
		deactivate();
	}
}

void Bullet::draw(sf::RenderWindow& window) const
{
	window.draw(shape);
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

sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

sf::Vector2f Bullet::getPosition() const
{
	return this->shape.getPosition();
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
	update(0.0f);
}

void Bullet::initShape()
{
	shape.setSize(sf::Vector2f(5, 10));
	shape.setFillColor(sf::Color::Red);
}
