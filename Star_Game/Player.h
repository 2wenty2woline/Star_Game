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
	float						_coolDown;
	float						_coolDownMax;

	int							_hp;
	int							_hpMax;

															// Function private
	void						initVariables();
	void						initTexture();
	void						initSprite();

public:
	Player();
	virtual ~Player();

															// Accessor
	const sf::Vector2f&			getPos()const;
	const sf::FloatRect			getBounds() const;
	const int&					getHp() const;
	const int&					getHpMax() const;

															// Modifie
	void						setPosition(const sf::Vector2f pos);
	void						setPosition(const float pos_x, const float pos_y);
	void						setHp(const int hp);
	void						loosHp(const int value);

															// Function public
	void						move(const float dirX, const float dirY);
	const bool					canAttack();

	void						updateAttack();
	void						update();

	void						render(sf::RenderTarget& target);
};

