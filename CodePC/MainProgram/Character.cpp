#include "Character.h"


const float Character::BalloonHeightAdjustment = 85.0f;

Character::Character()
    : Entity(), aBalloon(nullptr), health(3)
{
    setPosition(600 / 2, 800 - 300);
    setSize(sf::Vector2f(90.f, 60.f));
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
    //if(!theBalloon)
	this->aBalloon = theBalloon;
	this->aBalloon->setPosition(getGlobalBounds().left, getGlobalBounds().top - 85.f); 
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
        this->setXPos(0);

        //this->setXPos(400);   
    }
    //prevents going right, outside window, 
    // the xPosition      +      the width of the rectangle  >=    the width of the screen 
    if (this->getPosXOfRect() + getSize().x >= this->getWidth() ) {

        this->setXPos(getWidth()- getSize().x);

    }
   
}

void Character::releaseBalloon()
{
    this->aBalloon->go();
    this->aBalloon = nullptr;
}





void Character::setPosition(float xPos, float yPos)
{
    this->Entity::setPosition(xPos, yPos);
    if (this->aBalloon != nullptr)
    {
        this->aBalloon->setPosition(getGlobalBounds().left,
            getGlobalBounds().top - BalloonHeightAdjustment);
    }
}

bool Character::isCollidingWith(const Bullet& bullet)
{
    return getGlobalBounds().intersects(bullet.getBounds());
}

void Character::takeDamage(int damage)
{
    this->health -= damage;
}

sf::FloatRect Character::getBounds() 
{
    return getGlobalBounds();
}

int Character::getHealth() const
{
    return this->health;
}

void Character::updateMovement()
{
    
    Entity::updateMovement();
    if(this->aBalloon !=nullptr){
    receiveBalloon(this->aBalloon);

    }
}


