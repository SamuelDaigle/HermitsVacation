#pragma once

#include "headers.h"
#include <map>
#include <iterator>

class SpriteLoader
{
public:
	static std::shared_ptr<sf::Sprite> GetSprite(std::string filename);

private:
	SpriteLoader() {}
	static std::shared_ptr<sf::Texture> loadTexture(std::string filename);

	static std::map<std::string, std::shared_ptr<sf::Texture>> textures;
};

