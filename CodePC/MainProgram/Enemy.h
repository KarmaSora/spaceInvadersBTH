#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
private:
	sf::RectangleShape shape;
	bool isAlive;
public:
	Enemy(float x, float y);
};





#endif