#include "Entity.h"

Entity::Entity()
	: alive(false), dX(0), dY(0), speed(10), xPos(400.f), yPos(400.f)
{

}

Entity::Entity(sf::Image image, int xPos, int yPos, int speed, int dX, int dY, bool alive)
	: image(image), xPos(xPos), yPos(yPos), speed(speed), dX(dX), dY(dY), alive(alive)
{
	

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
