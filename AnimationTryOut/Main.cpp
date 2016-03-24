#include "stdafx.h"
#include "Main.h"

#include "SpriteSheet.h"

void Main::start()
{
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Animating...");
	_clock.restart();

	while (_mainWindow.isOpen())
	{
		update(_clock.restart());
		draw(_mainWindow);
		handleInput(_mainWindow);
	}
}

void Main::handleInput(sf::RenderWindow& renderWindow)
{
	sf::Event ev;
	while (renderWindow.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			renderWindow.close();
		}
	}
}

void Main::update(sf::Time& delta)
{
	std::cout << "Previous frame took " << delta.asMicroseconds() << std::endl;
	_stella.update(delta);
}

void Main::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.clear(sf::Color(0, 0, 0));

	_stella.draw(renderWindow);
	
	renderWindow.display();
}

sf::RenderWindow Main::_mainWindow;
sf::Clock Main::_clock;

Stella Main::_stella(100, 100);