#pragma once
#include <SFML/Graphics.hpp>

class Obstacle :public sf::Drawable
{
private:
	sf::CircleShape circle;
public:
	Obstacle(float windowWidth, float windowHeight, sf::Color color, float radius = 5.0f);
	sf::FloatRect getBounds() const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

