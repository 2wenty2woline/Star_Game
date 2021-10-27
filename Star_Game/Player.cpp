#include "Player.h"

void Player::initVariables()
{
	_movemetSpeed	= 6.f;

	_coolDownMax	= 10.f;
	_coolDown		= _coolDownMax;

	_hpMax			= 100;
	_hp				= _hpMax;
}

void Player::initTexture()
{
																			// Load a texture from file
	if (!_texture.loadFromFile("Textures/star-ship.png"))
	{
		std::cout << " ! ERROR::PLAYER::INITTEXTURE::Could not load file" << std::endl;
	}
}

void Player::initSprite()
{
																			// Set texture to the sprite
	_sprite.setTexture(_texture);

																			// Resize the spritre
	_sprite.scale(0.1f, 0.1f);
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

const sf::Vector2f & Player::getPos() const
{
	return _sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return _sprite.getGlobalBounds();
}

const int & Player::getHp() const
{
	return _hp;
}

const int & Player::getHpMax() const
{
	return _hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	_sprite.setPosition(pos);
}

void Player::setPosition(const float pos_x, const float pos_y)
{
	_sprite.setPosition(pos_x, pos_y);
}

void Player::setHp(const int hp)
{
	_hp = hp;
	if (_hp < 0)
		_hp = 0;
}

void Player::loosHp(const int value)
{
	_hp -= value;
}

void Player::move(const float dirX, const float dirY)
{
	_sprite.move(_movemetSpeed * dirX, _movemetSpeed * dirY);
}

const bool Player::canAttack()
{
	if (_coolDown >= _coolDownMax)
	{
		_coolDown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if (_coolDown < _coolDownMax)
	{
		_coolDown += 0.5f;
	}
}

// Function
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(_sprite);
}
