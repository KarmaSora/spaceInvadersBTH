#include "Balloon.h"
#include <iostream>

Balloon::Balloon(float speed)
	:speed(speed), moves(false)
{
	this->texture.loadFromFile("../Images/BlueBalloon.png");
	this->sprite.setTexture(this->texture);
}

void Balloon::go()
{
	this->moves = true;
}

bool Balloon::isMoving() const
{
	return moves;
}
void Balloon::move()
{
	this->sprite.move(0, -this->speed);
}

bool Balloon::insideWindow() const
{
	return this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height > 0;
}

void Balloon::stopMoving()
{
	this->moves = false;
}

void Balloon::setPosition(float xPos, float yPos)
{
	this->sprite.setPosition(xPos, yPos);
}

float Balloon::getPosX() const
{
	return this->sprite.getPosition().x;

}

float Balloon::getPosY() const
{
	return this->sprite.getPosition().y;
	

}

sf::Sprite Balloon::getSprite() const
{
	return this->sprite;
}

bool Balloon::collidedWith(const Obstacle& obstacle)
{
	return this->sprite.getGlobalBounds().intersects(obstacle.getBounds());
}

bool Balloon::collidedWith( Enemy& enemy)
{
	return this->sprite.getGlobalBounds().intersects(enemy.getBounds());
}

void Balloon::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}
