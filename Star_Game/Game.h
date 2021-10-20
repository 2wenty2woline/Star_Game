#pragma once

#include "Player.h"

class Game
{
private:
	sf::RenderWindow*			_window;

														// Player
	Player*						_player;

														// Private Function
	void						initWindow();
	void						initPlayer();

	void						movementPlayer();

public:
	Game();

	virtual ~Game();
	
														// Function
	void						run();
	
	void						update();
	void						render();

};

