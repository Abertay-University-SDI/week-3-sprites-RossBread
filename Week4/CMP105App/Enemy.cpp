#include "Enemy.h"

Enemy::Enemy() 
{
	window = nullptr;
	setVelocity(250.f, 300.f);
	goomba.loadFromFile("gfx/Goomba.png");
	setTexture(&goomba);
	setSize(sf::Vector2f(100, 100));
	setPosition(600, 500);
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	move(velocity * dt);

	// right wall
	if (getPosition().x + getSize().x >= window->getSize().x)
	{
		setPosition(window->getSize().x - getSize().x, getPosition().y);
		velocity.x *= -1;
	}

	// left wall
	if (getPosition().x <= 0)
	{
		setPosition(0, getPosition().y);
		velocity.x *= -1;
	}

	// top wall
	if (getPosition().y <= 0)
	{
		setPosition(getPosition().x, 0);
		velocity.y *= -1;
	}

	// bottom wall
	if (getPosition().y + getSize().y >= window->getSize().y)
	{
		setPosition( getPosition().x, window->getSize().y - getSize().y);
		velocity.y *= -1;
	}


}