#include "Player.h"

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
	_movemetSpeed	= 3.f;

	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	_sprite.move(_movemetSpeed * dirX, _movemetSpeed * dirY);
}

// Function
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(_sprite);
}
