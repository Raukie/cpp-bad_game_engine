#include "Game.hpp"
#include "sfml/Graphics.hpp"

#ifndef customObjects_H_INCLUDED
#define customObjects_H_INCLUDED


const float slowmo = 1;
const float RandomNumberThatFeelsRight = 0.01;
class Planet : public OBJ::GameObject {
public:
	Planet(float density, float mass, sf::Vector2f pos, sf::Color color, sf::Vector2f initForce) : GameObject("Planet", &this->Shape, 'R') {
		Density = density;
		Mass = mass;
		GameObject::SetForce(initForce);
		Shape.setSize((sf::Vector2f(1, 1) * mass) * (-density));
		Shape.setPosition(pos);
		Shape.setFillColor(color);
	}
	float Density;
	float Mass;
	sf::RectangleShape Shape;
	void CalculateGravity(Planet* targetPlanet) {
		float range = Mass * 4;
		float distanceBetween = GameObject::DistanceToVector(Shape.getPosition());
		if (range > distanceBetween) {
			sf::Vector2f dir = (targetPlanet->Shape.getPosition() - Shape.getPosition());
			float strength = Mass / distanceBetween * RandomNumberThatFeelsRight * slowmo;
			GameObject::AddForce(dir * strength);
		}
	}

	void Update(Game& game) {
		Shape.setPosition(GameObject::Pos);
		if (GameObject::Kinectic)
			GameObject::Pos = Pos + Force;
		std::vector<OBJ::GameObject*> Objects = game.GetObjectsByTag("Planet");
			for (int j = 0; j < Objects.size(); j++) {
					CalculateGravity(dynamic_cast<Planet*>(Objects[j]));
			}
	}

	void Draw(sf::RenderWindow& Window) {
		Window.draw(Shape);
	}
	
	
};


#endif // customObjects_H_INCLUDED