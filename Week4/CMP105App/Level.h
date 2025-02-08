#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Cursor.h"
#include <string.h>
#include <iostream>


class Level : BaseLevel {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

private:
	// Level objects
	Player playerObject;


	Enemy enemyObject;
	Enemy enemyObject2;
	sf::Texture enemyTexture2;

	Background background;

	Cursor cursorObject;

	// task 6 i promise
	Enemy jcoleMeal;
	sf::Texture jcoleTexture;
};