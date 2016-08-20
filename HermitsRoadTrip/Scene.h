#pragma once

#include "headers.h"
#include "RV.h"

class Scene
{
public:
	Scene();
	~Scene();

	void Update();
	void Draw(sf::RenderWindow& window);

private:
	std::unique_ptr<RV> rv;
};

