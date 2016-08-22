#include "headers.h"
#include "Scene.h"

std::map<std::string, std::shared_ptr<sf::Texture>> SpriteLoader::textures = {};

int main()
{
	sf::Vector2<int> windowedSize(1024, 576);
	float ratio = windowedSize.x / windowedSize.y;
	std::string windowTitle = "Hermit's vacation";

	sf::RenderWindow window(sf::VideoMode(windowedSize.x, windowedSize.y), windowTitle, sf::Style::Close);
	window.setFramerateLimit(60);
	sf::View view = window.getDefaultView();
	window.setView(view);
	Scene scene;
	bool fullscreen = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed 
				|| ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				window.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F)) {
				fullscreen = !fullscreen;
				if (fullscreen)
				{
					window.create(sf::VideoMode(windowedSize.x, windowedSize.y), windowTitle, sf::Style::Fullscreen);
					window.setView(view);
				}
				else
				{
					window.create(sf::VideoMode(windowedSize.x, windowedSize.y), windowTitle, sf::Style::Close);
				}
			}
		}

		window.clear();

		scene.Update();
		scene.Draw(window);

		window.display();
	}

	return 0;
}