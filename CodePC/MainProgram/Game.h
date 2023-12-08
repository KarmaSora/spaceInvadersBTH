#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Balloon.h"
#include "Obstacle.h"

class Game
{
private:
	static const int WIDTH = 900;
	static const int HEIGHT = 600;
private:
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;

	Obstacle obstacle;
	Character character;
	Balloon * balloon;
	
	void handleEvents();
	void update();
	void render();
public:
	Game();
	~Game();
	void run(); 
};
