#include "SpriteLoader.h"

std::shared_ptr<sf::Sprite> SpriteLoader::GetSprite(std::string filename)
{
	std::shared_ptr<sf::Texture> texture;
	filename = "../Assets/" + filename + ".png";

	std::map<std::string, std::shared_ptr<sf::Texture>>::iterator textureIterator = textures.find(filename);
	if (textureIterator != textures.end())
	{
		std::cout << "Reused file: " + filename << std::endl;
		return std::make_shared<sf::Sprite>(sf::Sprite(*textureIterator->second));
	}
	else
	{
		return std::make_shared<sf::Sprite>(sf::Sprite(*loadTexture(filename)));
	}
}

std::shared_ptr<sf::Texture> SpriteLoader::loadTexture(std::string filename)
{
	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>(sf::Texture());
	
	if (!texture->loadFromFile(filename))
	{
		std::cout << "Error loading file: " + filename << std::endl;
	}
	else
	{
		std::cout << "Successfully loaded file: " + filename << std::endl;
	}

	textures[filename] = texture;

	return texture;
}