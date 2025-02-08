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

	cursorObject.setInput(input);


	jcoleTexture.loadFromFile("gfx/jcolemeal.jpg");
	jcoleMeal.setTexture(&jcoleTexture);
	jcoleMeal.setSize(sf::Vector2f(225, 225));
	jcoleMeal.setPosition(560, 275);
	jcoleMeal.setWindow(window);


	window->setMouseCursorVisible(false);
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

	cursorObject.update(dt);
	jcoleMeal.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(background);
	window->draw(playerObject);
	window->draw(enemyObject);
	window->draw(enemyObject2);

	window->draw(jcoleMeal);

	window->draw(cursorObject);
	endDraw();
}
