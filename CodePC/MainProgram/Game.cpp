#include "Game.h"
#include <iostream>

#include "Menu.h"

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
		//

		elapsedTimeSinceLastUpdate -= timePerFrame;
		this->character.act();
		if (this->balloon->collidedWith(this->obstacle))
		{
			this->balloon->stopMoving();
			this->character.receiveBalloon(this->balloon);
		}
		else if (this->balloon->insideWindow() &&
			this->balloon->isMoving())
		{
			this->balloon->move();
		}
		else if (!this->balloon->insideWindow())
		{
			this->balloon->stopMoving();
			this->character.receiveBalloon(this->balloon);
		}
	}	
}

void Game::render()
{
	/*Menu menu(WIDTH, HEIGHT);

	while (this->window.isOpen()) {
		int menuResult = menu.handleInput(window);
		if (menuResult == 1) break;
		window.clear();
		window.draw(menu);
		window.display();       MENYN ÄR INTE KLAR..
	}
*/

	this->window.clear();
	//this->window.draw(this->menu);
	this->window.draw(this->character);
	this->window.draw(*this->balloon);
	this->window.draw(this->obstacle);
	this->window.display();
}


Game::Game()
	:window(sf::VideoMode(WIDTH, HEIGHT), "Space Invaders"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero),
	character(WIDTH, HEIGHT, sf::Color::Green, 40.0f, 40.0f, 6.0f), obstacle(HEIGHT, WIDTH, sf::Color::Yellow)
{
	this->balloon = new Balloon(3.0f);
	this->character.receiveBalloon(this->balloon);
}

Game::~Game()
{
	delete this->balloon;
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
