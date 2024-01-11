#include "Menu.h"

Menu::Menu()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Space Invaders Menu")
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	window.setMouseCursorVisible(true);
	window.setMouseCursorGrabbed(false);
	window.setActive(true);
	window.requestFocus();
	window.clear(sf::Color::Black);

	if (!font.loadFromFile("../Fonts/space_invaders.ttf")) {
		std::cerr << "Error loading font file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (!font2.loadFromFile("../Fonts/MachineStd-Bold.otf")) {
		std::cerr << "Error loading font file" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	startGame = false;

	//title: 
	setTextProperties(title, "SPACE INVADERS", 45,
		sf::Color::Green, WIDTH / 2 - 220, HEIGHT / 4 - 20);

	//start:
	setTextProperties(start, "Start Game", 30, sf::Color::Green, WIDTH / 2 - 120, HEIGHT / 2);
	//middle:
	setTextProperties(middle, "You get 3 lives, use them well..", 20,
		sf::Color::Red, WIDTH / 2 - 200, HEIGHT / 2 + 150);
	//exit:
	setTextProperties(exit, "Quit", 30, sf::Color::Green, WIDTH / 2 - 60, HEIGHT / 2 + 50);

}

Menu::Menu(int xPos, int yPos, sf::Color color, sf::Text title,
	sf::Text start, sf::Text exit, sf::Font font)

	: title(title), start(start),
	exit(exit), font(font)
{
	startGame = false;
	if (!font.loadFromFile("../Fonts/space_invaders.ttf")) {
		std::cerr << "Error loading font file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (!font2.loadFromFile("../Fonts/MachineStd-Bold.otf")) {
		std::cerr << "Error loading font file" << std::endl;
		std::exit(EXIT_FAILURE);
	}

}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(title);
	target.draw(start);
	target.draw(middle);
	target.draw(exit);
}

void Menu::setTextProperties(sf::Text& text, const std::string& string, int characterSize, sf::Color color, float xPos, float yPos)
{
	text.setFont(font);
	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(color);
	text.setStyle(sf::Text::Bold);
	text.setPosition(xPos, yPos);
}

int Menu::handleInput()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:

			if (event.key.code == sf::Keyboard::Up) {
				selectedOption = (selectedOption - 1 + 2) % 2;
			}
			else if (event.key.code == sf::Keyboard::Down) {
				selectedOption = (selectedOption + 1) % 2;
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (selectedOption == 0) {
					window.close();
					startGame = true;
				}
				else if (selectedOption == 1) {
					window.close();
					startGame = false;
				}
			}
			break;
		default:
			break;
		}
	}
	window.clear(sf::Color(0, 0, 0));

	start.setFillColor(selectedOption == 0 ? sf::Color::Yellow : sf::Color::Green);
	exit.setFillColor(selectedOption == 1 ? sf::Color::Yellow : sf::Color::Green);

	texture.loadFromFile("../../CodePC/Images/stars1.png");

	//Create sprite to display frames
	sprite.setTexture(texture);

	window.draw(sprite);
	window.draw(*this);
	window.display();

	return 0; //Stays at menu
}

void Menu::run()
{

	while (window.isOpen())
	{
		handleInput();
	}

}

bool Menu::getStartGame()
{
	return startGame;
}
