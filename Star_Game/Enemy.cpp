#include "Enemy.h"

void Enemy::initVariables()
{
	_pointCount = rand() % 8 + 3;
	_type		= 0; 
	_speed		= static_cast<float>(static_cast<unsigned>(_pointCount / 2));
	_hpMax		= static_cast<int>(_pointCount);
	_hp			= _hpMax;
	_damage		= _pointCount;
	_points		= _pointCount;
}

void Enemy::initShape()
{
	_shape.setRadius(_pointCount * 3);
	_shape.setPointCount(_pointCount); sf::Color(255, 255, 255);
	_shape.setFillColor(sf::Color(rand() % 255 + 1,
		rand() % 255 + 1,
		rand() % 255 + 1, 255));
}

Enemy::Enemy(float pos_X, float pos_Y)
{
	this->initVariables();
	this->initShape();

	_shape.setPosition(pos_X, pos_Y);

}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
	return _shape.getGlobalBounds();
}

const int & Enemy::getPoints() const
{
	return _points;
}

const int & Enemy::getDamage() const
{
	return _damage;
}

														// Functions
void Enemy::update()
{
	_shape.move(0.f, _speed);
}

void Enemy::render(sf::RenderTarget * target)
{
	target->draw(_shape);
}
