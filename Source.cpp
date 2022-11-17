#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include "CustomObjects.hpp";

//main loop
int main() {
	sf::RenderWindow Window(sf::VideoMode(1280, 720), "MyProgram");
	std::vector<Planet> planets;
	planets.push_back(Planet(1, 200, sf::Vector2f(300,300), sf::Color::Cyan, sf::Vector2f(5,0)));
	planets.push_back(Planet(1, 200, sf::Vector2f(600, 500), sf::Color::Cyan, sf::Vector2f(-5, 0)));
	Window.setFramerateLimit(60);
	Game game(Window);
	game.GameObjects.push_back(&planets[0]);
	game.GameObjects.push_back(&planets[1]);
	sf::Clock clock;

	while (Window.isOpen()) {
		sf::Event Event;
		sf::RectangleShape rect;
		sf::Vector2f rectPos(600, 350);
		rect.setSize(sf::Vector2f(200, 200));
		sf::Time time = clock.restart();
		float delta = time.asMicroseconds();
		while (Window.pollEvent(Event)) {
			//close window if window is closed on desktop
			if (Event.type == sf::Event::Closed) Window.close();
		}

		
		std::vector<OBJ::GameObject*> Objects = game.GetObjectsByTag("Planet");

		for (int i = 0; i < Objects.size(); i++) {
			Planet* planet = dynamic_cast<Planet*> (Objects[i]);

			for (int j = 0; j < Objects.size(); j++) {
				if(j!=i)
					planet->CalculateGravity(dynamic_cast<Planet*>(Objects[j]));
			}
		}
		game.update();
	}
}