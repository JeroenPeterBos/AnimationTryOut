#pragma once
#include "stdafx.h"

class SpriteSheet
{
public:
	SpriteSheet(std::string filename, int w, int h, int x, int y);
	~SpriteSheet();

	sf::Texture& getTexture(int x, int y);

private:
	std::vector<sf::Texture> sheet;
	int _noSpritesX;
	int _noSpritesY;
};

