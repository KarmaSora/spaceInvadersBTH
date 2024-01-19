#include "Enemy.h"

void Enemy::setDeltaTime(float deltaTIme)
{
	this->deltaTime=deltaTIme;
}

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
	setSpeed(0.05f);

	setSize(sf::Vector2f(40.0f, 40.0f));
	setPosition(x, y);
	setTexture(texture, true);
	setFillColor(sf::Color(255, 12, 213));
	direction = 1; //Start moving right
}


void Enemy::move()
{
	if (this != nullptr) {
		Entity::move(Entity::getSpeed() * direction, 0.f);
	}
}

void Enemy::changeDirection()
{
	direction *= -1; //Reverse
	Entity::move(0.f, 20.f); //Move down
}



void Enemy::draw(sf::RenderWindow& window)
{
	if (this != nullptr && isAlive) {
		window.draw(*this);
		drawBullets(window);
	}
}

void Enemy::fireBullet()
{
	float fireSpeed = 0.02f;
	int bulletDamage = 1;
	Bullet bullet(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y, fireSpeed, bulletDamage);
	bullets.push_back(bullet);
}

void Enemy::updateBullets()
{
	//Update each bullet's position
	for (auto& bullet : bullets) { 
		bullet.updateMovement();
	}

	//Remove inactive bullets (out of bounds)
	bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
		[](const Bullet& bullet) { return !bullet.isActive(); }),
		bullets.end());
}

void Enemy::drawBullets(sf::RenderWindow& window)
{
	for (const auto& bullet : bullets) {
		window.draw(bullet);	
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

void Enemy::updateMovement()
{
	if (this != nullptr) {
		move(); //Move the enemy

		//Shooting:
		frameCounter += deltaTime;

		if (frameCounter >= firingDelay) {
			fireBullet();
			frameCounter = 0;  // Reset
		}

		// Update bullets
		updateBullets();
	}
}
