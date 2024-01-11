#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Menu : public	sf::Drawable {
private:

	sf::Texture texture;
	sf::Sprite sprite;
	bool startGame;
	sf::Font font;
	sf::Font font2;
	int selectedOption = 0;  // 0 for "Start", 1 for "Quit"
	sf::Text title;
	sf::Text start;
	sf::Text middle;
	sf::Text exit;
	static const int WIDTH = 900;
	static const int HEIGHT = 600;
	sf::RenderWindow window;
public:
	Menu();
	Menu(int xPos, int yPos, sf::Color color, sf::Text title,
		sf::Text start, sf::Text exit, sf::Font font);
	int handleInput();
	void run();
	bool getStartGame();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setTextProperties(sf::Text& text, const std::string& string, int characterSize, sf::Color color, float xPos, float yPos);
};