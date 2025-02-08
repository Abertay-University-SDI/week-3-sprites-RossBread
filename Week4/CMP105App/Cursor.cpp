#include "Cursor.h"

Cursor::Cursor()
{
	cursorTexture.loadFromFile("gfx/icon.png");
	setTexture(&cursorTexture);
	setSize(sf::Vector2f(48, 48));
};
Cursor::~Cursor()
{

};
void Cursor::update(float dt) 
{
	setPosition(input->getMouseX(), input->getMouseY());
};
