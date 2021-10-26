#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
														/// Window 
	sf::RenderWindow*					_window;

														/// Resources
	std::map<std::string, sf::Texture*>	_textures;
	std::vector<Bullet*>				_bullet;		// Bullet

														// GUI
	sf::Font							_font;
	sf::Text							_pointText;

														// World
	sf::Texture							_worldTextur;
	sf::Sprite							_wordlBackground;

														// System
	unsigned							_points;

														// Player
	Player*								_player;

														// Enemies
	float								_spawnTimer;
	float								_spawnTimerMax;
	std::vector<Enemy*>					_enemies;



														// Private Function
	void								initWindow();
	void								initTextures();
	void								initGUI();
	void								initWorld();
	void								initSystem();

	void								initPlayer();
	void								initEnemies();

public:
	Game();

	virtual ~Game();
	
														// Function
	void								run();

	void								updatePollEvents();
	void								updateInput();
	void								updateGUI();
	void								updateWorld();
	void								updateCollision();
	void								updateBullet();
	void								updateEnemies();
	void								updateCombat();
	void								update();

	void								renderGUI();
	void								renderWorld();
	void								render();

};

