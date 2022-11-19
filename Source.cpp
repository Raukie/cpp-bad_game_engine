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
	planets.push_back(Planet(1, 200, sf::Vector2f(300, 400), sf::Color::Blue, sf::Vector2f(-5, 0)));
	planets.push_back(Planet(1, 200, sf::Vector2f(400, 400), sf::Color::Blue, sf::Vector2f(0, 5)));
	Window.setFramerateLimit(60);
	sf::View vw;
	vw.setSize(1280, 720);
	Game game(Window, vw);
	game.GameObjects.push_back(&planets[0]);
	game.GameObjects.push_back(&planets[1]);
	game.GameObjects.push_back(&planets[2]);
	game.GameObjects.push_back(&planets[3]);
	game.follow = true;
	game.target = &planets[3];
	float force = 0;
	sf::Text txt;
	sf::Font font;
	if(!font.loadFromFile("Minecraft.ttf")){
		return EXIT_FAILURE;
	}
	
	txt.setFont(font);
	txt.setPosition(sf::Vector2f(10, 10));
	txt.setCharacterSize(30);
	txt.setFillColor(sf::Color::White);
	UiObject ForceInfo(sf::Vector2f(10,10), txt);
	game.UiObjects.push_back(&ForceInfo);

	Window.setView(vw);
	//txt.setFillColor(sf::Color::Yellow);
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
		std::vector<OBJ::GameObject*> objects = game.GetObjectsByTag("Planet");
		force = 0;
		for (int i = 0; i < objects.size(); i++) {
			Planet* pln = dynamic_cast<Planet*>(objects[i]);

			force += pln->GetTotalForce();
		}
		
		ForceInfo.textObj.setString("Total force in game: "+std::to_string(force));
		game.Update(delta);
		
	}
}