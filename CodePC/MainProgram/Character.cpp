#include "Character.h"


const float Character::BalloonHeightAdjustment = 85.0f;

Character::Character()
    : Entity(), aBalloon(nullptr), health(3)
{
    this->rectShape.setPosition(600 / 2, 800 - 300);
    this->rectShape.setSize(sf::Vector2f(90.f, 60.f));
    sf::Texture tex;
   
    //// Defult look for player, Curently blue ballon image
    //tex.loadFromFile("../Images/BlueBalloon.png");
    //this->setTexture(tex);
    ////changes the color of given image if any. If image not found then change color of rect to red -Karma
    //this->rectShape.setFillColor(sf::Color::Red);
    //this->setPosition(600 / 2, 800 - 300);

}

Character::Character(std::string texturePath, float xPos, float yPos, int speed, bool alive, int dX, int dY, float windowWidth, float windowHeight, int health)
    :Entity(texturePath,xPos,yPos,speed,alive,dX,dY,windowWidth,windowHeight), health(health)
{
    
}




void Character::receiveBalloon(Balloon * theBalloon)
{

	this->aBalloon = theBalloon;
	this->aBalloon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f); 
}
void Character::act()
{
    this->setDX(0);
    this->setDY(0);
    this->updateMovement();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
    //std::cout << "enterd act func in character, Left was Pressed\n";
        this->setDX(-1);
        this->updateMovement();        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       // std::cout << "enterd act func in character, Right was Pressed\n";

        this->setDX(1);
        this->updateMovement();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (this->aBalloon != nullptr)
        {
            this->releaseBalloon();
        }
    }

    //keep character within window, Character bounds 
    //prevents going to left, outside of window
    if ((this->getPosXOfRect() ) <= 0) {
        std::cout << "\n\n\nthis was called\n\n\n";
        //change the 5 later to the width of image... //Karma
        this->setXPos(this->rectShape.getSize().x);

        //this->setXPos(400);   
    }
    //prevents going right, outside window, 
    // the xPosition      +      the width of the rectangle  >=    the width of the screen 
    if (this->getPosXOfRect() + this->rectShape.getSize().x >= this->getWidth() ) {

        this->setXPos(this->getWidth()/2);

    }
    



}

void Character::releaseBalloon()
{
    this->aBalloon->go();
    this->aBalloon = nullptr;
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->rectShape);
}

// New changes:
sf::Vector2f Character::getPosition() const
{
    return this->Entity::getPosition();
}

sf::Vector2f Character::getSize() const
{
    return this->rectShape.getSize();
}

void Character::setPosition(float x, float y)
{
    this->Entity::setPosition(x, y);
    if (this->aBalloon != nullptr)
    {
        this->aBalloon->setPosition(this->rectShape.getGlobalBounds().left,
            this->rectShape.getGlobalBounds().top - BalloonHeightAdjustment);
    }
}

bool Character::isCollidingWith(const Bullet& bullet)
{
    return this->rectShape.getGlobalBounds().intersects(bullet.getBounds());
}

void Character::takeDamage(int damage)
{
    this->health -= damage;
}

sf::FloatRect Character::getBounds() const
{
    return this->rectShape.getGlobalBounds();
}

int Character::getHealth() const
{
    return this->health;
}

void Character::updateMovement()
{
    Entity::updateMovement();
}



//#include "Character.h"
//const float Character::BalloonHeightAdjustment = 85.0f;
//
//void Character::receiveBalloon(Balloon * theBalloon)
//{
//
//	this->aBallon = theBalloon;
//	this->aBallon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f); // 85.0 is the height of the Balloon, should use a memberfunction in Balloon for this
//}
//
//Character::Character(float windowWidth, float windowHeight, sf::Color color, float width, float height, float speed, int health)
//	:rectShape(sf::Vector2f(width,height)), aBallon(nullptr), speed(speed), health(health)
//{
//	this->rectShape.setFillColor(color);
//	this->rectShape.setPosition(windowWidth/2, windowHeight - width);
//}
//
//void Character::act()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	{
//		this->rectShape.move(-this->speed, 0);
//		if (this->aBallon !=  nullptr)
//		{
//			this->aBallon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f);
//		}
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	{
//		this->rectShape.move(this->speed, 0);
//		if (this->aBallon != nullptr )
//		{
//			this->aBallon->setPosition(this->rectShape.getGlobalBounds().left, this->rectShape.getGlobalBounds().top - 85.f);
//		}
//	}
//	
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//	{
//		if (this->aBallon != nullptr)
//		{
//			this->releaseBalloon();
//		}
//	}
//}
//
//
//void Character::releaseBalloon() 
//{
//	this->aBallon->go();
//	this->aBallon = nullptr;
//}
//
//void Character::draw(sf::RenderTarget & target, sf::RenderStates states) const
//{
//	target.draw(this->rectShape);
//}
////new changes:
//sf::Vector2f Character::getPosition() const
//{
//	return this->rectShape.getPosition();
//}
//
//sf::Vector2f Character::getSize() const
//{
//	return this->rectShape.getSize();
//}
//
//void Character::setPosition(float x, float y)
//{
//	this->rectShape.setPosition(x, y);
//	if (this->aBallon != nullptr) {
//		this->aBallon->setPosition(this->rectShape.getGlobalBounds().left,
//			this->rectShape.getGlobalBounds().top - BalloonHeightAdjustment);
//	}
//}
//
//bool Character::isCollidingWith(const Bullet& bullet)
//{
//	//this->health--;
//	return this->rectShape.getGlobalBounds().intersects(bullet.getBounds());
//}
//
//void Character::takeDamage(int damage)
//{
//	this->health -= damage;
//	/*if (health <= 0) {
//		std::cout << "Player has been defeated!" << std::endl;
//	}*/
//}
//
//sf::FloatRect Character::getBounds() const
//{
//	return this->rectShape.getGlobalBounds();
//}
//
//int Character::getHealth() const
//{
//	return this->health;
//}
