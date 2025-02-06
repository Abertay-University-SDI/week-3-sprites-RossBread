#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	// player
	playerObject.setInput(input);
	playerTexture.loadFromFile("gfx/Mushroom.png");
	playerObject.setTexture(&playerTexture);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(200, 300);

	enemyObject.setWindow(window);
	enemyTexture.loadFromFile("gfx/goomba.png");
	enemyObject.setTexture(&enemyTexture);
	enemyObject.setSize(sf::Vector2f(100, 100));
	enemyObject.setPosition(500, 900);

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
}

// Update game objects
void Level::update(float dt)
{
	enemyObject.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(testSprite);
	window->draw(playerObject);
	window->draw(enemyObject);

	endDraw();
}
