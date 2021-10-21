#pragma once

#include <map>
#include "Player.h"
#include "Bullet.h"

class Game
{
private:
														/// Window 
	sf::RenderWindow*					_window;

														/// Resources
	std::map<std::string, sf::Texture>	_textures;

														/// Player
	Player*								_player;

														/// Bullet
	Bullet*								_bullet;

														// Private Function
	void								initWindow();
	void								initTextures();
	void								initPlayer();

public:
	Game();

	virtual ~Game();
	
														// Function
	void								run();

	void								updatePollEvents();
	void								updateInput();
	void								update();
	void								render();

};

