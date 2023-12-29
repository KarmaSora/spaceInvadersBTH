#include "Entity.h"

Entity::Entity()
	: alive(false), speed(10), xPos(400.f), yPos(400.f), dX(0), dY(0)
{

}


Entity::Entity(sf::Texture texture, int xPos, int yPos, int speed, bool alive, int dX, int dY)
	: texture(texture), xPos(xPos), yPos(yPos), speed(speed), alive(alive), dX(dX), dY(dY)
{

}



//Setters&Getters
    // Setters
void Entity::setXPos(float xPos) { 
    this->xPos = xPos;
}
void Entity::setYPos(float yPos) {
    this-> yPos = yPos; 
}
void Entity::setTexture(const sf::Texture& texture) { 
    this->texture = texture; 
}
void Entity::setSpeed(int newSpeed) {
    this->speed = newSpeed; 
}

void Entity::setAlive(bool isAlive) {
    this->alive = isAlive; 
}
void Entity::setSprite(const sf::Sprite& newSprite) { 
    this->sprite = newSprite;
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
    this->xPos += this->speed * this->dX;
    this->yPos += this->speed * this->dY;

    this->sprite.setPosition(xPos, yPos);


}
void Entity::setDX(const int dX)
{
    this->dX = dX;
}
void Entity::setDY(const int dY)
{
    this->dY = dY;
}
// Setters for position
void Entity::setPosition(float xPos, float yPos) {
    this->position.x = xPos;
    this->position.y = yPos;
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

// Getters for position
sf::Vector2f Entity::getPosition() const {
    return this->position;
}

int Entity::getDX() const
{
    return this->dX;
}

int Entity::getDY() const
{
    return this->dY;
}

float Entity::getXPos() const {
    return this->position.x;
}

float Entity::getYPos() const {
    return this->position.y;
}

const sf::Texture& Entity::getTexture() const
{
    return this->texture;
}

int Entity::getSpeed() const
{
    return this->speed;
}

bool Entity::isAlive() const
{
    return this->alive;
}

const sf::Sprite& Entity::getSprite() const
{
    return this->sprite;
}


void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->rectShape);


}
