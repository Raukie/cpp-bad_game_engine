#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include "customObjects.hpp"
//main loop
int main() {
	sf::RenderWindow Window(sf::VideoMode(1280, 720), "MyProgram");
	std::vector<Planet> planets;
	planets.push_back(Planet(1, 200, sf::Vector2f(600, 300), sf::Color::White, sf::Vector2f(5,0)));
	planets.push_back(Planet(1, 200, sf::Vector2f(600, 500), sf::Color::Cyan, sf::Vector2f(0, -5)));
	planets.push_back(Planet(1, 200, sf::Vector2f(300, 400), sf::Color::Blue, sf::Vector2f(-6, 0)));
	planets.push_back(Planet(1, 200, sf::Vector2f(400, 400), sf::Color::Blue, sf::Vector2f(1, 5)));
	Window.setFramerateLimit(60);
	Game game(Window);
	game.GameObjects.push_back(&planets[0]);
	game.GameObjects.push_back(&planets[1]);
	game.GameObjects.push_back(&planets[2]);
	game.GameObjects.push_back(&planets[3]);
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

		
		
		game.Update(delta);
	}
}