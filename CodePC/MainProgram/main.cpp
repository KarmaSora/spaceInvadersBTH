#include "Game.h"
#include <ctime>
#ifdef _DEBUG
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib") //To include music
#else
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-graphics.lib")
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(unsigned(time(0)));
	sf::Music music;
	if (!music.openFromFile("../../CodePC/Music/Pixel-Peeker-Polka-faster_chosic.com_.wav")) {
		std::cout << "Error..." << std::endl;
	}
	else {
		music.setLoop(true);
		music.setVolume(50);
		music.play();
		/*
		Pixel Peeker Polka – faster by Kevin MacLeod | https://incompetech.com/
		Music promoted by https://www.chosic.com/free-music/all/
		Creative Commons CC BY 3.0
		https://creativecommons.org/licenses/by/3.0/
		*/
	}

	bool allowGame = false;

	sf::RenderWindow menuWindow(sf::VideoMode(600, 500), "Space Invaders Menu");
	sf::Event ev;

	sf::Font font;
	sf::Font font2;

	font.loadFromFile("../Fonts/space_invaders.ttf");
	font2.loadFromFile("../Fonts/MachineStd-Bold.otf");

	//Menu text "SPACE INVADERS"
	sf::Text menuText;
	menuText.setFont(font);
	menuText.setString("SPACE INVADERS");
	menuText.setCharacterSize(45);
	menuText.setFillColor(sf::Color::Green);
	menuText.setStyle(sf::Text::Bold);
	menuText.setPosition(90.0f, 100.0f);

	
	// "Start" text
	sf::Text startText;
	startText.setFont(font);
	startText.setString("Start Game");
	startText.setCharacterSize(24);
	startText.setFillColor(sf::Color::Green);
	startText.setStyle(sf::Text::Regular);
	startText.setPosition(200.0f, 250.0f);

	sf::Text middleText;
	middleText.setFont(font2);
	middleText.setString("You get 3 lives, use them well..");
	middleText.setCharacterSize(36);
	middleText.setFillColor(sf::Color::Red);
	//middleText.setStyle(sf::Text::Bold);
	middleText.setPosition(90.0f, 450.0f);

	// "Quit" text
	sf::Text quitText;
	quitText.setFont(font);
	quitText.setString("Quit");
	quitText.setCharacterSize(24);
	quitText.setFillColor(sf::Color::Green);
	quitText.setStyle(sf::Text::Bold);
	quitText.setPosition(250.0f, 300.0f);

	int selectedOption = 0;  // 0 for "Start", 1 for "Quit"

	while (menuWindow.isOpen())
	{
		while (menuWindow.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::KeyPressed:
				
				if (ev.key.code == sf::Keyboard::Up) {
					selectedOption = (selectedOption - 1 + 2) % 2;
				}
				else if (ev.key.code == sf::Keyboard::Down) {
					selectedOption = (selectedOption + 1) % 2;
				}
				else if (ev.key.code == sf::Keyboard::Enter) {
					if (selectedOption == 0) {
						menuWindow.close();
						allowGame = true;
					}
					else if (selectedOption == 1) {
						menuWindow.close();
					}
				}
				break;
			default:
				break;
			}
		}
		menuWindow.clear(sf::Color(0,0,0));

		//Highlight the selected option
		startText.setFillColor(selectedOption == 0 ? sf::Color::Yellow : sf::Color::Green);
		quitText.setFillColor(selectedOption == 1 ? sf::Color::Yellow : sf::Color::Green);

		menuWindow.draw(startText);
		menuWindow.draw(middleText);
		menuWindow.draw(quitText);

		menuWindow.draw(menuText);
		menuWindow.display();

	}

	Game game;
	if(allowGame){
	game.run();
	}
	return 0;
}