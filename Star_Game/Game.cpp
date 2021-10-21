#include "Game.h"

void Game::initWindow()
{
	_window				= new sf::RenderWindow(sf::VideoMode(800, 600), "Star Game", sf::Style::Default);
	_window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	
}

void Game::initPlayer()
{
	_player				= new Player();
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete _window;
	delete _player;
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

void Game::updatePollEvents()
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

void Game::updateInput()
{
																// Move player func
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		_player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		_player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		_player->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		_player->move(0.f, 1.f);
	}
}

void Game::update()
{
	
	this->updatePollEvents();
																// Player moves here
	this->updateInput();
}

void Game::render()
{
	_window->clear();

																// Draw all the stuff
	_player->render(*_window);

	_window->display();
}
