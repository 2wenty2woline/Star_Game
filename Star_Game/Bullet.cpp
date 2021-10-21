#include "Bullet.h"

Bullet::Bullet()
{
	
}

Bullet::Bullet(sf::Texture& texture, float dir_x, float dir_y, float movement_Speed)
{
	_shape.setTexture(texture);
	_direction.x				= dir_x;
	_direction.y				= dir_y;
	_movementSpeed				= movement_Speed;
}

Bullet::~Bullet()
{

}

void Bullet::update()
{
																							// Movement bullet
	_shape.move(_movementSpeed * _direction);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(_shape);
}
