#include "Game.h"
#include <iostream>

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
	elapsedTimeSinceLastUpdate += clock.restart();
	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{
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
	this->window.clear();
	this->window.draw(this->character);
	this->window.draw(*this->balloon);
	this->window.draw(this->obstacle);
	this->window.display();
}

Game::Game()
	:window(sf::VideoMode(WIDTH, HEIGHT), "Flying balloon"),
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
