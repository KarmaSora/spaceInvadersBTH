#include "Game.h"
#include "Menu.h"
#include <fstream>
#include <iostream>
#include <string>



void Game::handleEvents()
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->window.close();
		}
	}
}

void Game::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}

	elapsedTimeSinceLastUpdate += clock.restart();
	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{


		this->character.act();


		elapsedTimeSinceLastUpdate -= timePerFrame;
		if (this->balloon->collidedWith(this->obstacle))
		{
			this->balloon->stopMoving();
			this->character.receiveBalloon(this->balloon.get());
		}
		else if (this->balloon->insideWindow() &&
			this->balloon->isMoving())
		{
			this->balloon->move();
		}
		else if (!this->balloon->insideWindow())
		{
			this->balloon->stopMoving();
			this->character.receiveBalloon(this->balloon.get());
		}

		updateBullets(); // Update bullets

		if (character.getHealth() == 0) {
			gameScreen("Game\nover!"); //Game over if character health is 0
		}
	}
}

void Game::render()
{


	this->window.clear();

	this->window.draw(background);


	this->window.draw(this->character);
	this->window.draw(*this->balloon);
	this->window.draw(this->obstacle);



	updateEnemies();
	for (const auto& enemy : enemies) {
		if (enemy != nullptr) enemy->draw(window);
	}
	for (int i = 0; i < character.getHealth(); ++i) {
		window.draw(lifeSprites[i]);

	}

	this->window.display();
}

void Game::updateEnemies()
{
	


	//Vector to store enemies marked for removal
	std::vector<std::unique_ptr<Enemy>> enemiesToRemove;

	//Iterate over the enemies and mark them for removal
	for (auto it = enemies.begin(); it != enemies.end(); /* no ++it here */) {
		auto& enemy = *it;

		enemy->setDeltaTime(timePerFrame.asSeconds());
			
			
		entityPtr = dynamic_cast<Enemy*>(enemy.get()); //dynamic cast to call updateMovement() from Enemy class
		entityPtr->updateMovement(); //dynamic binding


		if (enemy != nullptr) {

			if (enemy->getPosition().x <= 0 || enemy->getPosition().x >= 860) {
				for (auto& e : enemies) {
					e->changeDirection();
				}
			}
			else if (this->balloon->collidedWith(*enemy)) {
				this->balloon->stopMoving();
				this->character.receiveBalloon(this->balloon.get());

				//Mark the enemy for removal
				enemiesToRemove.push_back(std::move(enemy));
				it = enemies.erase(it); 
				GameScore++;
			}
			else {
				++it;
			}
		}
		else {
			//Increment 'it' if the enemy is null
			it = enemies.erase(it);
		}
	}

	//Remove marked enemies from the vector
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
		[&enemiesToRemove](const auto& enemy) {
			return std::find(enemiesToRemove.begin(), enemiesToRemove.end(), enemy) != enemiesToRemove.end();
		}),
		enemies.end());

}

void Game::updateBullets()
{
	
	for (auto& enemy : enemies) {
		enemy->updateBullets();

		for (auto& bullet : enemy->getBullets()) {
			if (!bullet.hasHit()) {
				sf::FloatRect characterBounds = character.getBounds();
				sf::FloatRect bulletBounds = const_cast<Bullet&>(bullet).getBounds();

				if (characterBounds.intersects(bulletBounds)) {
					character.takeDamage(bullet.getDamage());
					std::cout << "Character Hit! Damage: " << bullet.getDamage() << std::endl;
					std::cout << "Lives remaining: " << character.getHealth() << std::endl;
					const_cast<Bullet&>(bullet).markAsHit();  // Cast away const-ness to call non-const member
					const_cast<Bullet&>(bullet).deactivate();
				}
			}
		}
	}
}

void Game::gameScreen(std::string toDiplay)
{
	window.close();
	sf::RenderWindow menuWindow(sf::VideoMode(600, 500), toDiplay);
	sf::Event ev;

	sf::Font gameOverFont;
	gameOverFont.loadFromFile("../../CodePC/Fonts/space_invaders.ttf");

	sf::Text gameOverText;
	gameOverText.setFont(gameOverFont);
	gameOverText.setString(toDiplay);
	gameOverText.setCharacterSize(90);
	if (toDiplay == "Game\nover!") {
		gameOverText.setFillColor(sf::Color::Red);
	}
	else {
		gameOverText.setFillColor(sf::Color::Yellow);
	}
	gameOverText.setStyle(sf::Text::Bold);
	if (toDiplay == "Game\nover!") {
		gameOverText.setPosition(150, 100);
	}
	else {
		gameOverText.setPosition(100, 100);
	}

	sf::Font pressAnyKeyFont;
	pressAnyKeyFont.loadFromFile("../../CodePC/Fonts/space_invaders.ttf");

	sf::Text pressAnyKeyText;
	pressAnyKeyText.setFont(pressAnyKeyFont);
	pressAnyKeyText.setString("Press any key to continue.");
	pressAnyKeyText.setCharacterSize(25);
	pressAnyKeyText.setFillColor(sf::Color::Green);
	pressAnyKeyText.setStyle(sf::Text::Regular);
	pressAnyKeyText.setPosition(100, 400);



	while (menuWindow.isOpen())
	{
		while (menuWindow.pollEvent(ev))
		{
			if (ev.type == sf::Event::KeyPressed)
			{
				menuWindow.close();
			}


		}
		menuWindow.draw(gameOverText);
		menuWindow.draw(pressAnyKeyText);
		menuWindow.display();
	}
}




Game::Game()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Space Invaders"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero), obstacle(HEIGHT, WIDTH, sf::Color::Yellow), entityPtr(nullptr)
{
	this->balloon = std::make_unique<Balloon>(3.0f);
	this->character.receiveBalloon(this->balloon.get());
	enemyTexture.loadFromFile("../../CodePC/Images/invader1.png");

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> firingDelayDistribution(100, 900); //Random firing delay between 100 and 900, change this to your liking (900)

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 8; col++) {
			int firingDelay = firingDelayDistribution(gen);  //Random firing delay for each enemy
			auto newEnemy = std::make_unique<Enemy>(col * 60.0f, row * 60.0f, enemyTexture, firingDelay);
			enemies.push_back(std::move(newEnemy));
		}
	}
	backgroundTexture.loadFromFile("../../CodePC/Images/stars1.png");
	background.setTexture(backgroundTexture);

	//Hearts:
	heartTexture.loadFromFile("../../CodePC/Images/pixel-heart.png");

	for (float i = 0; i < 3; ++i) {
		lifeSprite.setTexture(heartTexture);

		lifeSprite.setPosition(10.f + i * 30.f, 10.f);

		lifeSprite.setScale(0.03f, 0.03f);
		lifeSprites.push_back(lifeSprite);
	}

}

void Game::run()
{


	while (this->window.isOpen() && this->GameScore != 24)
	{

		handleEvents();
		update();
		render();
	}

	registerScore(this->GameScore);
	if (this->GameScore == 24) {
		gameScreen("You won!");
	}

}


void Game::registerScore(int ScoreToAppend)
{
	std::ofstream writeTo(this->scoreFilePath, std::ios::app);

	if (writeTo.is_open()) {
		writeTo << ScoreToAppend << std::endl;
		std::cout << "Score appended: " << ScoreToAppend << std::endl;
	}
	else {
		std::cerr << "Error opening the file for writing." << std::endl;
	}

}


std::string Game::readScore() const
{
	std::string singleLine;
	std::string totalScore;

	std::ifstream readFile;
	readFile.open(this->scoreFilePath);
	if (readFile.is_open()) {
		while (std::getline(readFile, singleLine)) {
			totalScore += singleLine;

		}
	}
	readFile.close();



	return totalScore;
}


