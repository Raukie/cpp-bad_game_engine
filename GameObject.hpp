#include "sfml/Graphics.hpp";

#ifndef GameObject_H_INCLUDED
#define GameObject_H_INCLUDED

namespace OBJ {
	
	class GameObject {
	public:

		GameObject(sf::Vector2f size, sf::Vector2f initPos, sf::Color color, std::string tag) {
			Shape.setPosition(initPos);
			Shape.setSize(size);
			Shape.setFillColor(color);
			ObjectTag = tag;
			Force = sf::Vector2f(0, 0);
		}
		
		std::string ObjectTag;
		sf::RectangleShape Shape;
		sf::Vector2f Force;

		bool Kinectic = false;


		void MoveTo(sf::Vector2f vec2) {
			Shape.setPosition(vec2);
		}

		void SetScale(int x, int y) {
			Shape.setScale(x, y);
		}

		void SetForce(sf::Vector2f vec2) {
			Kinectic = true;
			Force = vec2;
		}

		void AddForce(sf::Vector2f vec2) {
			Kinectic = true;
			Force += vec2;
		}
		
		float DistanceToVector(sf::Vector2f vec2) {
			sf::Vector2f dif = Shape.getPosition() - vec2;
			float d = std::abs(dif.x);
			float y = std::abs(dif.y);
			return std::sqrt(d*d + y*y);
		}
		//has to be called each frame rendered
		void Update() {
			if (Kinectic)
				Shape.setPosition(Shape.getPosition() + Force);
		}

		virtual ~GameObject() {

		}
	};

	class Scene {
	public:
		Scene(std::vector<OBJ::GameObject*> objects) {
			Objects = objects;
		}
		std::vector<GameObject*> Objects;
	};
}


#endif // GameObject_H_INCLUDED