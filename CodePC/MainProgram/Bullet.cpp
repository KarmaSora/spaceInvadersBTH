#include "Bullet.h"

Bullet::Bullet()
	: speed(0.f), active(false), damage(0), hasHitCharacter(false)
{
	initShape();
}

Bullet::Bullet(float startX, float startY, float speed, float damage)
	: speed(speed), active(true), damage(damage), hasHitCharacter(false)
{
	initShape();
	shape.setPosition(startX, startY);
}


void Bullet::update(float deltaTime)
{
	float movement = speed * deltaTime;
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
	return active;
}

void Bullet::deactivate()
{
	active = false;
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

void Bullet::initShape()
{
	shape.setSize(sf::Vector2f(5, 10));
	shape.setFillColor(sf::Color::Red);
}
