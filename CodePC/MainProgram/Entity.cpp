#include "Entity.h"

Entity::Entity()
	: texturePath("../../CodePC/Images/BlueBalloon.png"), xPos(400.f), yPos(532.f), speed(5.f), alive(false), dX(0), dY(0), widthHeight(900, 600)

{
	sf::Texture tex;

	tex.loadFromFile(this->texturePath);
	this->setTexture(tex);
	this->rectShape.setFillColor(sf::Color::Green);


}


Entity::Entity(std::string texturePath, float xPos, float yPos, float speed, bool alive, int dX, int dY, float windowWidth, float windowHeight)
	: texturePath(texturePath), xPos(xPos), yPos(yPos), speed(speed), alive(alive), dX(dX), dY(dY), widthHeight(windowWidth, windowHeight)
{
	this->texture.loadFromFile(this->texturePath);
	this->setTexture(this->texture);


}



sf::Vector2f Entity::getPosition()
{
	return this->rectShape.getPosition();
}

void Entity::setPosition(float xPos, float yPos)
{
	this->rectShape.setPosition(xPos, yPos);
}

void Entity::setSize(const sf::Vector2f size)
{
	this->rectShape.setSize(size);
}

sf::Vector2f Entity::getSize()
{
	return this->rectShape.getSize();
}

sf::FloatRect Entity::getGlobalBounds()
{
	return this->rectShape.getGlobalBounds();
}




//Setters&Getters
void Entity::setXPos(float xPos) {
	this->xPos = xPos;
	this->xPos = xPos;
	setPosition(xPos, this->yPos);
}
void Entity::setYPos(float yPos) {
	this->yPos = yPos;
	setPosition(this->xPos, yPos);

}
void Entity::setTexture(const sf::Texture& texture, bool resetRect) {
	this->texture = texture;
	this->rectShape.setTexture(&this->texture, resetRect);
}
void Entity::setSpeed(float newSpeed) {
	this->speed = newSpeed;
}

void Entity::setAlive(bool isAlive) {
	this->alive = isAlive;
}

void Entity::setPosOfRect(float xPos, float yPos)
{
	this->rectShape.setPosition(xPos, yPos);
}
void Entity::setFillColor(sf::Color color)
{
	this->rectShape.setFillColor(color);
}
sf::Color Entity::getFillColor()
{
	return this->rectShape.getFillColor();
}
void Entity::move(float offsetX, float offsetY)
{
	this->rectShape.move(offsetX, offsetY);
}
// Setters for widthHeight
void Entity::setWidth(float width) {
	this->widthHeight.x = width;
}

void Entity::setHeight(float height) {
	this->widthHeight.y = height;
}


void Entity::updateMovement()
{
	this->xPos += (this->speed * this->dX);
	this->yPos += (this->speed * this->dY);
	this->rectShape.setPosition(xPos, yPos);




}
void Entity::setDX(const int dX)
{
	this->dX = dX;
}
void Entity::setDY(const int dY)
{
	this->dY = dY;
}

// Getters for widthHeight
sf::Vector2f Entity::getWidthHeight() const {
	return this->widthHeight;
}

float Entity::getWidth() const {
	return this->widthHeight.x;
}

float Entity::getHeight() const {
	return this->widthHeight.y;
}


float Entity::getPosXOfRect()
{
	return this->rectShape.getPosition().x;
}


float Entity::getPosYOfRect()
{
	return this->rectShape.getPosition().y;
}

// Getters for position
sf::Vector2f Entity::getPosition() const {
	return this->rectShape.getPosition();
}

int Entity::getDX() const
{
	return this->dX;
}

int Entity::getDY() const
{
	return this->dY;
}




const sf::Texture& Entity::getTexture() const
{
	return this->texture;
}

float Entity::getSpeed() const
{
	return this->speed;
}


bool Entity::isAlive() const
{
	return this->alive;
}

void Entity::setOutlineColor(sf::Color color)
{
	this->rectShape.setOutlineColor(color);
}

void Entity::setOutlineThickness(float thickness)
{
	this->rectShape.setOutlineThickness(thickness);
}



void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->rectShape);


}
