#pragma once
#include "stdafx.h"
#include "Stella.h"

class Main
{
public:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;

	static void start();

private:
	static void handleInput(sf::RenderWindow& renderWindow);
	static void update(sf::Time& delta);
	static void draw(sf::RenderWindow& renderWindow);

	static sf::RenderWindow _mainWindow;
	static sf::Clock _clock;

	static Stella _stella;
};