#pragma once

#include "Player.h"

class Game
{
private:
	sf::RenderWindow*			_window;

	// Private Function
	void						initWindow();

public:
	Game();

	virtual ~Game();
	
														// Function
	void						run();
	
	void						update();
	void						render();

};

