#include "Entity.h"

void Entity::moveRectShape(float x, float y)
{
    rectShape.move(x, y);
}

Entity::Entity()
    : texturePath("../../CodePC/Images/BlueBalloon.png"), xPos(400.f), yPos(532.f), speed(5), alive(false), dX(0), dY(0), widthHeight(900, 600)

{
    sf::Texture tex;

    tex.loadFromFile(this->texturePath);
    this->setTexture(tex);
    //changes the color of given image if any. If image not found then change color of rect to red -Karma
    this->rectShape.setFillColor(sf::Color::Green);
    //For debugging and coding perpus, can remove later.. -Karma
    //sets defult image for entity
    /*this->texture.loadFromFile("../Images/BlueBalloon.png");
    this->rectShape.setTexture(&this->texture);
    */

    //sets defult outline for entity
    this->rectShape.setOutlineColor(sf::Color::Cyan);
    this->rectShape.setOutlineThickness(5.f);

}


Entity::Entity(std::string texturePath, float xPos, float yPos, int speed, bool alive, int dX, int dY, float windowWidth, float windowHeight)
	: texturePath(texturePath), xPos(xPos), yPos(yPos), speed(speed), alive(alive), dX(dX), dY(dY), widthHeight(windowWidth, windowHeight)
{
    this->texture.loadFromFile(this->texturePath);
    this->setTexture(this->texture);
    //this->rectShape.setTexture(&this->texture);


}



//Setters&Getters
    // Setters
void Entity::setXPos(float xPos) { 
    this->xPos = xPos;
    setPosition(xPos, this->yPos);
}
void Entity::setYPos(float yPos) {
    this->yPos = yPos; 
    setPosition(this->xPos, yPos);

}
void Entity::setTexture(const sf::Texture& texture) { 
    this->texture = texture; 
    this->rectShape.setTexture(&this->texture);
}
void Entity::setSpeed(int newSpeed) {
    this->speed = newSpeed; 
}

void Entity::setAlive(bool isAlive) {
    this->alive = isAlive; 
}

void Entity::setPosOfRect(float xPos, float yPos)
{
    this->rectShape.setPosition(xPos, yPos);
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



void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->rectShape);


}
