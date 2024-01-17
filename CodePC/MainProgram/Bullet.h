#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

#include <SFML/Graphics.hpp>

class Bullet : public Entity {
public:
	Bullet();
	Bullet(float startX, float startY, float speed, int damage);

	// Update the bullet's position

	// Draw the bullet on the window
	void draw(sf::RenderWindow& window) ;

	// Check if the bullet is currently active
	bool isActive() const;

	// Set the bullet to inactive
	void deactivate();

	int getDamage() const;
	sf::FloatRect getBounds() ;

	sf::Vector2f getPosition() const;

	bool hasHit() const;
	void markAsHit();

	void updateMovement() override;
private:
	// Bullet attributes
	//sf::RectangleShape shape;								//remove this....		
	bool hasHitCharacter;  //Flag to track
	int damage;

	//Private helper method to set the bullet's appearance
	void initShape();
};




#endif