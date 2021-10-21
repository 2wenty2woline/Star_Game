#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

class Bullet
{
private:

	sf::Sprite				_shape;
	sf::Vector2f			_direction;
	
	float					_movementSpeed;

public:

																					// Const/Dest
	Bullet();
	Bullet(sf::Texture& texture, float dir_x, float dir_y, float movement_Speed);
	virtual ~Bullet();

																					// Private function

	void					update();
	void					render(sf::RenderTarget& target);

};

