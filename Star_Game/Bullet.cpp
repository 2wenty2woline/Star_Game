#include "Bullet.h"

Bullet::Bullet()
{
	
}

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, 
									 float dir_x, float dir_y, float movement_Speed)
{
	_shape.setTexture(*texture);
	_shape.scale(0.5f, 0.5f);

	_shape.setPosition(pos_x, pos_y);
	_direction.x				= dir_x;
	_direction.y				= dir_y;
	_movementSpeed				= movement_Speed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return _shape.getGlobalBounds();
}

void Bullet::update()
{
																							// Movement bullet
	_shape.move(_movementSpeed * _direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(_shape);
}
