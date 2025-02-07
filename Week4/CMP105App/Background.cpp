#include "Background.h"

Background::Background()
{
	background.loadFromFile("gfx/Level1_1.png");
	setTexture(&background);
	setSize(sf::Vector2f(11038, 675));
};

Background::~Background()
{

}

void Background::setWindow(sf::RenderWindow* wnd)
{
	window = wnd;
}

void Background::handleInput(float dt)
{
	sf::View v = window->getView();

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		v.move(200.f * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		v.move(-200.f * dt, 0);
	}

	s

	window->setView(v);
};