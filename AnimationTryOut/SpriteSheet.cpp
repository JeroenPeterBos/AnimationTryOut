#include "stdafx.h"
#include "SpriteSheet.h"
#include <SFML/Graphics/Rect.hpp>


SpriteSheet::SpriteSheet(std::string filename, int w, int h, int x, int y)
	: _noSpritesX(x), _noSpritesY(y)
{
	for (int i = 0; i < x * y; i++) {
		sf::Texture tex;
		tex.loadFromFile(filename, sf::Rect<int>((i % x) * w, (i / x) * h, w, h));
		sheet.push_back(tex);
	}
}


SpriteSheet::~SpriteSheet()
{
}

sf::Texture& SpriteSheet::getTexture(int x, int y)
{
	return sheet.at(y * _noSpritesX + x);
}