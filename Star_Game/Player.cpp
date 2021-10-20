#include "Player.h"

void Player::initTexture()
{

}

void Player::initSprite()
{

}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

																			// Function
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(_sprite);
}
