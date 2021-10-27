#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Enemy
{
private:
	sf::CircleShape				_shape;

	unsigned					_pointCount;
	int							_type;
	float						_speed;
	int							_hp;
	int							_hpMax;
	int							_damage;
	int							_points;

	void						initVariables();
	void						initShape();


public:
	Enemy(float pos_X, float pos_Y);

	virtual ~Enemy();

															// Accessors
	const sf::FloatRect			getBounds() const;
	const int&					getPoints() const;
	const int&					getDamage()	const;

															// Function
	void						update();
	void						render(sf::RenderTarget* target);
};

