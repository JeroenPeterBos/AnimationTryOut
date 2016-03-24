#pragma once
#include "SpriteSheet.h"

class Stella
{
public:
	Stella(int x, int y);
	~Stella();

	void update(sf::Time& delta);
	void draw(sf::RenderWindow& renderWindow);
private:
	SpriteSheet _sheet;
	sf::Sprite _sprite;
	int _direction;
	int _animationCounter;
};


