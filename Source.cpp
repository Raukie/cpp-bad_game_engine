#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include "customObjects.hpp"
//main loop
int main() {
	sf::RenderWindow Window(sf::VideoMode(1280, 720), "MyProgram");
	std::vector<Planet> planets;
	planets.push_back(Planet(1, 200, sf::Vector2f(0,300), sf::Color::Cyan, sf::Vector2f(5,0)));
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

		
		
		game.Update(delta);
	}
}