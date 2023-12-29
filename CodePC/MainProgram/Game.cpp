#include "Game.h"
#include <iostream>

#include "Menu.h"

//const float collisionThreshold = 7.0f; // Adjust as needed for collision detection

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
		//exit(0);
	}
	//WTFTHis is bullshit
	//WTF COMMITS CHANGES

	elapsedTimeSinceLastUpdate += clock.restart();
	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{

		// Bounds checking to prevent the player from moving outside the window
		sf::Vector2f characterPosition = this->character.getPosition();
		sf::Vector2f characterSize = this->character.getSize();
		sf::Vector2u windowSize = this->window.getSize();


		/*
		if (characterPosition.x < 0) {
			this->character.setPosition(0, characterPosition.y);
		}
		else if (characterPosition.x > windowSize.x - characterSize.x) {
			this->character.setPosition(windowSize.x - characterSize.x, characterPosition.y);
		}

		if (characterPosition.y < 0) {
			this->character.setPosition(characterPosition.x, 0);
		}
		else if (characterPosition.y > windowSize.y - characterSize.y) {
			this->character.setPosition(characterPosition.x, windowSize.y - characterSize.y);
		}
		*/

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
			gameOverScreen(); //Game over if character health is 0
		}
	}
}

void Game::render()
{


	this->window.clear();
	this->window.draw(this->character);
	this->window.draw(*this->balloon);
	this->window.draw(this->obstacle);

	//////
	updateEnemies();
	for (const auto& enemy : enemies) {
		if (enemy != nullptr) enemy->draw(window);
	}
	//////

	this->window.display();
}

void Game::updateEnemies()
{
	//for (auto& enemy : enemies) {
	//	enemy->update(timePerFrame.asSeconds()); // Pass in the time since last update

	//	if (enemy->getPosition().x <= 0 || enemy->getPosition().x >= 860) {
	//		for (auto& e : enemies) {
	//			e->changeDirection();
	//		}
	//		break;
	//	}

	//	if (this->balloon->collidedWith(*enemy)) {
	//		this->balloon->stopMoving();
	//		this->character.receiveBalloon(this->balloon.get());

	//	}
	//}

	// Vector to store enemies marked for removal
	std::vector<std::unique_ptr<Enemy>> enemiesToRemove;

	// Iterate over the enemies and mark them for removal
	for (auto it = enemies.begin(); it != enemies.end(); /* no ++it here */) {
		auto& enemy = *it;

		enemy->update(timePerFrame.asSeconds());

		if (enemy != nullptr) {
			if (enemy->getPosition().x <= 0 || enemy->getPosition().x >= 860) {
				for (auto& e : enemies) {
					e->changeDirection();
				}
				// Don't break here, just mark the enemy for removal
				enemiesToRemove.push_back(std::move(enemy));
				it = enemies.erase(it);  // Increment 'it' after erasing
			}
			else if (this->balloon->collidedWith(*enemy)) {
				this->balloon->stopMoving();
				this->character.receiveBalloon(this->balloon.get());

				// Mark the enemy for removal
				enemiesToRemove.push_back(std::move(enemy));
				it = enemies.erase(it);  // Increment 'it' after erasing
			}
			else {
				++it;  // Increment 'it' if no removal
			}
		}
		else {
			// Increment 'it' if the enemy is null
			it = enemies.erase(it);
		}
	}

	// Remove marked enemies from the vector
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
		[&enemiesToRemove](const auto& enemy) {
			return std::find(enemiesToRemove.begin(), enemiesToRemove.end(), enemy) != enemiesToRemove.end();
		}),
		enemies.end());




}

void Game::updateBullets()
{
	for (auto& enemy : enemies) {
		// Assuming some threshold for collision, adjust as needed
		enemy->updateBullets(timePerFrame.asSeconds());

		for (auto& bullet : enemy->getBullets()) {
			/*sf::FloatRect characterBounds = character.getBounds();
			sf::FloatRect bulletBounds = bullet.getBounds();*/

			//if (characterBounds.intersects(bulletBounds)) {
			//	character.takeDamage(bullet.getDamage());
			//	std::cout << "Character Hit! Damage: " << bullet.getDamage() << std::endl;
			//	//bullet.deactivate();
			//}
			if (!bullet.hasHit()) {
				sf::FloatRect characterBounds = character.getBounds();
				sf::FloatRect bulletBounds = bullet.getBounds();

				if (characterBounds.intersects(bulletBounds)) {
					character.takeDamage(bullet.getDamage());
					std::cout << "Character Hit! Damage: " << bullet.getDamage() << std::endl;
					//bullet.deactivate();  // Assuming there's a method to deactivate the bullet
					//bullet.markAsHit();   // Mark the bullet as hit to prevent multiple hits
					const_cast<Bullet&>(bullet).markAsHit();  // Cast away const-ness to call non-const member
					const_cast<Bullet&>(bullet).deactivate();  // Cast away const-ness to call non-const member
				}
			}
		}
	}
}

void Game::gameOverScreen()
{
	window.close();
	sf::RenderWindow menuWindow(sf::VideoMode(600, 500), "Space Invaders Gameover Menu");
	sf::Event ev;

	sf::Font gameOverFont;
	gameOverFont.loadFromFile("../Fonts/space_invaders.ttf");

	sf::Text gameOverText;
	gameOverText.setFont(gameOverFont);
	gameOverText.setString("Game\nOver!");
	gameOverText.setCharacterSize(70);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setStyle(sf::Text::Bold);
	gameOverText.setPosition(190, 100);

	sf::Font pressAnyKeyFont;
	pressAnyKeyFont.loadFromFile("../Fonts/space_invaders.ttf");

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
	elapsedTimeSinceLastUpdate(sf::Time::Zero),
	character(WIDTH, HEIGHT, sf::Color::Green, 40.0f, 40.0f, 6.0f), obstacle(HEIGHT, WIDTH, sf::Color::Yellow)
{
	this->balloon = std::make_unique<Balloon>(3.0f);
	this->character.receiveBalloon(this->balloon.get()); // Assuming receiveBalloon takes a raw pointer
	/*this->balloon = new Balloon(3.0f);
	this->character.receiveBalloon(this->balloon);*/
	/////////////////////////////new:
	enemyTexture.loadFromFile("../Images/invader1.png");

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> firingDelayDistribution(100, 900); // Random firing delay between 100 and 900, change this to your liking (900)

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 8; col++) {
			int firingDelay = firingDelayDistribution(gen);  // Random firing delay for each enemy
			//enemies.push_back(std::make_unique<Enemy>(col * 60.0f, row * 60.0f, enemyTexture, firingDelay));
			auto newEnemy = std::make_unique<Enemy>(col * 60.0f, row * 60.0f, enemyTexture, firingDelay);
			enemies.push_back(std::move(newEnemy));
		}
	}
}

void Game::run()
{


	while (this->window.isOpen())
	{

		handleEvents();
		update();
		render();
	}
}
