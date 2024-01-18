#pragma once
#include "Balloon.h"
#include "Character.h"
#include "Enemy.h"
#include "Obstacle.h"
#include <random>
#include <SFML/Graphics.hpp>
#include <vector>

#include <memory>

#include "Menu.h"


class Game
{
private:
	static const int WIDTH = 900;
	static const int HEIGHT = 600;

	int GameScore = 0;
	std::string scoreFilePath = "../../CodePC/Images/gameScore.txt";
	std::vector<std::unique_ptr<Enemy>> enemies;
	//create entity so i can use dynamic bindning

	sf::Texture enemyTexture;

private:
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;

	sf::Sprite background;
	sf::Texture backgroundTexture;

	//Hearts:
	sf::Texture heartTexture;
	std::vector<sf::Sprite> lifeSprites; 
	sf::Sprite lifeSprite;

	Obstacle obstacle;
	Character character;
	Bullet bullet;

	std::unique_ptr<Balloon>(balloon);

	Entity* entityPtr;



	void handleEvents();
	void update();
	void render();

	void updateEnemies();
	void updateBullets();
	void gameScreen(std::string toDisplay);
	void registerScore(int ScoreToAppend);
	std::string readScore() const;
public:
	Game();
	void run();

};

