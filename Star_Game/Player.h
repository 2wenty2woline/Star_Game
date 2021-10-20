#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class Player
{
private:
	sf::Sprite					_sprite;
	sf::Texture					_texture;

															// Function private
	void						initTexture();
	void						initSprite();

public:
	Player();
	virtual ~Player();

															// Function public

	void						update();
	void						render(sf::RenderTarget& target);
};

