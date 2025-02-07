#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	// player

	playerObject.setInput(input);

	// enemies
	enemyObject.setWindow(window);

	enemyObject2.setWindow(window);
	enemyTexture2.loadFromFile("gfx/nidoran.jpg");
	enemyObject2.setTexture(&enemyTexture2);
	enemyObject2.setPosition(800, 400);

	background.setWindow(hwnd);
	background.setInput(in);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	playerObject.handleInput(dt);
	background.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	enemyObject.update(dt);
	enemyObject2.update(dt);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(background);
	window->draw(playerObject);
	window->draw(enemyObject);
	window->draw(enemyObject2);

	endDraw();
}
