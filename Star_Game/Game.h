#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

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

