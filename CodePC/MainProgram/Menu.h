#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu : public	sf::Drawable {
private:
	sf::Font font;
	sf::Text title;
	sf::Text start;
	sf::Text exit;

	float windowWidth, windowHeight;
public:
	sf::RenderWindow window;
	Menu();
	Menu(float windowWidth, float windowHeight, sf::Text title,
		sf::Text start, sf::Text exit);
	int handleInput(sf::RenderWindow& window);
private:

	void setFont(sf::Font font);
	void setTitle(sf::Text title);
	void setStart(sf::Text start);
	void setExit(sf::Text exit);
	sf::Font getFont();
	sf::Text getTitle();
	sf::Text getStart();
	sf::Text getExit();

	void setTextProperties(sf::Text& text, const std::string& content, unsigned int size,
		const sf::Color& color, float x, float y);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};