#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu : public	sf::Drawable {
private:
	bool startGame;
	sf::Event event;
	sf::Font font;
	sf::Font font2;
	int selectedOption = 0;  // 0 for "Start", 1 for "Quit"
	sf::Text title;
	sf::Text start;
	sf::Text middle;
	sf::Text exit;
	const float WINDOWWIDTH = 600, WINDOWHEIGHT = 500;
	sf::RenderWindow window;
public:
	Menu();
	Menu(int xPos, int yPos, sf::Color color, sf::Text title,
		sf::Text start, sf::Text exit, sf::Font font);
	int handleInput(sf::Event event);
	void run();
	bool getStartGame();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setTextProperties(sf::Text& text, const std::string& string, int characterSize, sf::Color color, float xPos, float yPos);
};