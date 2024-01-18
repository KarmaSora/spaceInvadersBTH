#ifndef ENEMY_H
#define ENEMY_H

#include "Bullet.h"
#include <random>
#include <vector>

class Enemy : public Entity {
private:
	bool isAlive;

	int direction; // 1 for right, -1 for left
	std::vector<Bullet> bullets;
	float frameCounter;
	float deltaTime;

	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> dis;

	int firingDelay;
public:
	void setDeltaTime(float deltaTIme);
	bool getIsAlive() const;
	sf::Vector2f getPosition() const;
	void setPosition(float x, float y);

	Enemy(float x, float y, const sf::Texture& texture, int firingDelay);


	void move();
	void changeDirection();
	void update();
	void draw(sf::RenderWindow& window);

	// Create and fire a bullet
	void fireBullet();

	// Update bullets' positions and check for collisions
	void updateBullets();

	// Draw bullets on the window
	void drawBullets(sf::RenderWindow& window);

	const std::vector<Bullet>& getBullets() const;


	sf::FloatRect getBounds();


	void updateMovement() override;

};





#endif