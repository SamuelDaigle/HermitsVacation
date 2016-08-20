#include "Scene.h"



Scene::Scene()
{
	rv = std::make_unique<RV>(RV());
}


Scene::~Scene()
{
	rv.release();
}


void Scene::Update()
{

}

void Scene::Draw(sf::RenderWindow& window)
{
	rv->Draw(window);
}