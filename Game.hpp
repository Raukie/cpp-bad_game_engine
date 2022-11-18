
#include "GameObject.hpp"
#include "SFML/Graphics.hpp";

#ifndef Game_H_INCLUDED
#define Game_H_INCLUDED
class Game {
public:
	Game(sf::RenderWindow& window) : Window(window) {

	}


	std::vector<OBJ::GameObject*> GameObjects = {
		
	};

	void LoadScene(OBJ::Scene scene) {
		for (int i = 0; i < scene.Objects.size(); i++) {
			GameObjects.push_back(scene.Objects[i]);
		}
	}

	virtual void Update(float delta) {
		Window.clear();
		for (int i = 0; i < GameObjects.size(); i++) {
			
			OBJ::GameObject* Object = GameObjects[i];
			Object->Draw(Window);
			Object->Update(GameObjects, delta);
		
			
		}
		Window.display();
	}

	//get all objects with tag return as reference for direct editing and moving of object
	std::vector<OBJ::GameObject*> GetObjectsByTag(std::string tag) {
		std::vector<OBJ::GameObject*> foundObjects;
		for (int i = 0; i < GameObjects.size(); i++) {
			OBJ::GameObject* Object = GameObjects[i];
			if (Object->ObjectTag == tag) {
				foundObjects.push_back(Object);
			}
		}
		return foundObjects;
	}

private:
	sf::RenderWindow& Window;

};


#endif