#include "Enemy.h"

bool Enemy::getIsAlive() const
{
    return isAlive;
}

sf::Vector2f Enemy::getPosition() const
{
    return Entity::getPosition();
}

void Enemy::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
}

Enemy::Enemy(float x, float y, const sf::Texture& texture, int firingDelay)
    : isAlive(true), frameCounter(0), gen(rd()), dis(100, 300), firingDelay(firingDelay)
{
    setSpeed(0.2f);

    setSize(sf::Vector2f(40.0f, 40.0f));
    setPosition(x, y);
    setTexture(texture, true);
    setFillColor(sf::Color(255, 12, 213));
    direction = 1; //Start moving right
}


void Enemy::move()
{
    if (this != nullptr) {
        //std::cout << Entity::getSpeed() * direction << std::endl;
        //std::cout << direction << std::endl;
        Entity::move(Entity::getSpeed() * direction, 0.f);
        //Entity::updateMovement();
    }
}
/*Why does this never being called?
* I think it is because the enemy is never colliding with the window
* I think the enemy is colliding with the window, but the enemy is not being deleted
* I think the enemy is not being deleted because the enemy is not colliding with the window
* I think the enemy is not colliding with the window because the enemy is not being deleted
* I think the enemy is not being deleted because the enemy is not colliding with the window
* I think the enemy is not colliding with the window because the enemy is not being deleted
* I think the enemy is not being deleted because the enemy is not colliding with the window
* I think the enemy is not colliding with the window because the enemy is not being deleted
*/
void Enemy::changeDirection()
{
    direction *= -1; //Reverse
    Entity::move(0.f, 20.f); //Move down
}

void Enemy::update(float deltaTime)
{
    if (this != nullptr) {
        move(); //Move the enemy


        //ADD SHOOTING HERE:
        // Increment the frame count for each enemy
        frameCounter += deltaTime;

        // Fire a bullet every slower frames
        //if (frameCounter >= slowerFrameRate * 500) {
        //    fireBullet();
        //    frameCounter = 0;  // Reset the frame count
        //}

        if (frameCounter >= firingDelay) {
            fireBullet();
            frameCounter = 0;  // Reset the frame count
        }

        // Update bullets
        float bulletSpeedDown = 5.f; // Bullets move down
        updateBullets(bulletSpeedDown);
    }
}

void Enemy::draw(sf::RenderWindow& window)
{
    if (this != nullptr && isAlive) {
        window.draw(getRectangle());
        drawBullets(window);

    }


}

void Enemy::fireBullet()
{
    float fireSpeed = 0.02f;
    float bulletDamage = 1.f;
    Bullet bullet(getPosition().x + getSize().x / 2.f, getPosition().y +getSize().y, fireSpeed, bulletDamage);
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

const std::vector<Bullet>& Enemy::getBullets() const
{
    return bullets;
}

sf::FloatRect Enemy::getBounds() 
{
    return getGlobalBounds();
}


// had to add something, can change later...
void Enemy::updateMovement()
{
    Entity::updateMovement();
}
