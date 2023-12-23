#include "Bullet.h"
//#include "Bullet.h"
//
//Bullet::Bullet(float startX, float startY, float bulletSpeed)
//    : speed(bulletSpeed), isAlive(true)
//{
//	shape.setSize(sf::Vector2f(5.f, 5.f));
//	shape.setPosition(startX, startY);
//	shape.setFillColor(sf::Color::Red);
//	//shape.setOrigin(5.f, 5.f);
//}
//
//void Bullet::update()
//{
//	if (isAlive) {
//		shape.move(0.f, -speed);
//	}
//}
//
//void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	if (isAlive) {
//		target.draw(shape, states);
//	}
//}
//
//bool Bullet::getIsAlive() const
//{
//	return isAlive;
//}
//
//sf::Vector2f Bullet::getPosition() const
//{
//	return shape.getPosition();
//}
//
//void Bullet::setPosition(float x, float y)
//{
//	shape.setPosition(x, y);
//}

//sf::Vector2f Bullet::getSize() const
//{
//	return shape.getSize();
//}

Bullet::Bullet()
	: speed(0.f), active(false), damage(0)
{
	initShape();
}

Bullet::Bullet(float startX, float startY, float speed, float damage)
	: speed(speed), active(true), damage(damage)
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

//sf::FloatRect Bullet::getGlobalBounds() const
//{
//	return shape.getGlobalBounds();
//}

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

void Bullet::initShape()
{
	shape.setSize(sf::Vector2f(5, 10));
	shape.setFillColor(sf::Color::Red);
}
