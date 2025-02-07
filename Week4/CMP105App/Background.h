#pragma once
#include "Framework/GameObject.h"

class Background : public GameObject
{
public:
	Background();
	~Background();

	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* wnd);

	sf::Texture background;
	sf::RenderWindow wnd;
	Input in;
};

