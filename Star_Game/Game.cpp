#include "Game.h"

void Game::initWindow()
{
	_window				= new sf::RenderWindow(sf::VideoMode(800, 600), "Star Game", sf::Style::Default);
	_window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(false);
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->_window;
}

																// Functions
void Game::run()
{
	while (_window->isOpen())
	{
		this->update();

		this->render();
	}
	
}

void Game::update()
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
																// If clicked close
		if (event.type == sf::Event::Closed)
		{
			_window->close();
		}
		if (event.KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			_window->close();
		}
	}
}

void Game::render()
{
	_window->clear();

																// Draw all the stuff
	_window->display();
}
