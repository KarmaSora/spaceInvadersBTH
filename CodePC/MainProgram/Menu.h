#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu : public	sf::Drawable {
private:
	sf::Font font;
	sf::Text title;
	sf::Text start;
	sf::Text exit;
public:
	Menu(float windowWidth, float windowHeight);
	int handleInput(sf::RenderWindow& window);
private:
	void setTextProperties(sf::Text& text, const std::string& content, unsigned int size,
		const sf::Color& color, float x, float y);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};