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
    : isAlive(true), speed(0.02f), frameCounter(0), gen(rd()), dis(100, 300)
{
    shape.setSize(sf::Vector2f(40.0f, 40.0f));
    shape.setPosition(x, y);
    shape.setTexture(&texture);
    direction = 1; //Start moving right
}

void Enemy::move()
{
    shape.move(speed * direction, 0.f);
}

void Enemy::changeDirection()
{
    direction *= -1; //Reverse
    shape.move(0.f, 20.f); //Move down
}

void Enemy::update(float deltaTime)
{
    move(); //Move the enemy


    //ADD SHOOTING HERE:
    // Increment the frame count for each enemy
    frameCounter += deltaTime;

    // Fire a bullet every slower frames
    //if (frameCounter >= slowerFrameRate * 500) {
    //    fireBullet();
    //    frameCounter = 0;  // Reset the frame count
    //}

    if (frameCounter >= dis(gen)) {
        fireBullet();
        frameCounter = 0;  // Reset the frame count
    }

    // Update bullets
    float bulletSpeedDown = 5.f; // Bullets move down
    updateBullets(bulletSpeedDown); 
}

void Enemy::draw(sf::RenderWindow& window)
{
    if (isAlive) {
        window.draw(shape);
    }

    drawBullets(window);

}

void Enemy::fireBullet()
{
    float fireSpeed = 0.02f;
    Bullet bullet(shape.getPosition().x + shape.getSize().x / 2.f, shape.getPosition().y + shape.getSize().y, fireSpeed);
    bullets.push_back(bullet);
}

void Enemy::updateBullets(float deltaTime)
{
    // Update each bullet's position
    for (auto& bullet : bullets) {
        bullet.update(deltaTime);
    }

    // Remove inactive bullets (out of bounds)
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [](const Bullet& bullet) { return !bullet.isActive(); }),
        bullets.end());
}

void Enemy::drawBullets(sf::RenderWindow& window)
{
    for (const auto& bullet : bullets) {
        bullet.draw(window);
    }
}
