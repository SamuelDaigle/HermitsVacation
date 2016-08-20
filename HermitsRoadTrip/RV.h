#pragma once

#include "headers.h"

class RV
{
public:
	RV();
	~RV();

	void Draw(sf::RenderWindow& window);

private:
	std::shared_ptr<sf::Sprite> base;
	std::shared_ptr<sf::Sprite> inside;
	std::shared_ptr<sf::Sprite> wheelLeft;
	std::shared_ptr<sf::Sprite> wheelRight;
};

