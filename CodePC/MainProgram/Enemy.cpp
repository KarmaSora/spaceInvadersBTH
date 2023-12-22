#include "Enemy.h"

bool Enemy::getIsAlive() const
{
    return isAlive;
}

sf::Vector2f Enemy::getPosition() const
{
    return shape.getPosition();
}

void Enemy::setPosition(float x, float y)
{
    shape.setPosition(x, y);
}

Enemy::Enemy(float x, float y, const sf::Texture& texture)
{
    shape.setSize(sf::Vector2f(40.0f, 40.0f));
    shape.setPosition(x, y);
    shape.setTexture(&texture);
    isAlive = true;
    speed = 0.02f;
    direction = 1; //Start by moving to the right
}

void Enemy::move()
{
    shape.move(speed * direction, 0.f);
}

void Enemy::changeDirection()
{
    direction *= -1; //Reverse
    shape.move(0.f, 20.f);
}

void Enemy::update()
{
    move();
    //ADD SHOOTING HERE:
}

void Enemy::draw(sf::RenderWindow& window)
{
    if (isAlive) {
        window.draw(shape);
    }
}
