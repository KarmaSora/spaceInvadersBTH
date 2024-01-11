#include "Game.h"
#include "Menu.h"
#include <ctime>

#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

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

	Menu menu;
	menu.run();

	Game game;
	if (menu.getStartGame()) {
		game.run();
	}
	return 0;
}