#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

class Player
{
private:
	sf::Sprite					_sprite;
	sf::Texture					_texture;

	float						_movemetSpeed;

															// Function private
	void						initTexture();
	void						initSprite();

public:
	Player();
	virtual ~Player();

															// Function public
	void						move(const float dirX, const float dirY);

	void						update();
	void						render(sf::RenderTarget& target);
};

