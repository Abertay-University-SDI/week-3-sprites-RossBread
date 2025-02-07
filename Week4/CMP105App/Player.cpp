#include "Player.h"
#include <iostream>

// Constructor
Player::Player()
{

	mushroom.loadFromFile("gfx/Mushroom.png");
	setTexture(&mushroom);
	setSize(sf::Vector2f(100, 100));
	setPosition(200, 300);
}

// Destructor
Player::~Player()
{

}

void Player::handleInput(float dt)
{
	// Player movement
	if (input->isKeyDown(sf::Keyboard::W))
	{
		setVelocity(0, -200.f);
		move(velocity * dt);
	}

	if (input->isKeyDown(sf::Keyboard::A))
	{
		setVelocity(-200.f, 0);
		move(velocity * dt);
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		setVelocity(0, 200.f);
		move(velocity * dt);
	}

	if (input->isKeyDown(sf::Keyboard::D))
	{
		setVelocity(200.f, 0);
		move(velocity * dt);
	}


}



