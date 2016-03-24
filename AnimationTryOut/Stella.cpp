#include "stdafx.h"
#include "Stella.h"


Stella::Stella(int x, int y)
	: _sheet("images/stella_walk.png", 64, 64, 4, 8), _direction(4)
{
	_sprite.setPosition(x, y);
}


Stella::~Stella()
{
}

void Stella::update(sf::Time& delta)
{
	_animationCounter = (_animationCounter + delta.asMilliseconds()) % 400;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			_direction = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			_direction = 6;
		}
		else
		{
			_direction = 3;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			_direction = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			_direction = 8;
		}
		else
		{
			_direction = 5;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		_direction = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
	{
		_direction = 7;
	}
	else
	{
		_direction = 4;
	}
}

void Stella::draw(sf::RenderWindow& renderWindow)
{
	switch (_direction) {
	case 0:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 6));
		break;
	case 1:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 3));
		break;
	case 2:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 7));
		break;
	case 3:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 1));
		break;
	case 4:
		_sprite.setTexture(_sheet.getTexture(0, 0));
		break;
	case 5:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 2));
		break;
	case 6:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 5));
		break;
	case 7:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 0));
		break;
	case 8:
		_sprite.setTexture(_sheet.getTexture((_animationCounter / 100), 4));
		break;
	}

	renderWindow.draw(_sprite);
}