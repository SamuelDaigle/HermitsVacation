#include "RV.h"



RV::RV()
{
    base = SpriteLoader::GetSprite("rv_base");
	inside = SpriteLoader::GetSprite("rv_inside");
	wheelLeft = SpriteLoader::GetSprite("rv_wheel");
	wheelRight = SpriteLoader::GetSprite("rv_wheel");

	base->setPosition(sf::Vector2<float>(0, 0));
	base->setScale(sf::Vector2<float>(20, 20));
}


RV::~RV()
{
}

void RV::Draw(sf::RenderWindow& window)
{
	window.draw(*inside);
	window.draw(*base);
	window.draw(*wheelLeft);
	window.draw(*wheelRight);
}