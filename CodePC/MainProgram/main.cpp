#include "Game.h"
#include <ctime>
#ifdef _DEBUG
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#else
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-graphics.lib")
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(unsigned(time(0)));
	


	bool allowGame = false;;

	sf::RenderWindow menuWindow(sf::VideoMode(600, 500), "Space Invaders Menu");
	sf::Event ev;

	//new:
	sf::Font font;
	font.loadFromFile("../Fonts/space_invaders.ttf");
		
	//Menu text "SPACE INVADERS"
	sf::Text menuText;
	menuText.setFont(font);
	menuText.setString("SPACE INVADERS");
	menuText.setCharacterSize(45);
	menuText.setFillColor(sf::Color::Green);
	menuText.setStyle(sf::Text::Bold);
	menuText.setPosition(90.0f, 100.0f);

	//Hint: "Press Space to Start"

	sf::Text menuHint;
	menuHint.setFont(font);
	menuHint.setString("Press Space to Start");
	menuHint.setCharacterSize(20);
	menuHint.setFillColor(sf::Color::Green);
	menuHint.setStyle(sf::Text::Italic);
	menuHint.setPosition(169.0f, 400.0f);
	//

	while (menuWindow.isOpen())
	{
		while (menuWindow.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Space) {
					menuWindow.close();
					allowGame = true;
				}
				break;
			default:
				break;
			}
		}
		menuWindow.clear(sf::Color(0,0,0));
		menuWindow.draw(menuText);
		menuWindow.draw(menuHint);
		menuWindow.display();

	}

	Game game;
	if(allowGame){
	game.run();
	}
	return 0;
}