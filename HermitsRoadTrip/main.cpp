#include "headers.h"
#include "Scene.h"

std::map<std::string, std::shared_ptr<sf::Texture>> SpriteLoader::textures = {};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hermit's vacation");
	sf::View view(sf::FloatRect(0, 0, 800, 600));
	window.setView(view);
	Scene scene;
	bool fullscreen = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F)) {
				fullscreen = !fullscreen;
				window.create(sf::VideoMode(800, 600, 16), "SFML Test", (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize | sf::Style::Close));
			}
		}

		window.clear();

		scene.Update();
		scene.Draw(window);

		window.display();
	}

	return 0;
}