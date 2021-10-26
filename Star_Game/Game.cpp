#include "Game.h"

void Game::initWindow()
{
	_window				= new sf::RenderWindow(sf::VideoMode(800, 600), "Star Game", sf::Style::Default);
	_window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	_textures["BULLET"] = new sf::Texture();
	_textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::initGUI()
{
																// Load font
	if (!_font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << " ! ERROR::GAME::INITGUI::Faild to loat font" << std::endl;
	}
																// Init point text
	_pointText.setFont(_font);
	_pointText.setCharacterSize(24);
	_pointText.setFillColor(sf::Color::White);
}

void Game::initWorld()
{
	_wordlBackground;
	if (!_worldTextur.loadFromFile("Textures/star-5364491_1280.jpg"))
	{
		std::cout << " ! ERROR::GAME::INITWORLD::Faild to loat textur" << std::endl;
	}

	_wordlBackground.setTexture(_worldTextur);
}

void Game::initSystem()
{
	_points				= 0;
}

void Game::initPlayer()
{
	_player				= new Player();
}

void Game::initEnemies()
{
	_spawnTimerMax		= 50.f;
	_spawnTimer			= _spawnTimerMax;
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initGUI();
	this->initWorld();
	this->initSystem();
	this->initTextures();
	this->initEnemies();
}

Game::~Game()
{
	delete _window;
	delete _player;

																// Remove textures
	for (auto &i : _textures)
	{
		delete i.second;
	}

																// Remove bullets
	for (auto *i : _bullet)
	{
		delete i;
	}

																// Remove enemies
	for (auto *enemy : _enemies)
	{
		delete enemy;
	}
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

																// Movement bullet
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _player->canAttack())
	{
		_bullet.push_back(new Bullet(_textures["BULLET"], 
									 _player->getPos().x + _player->getBounds().width/2.f, 
									 _player->getPos().y, 
									 0.f, -1.f, 8.f));
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << _points;
	_pointText.setString(ss.str());
}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
																// Check world collisio intersection with _player															
																// Left
	if (_player->getBounds().left < 0.f)
	{
		_player->setPosition(0.f, _player->getBounds().top);
	}	

																// Top
	else if (_player->getBounds().top < 0.f)
	{
		_player->setPosition(_player->getBounds().left, 0.f);
	}		

																// Right
	else if (_player->getBounds().left + _player->getBounds().width >= _window->getSize().x)
	{
		_player->setPosition(_window->getSize().x - _player->getBounds().width, _player->getBounds().top);
	}

																// Bottom
	else if (_player->getBounds().top + _player->getBounds().height >= _window->getSize().y)
	{
		_player->setPosition(_player->getBounds().left, _window->getSize().y - _player->getBounds().height);
	}
}

void Game::updateBullet()
{
	int count = 0;

	for (auto *b : _bullet)
	{
		b->update();

																// top of screen
		if (b->getBounds().top + b->getBounds().height < 0.f)
		{
																// Dellete bullet
			//delete _bullet.at(count);
			_bullet.erase(_bullet.begin() + count);
			--count;
		}

		++count;
	}
}

void Game::updateEnemies()
{

																// Spawning
	_spawnTimer					+= 0.5f;
	if (_spawnTimer >= _spawnTimerMax)
	{
		_enemies.push_back(new Enemy(rand() % _window->getSize().x - 20.f, -100.f));
		_spawnTimer				= 0.f;
	}

																// Update
	int count = 0;
	for (auto *enemy : _enemies)
	{
		enemy->update();

																// Remove enemy at the bottom of the screen
		if (enemy->getBounds().top > _window->getSize().y)
		{
			delete _enemies.at(count);
			_enemies.erase(_enemies.begin() + count);
			std::cout << _enemies.size() << std::endl;
			--count;
		}
		++count;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < _enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < _bullet.size() && !enemy_deleted; ++k)
		{
			if (_enemies[i]->getBounds().intersects(_bullet[k]->getBounds()))
			{
				_points += _enemies[i]->getPoints();

				delete _enemies[i];
				_enemies.erase(_enemies.begin() + i);
				std::cout << _enemies.size() << std::endl;

				delete _bullet[k];
				_bullet.erase(_bullet.begin() + k);
				std::cout << _bullet.size() << std::endl;

				enemy_deleted = true;
			}
		}
	}
}

void Game::update()
{
	
	this->updatePollEvents();
																// Player moves here
	this->updateInput();

	_player->update();

	this->updateCollision();

	this->updateBullet();

	this->updateEnemies();

	this->updateCombat();

	this->updateGUI();

	this->updateWorld();
}

void Game::renderGUI()
{
	_window->draw(_pointText);
}

void Game::renderWorld()
{
	_window->draw(_wordlBackground);
}

void Game::render()
{
	_window->clear();

																// Draw world background
	this->renderWorld();

																// Draw all the stuff
	_player->render(*_window);

	for (auto *b : _bullet)
	{
		b->render(_window);
	}

																// Draw all enemies
	for (auto *enemy : _enemies)
	{
		enemy->render(_window);
	}

	this->renderGUI();

	_window->display();
}
