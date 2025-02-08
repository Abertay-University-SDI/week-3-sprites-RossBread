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
	static float viewX;

	sf::View v = window->getView();

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		v.move(400.f * dt, 0);
		viewX += 400.f * dt;
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		v.move(-400.f * dt, 0);
		viewX -= 400.f * dt;
	}

	if (viewX < 0)
	{
		v.move(400.f * dt, 0);
		viewX += 400.f * dt;
	}

	if (viewX > 11038 - window->getSize().x)
	{
		v.move(-400.f * dt, 0);
		viewX -= 400.f * dt;
	}

	window->setView(v);
};