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
	while (menuWindow.isOpen())
	{
		while (menuWindow.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape) {
					menuWindow.close();
					allowGame = true;
				}
				
			default:
				break;
			}
		}

		menuWindow.clear(sf::Color(250,0,0));
		menuWindow.display();

	}

	Game game;
	if(allowGame){
	game.run();
	}
	return 0;
}