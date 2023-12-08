#include "Obstacle.h"


Obstacle::Obstacle(float windowWidth, float windowHeight, sf::Color color, float radius)
{
	this->circle.setFillColor(color);
	this->circle.setRadius(radius);
	this->circle.setPosition(sf::Vector2f((float)(rand() % (int)windowWidth), (float)(rand() % (int)windowHeight / 2) + 100.f));
}

sf::FloatRect Obstacle::getBounds() const
{
	return this->circle.getGlobalBounds();
}

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->circle);
}
