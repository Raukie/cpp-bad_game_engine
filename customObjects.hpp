#ifndef customObjects_H_INCLUDED
#define customObjects_H_INCLUDED
#include "GameObject.hpp"
#include "sfml/Graphics.hpp"
const float RandomNumberThatFeelsRight = 0.01;
class Planet : public OBJ::GameObject {
public:
	Planet(float density, float mass, sf::Vector2f pos, sf::Color color, sf::Vector2f initForce) : GameObject((sf::Vector2f(1,1)*mass) * (- density), pos, color, "Planet") {
		Density = density;
		Mass = mass;
		GameObject::SetForce(initForce);
	}
	float Density;
	float Mass;
	
	void CalculateGravity(Planet* targetPlanet) {
		float range = Mass * 3;
		float distanceBetween = GameObject::DistanceToVector(targetPlanet->Shape.getPosition());
		if (range > distanceBetween) {
			sf::Vector2f dir = (targetPlanet->Shape.getPosition() - GameObject::Shape.getPosition());
			float strength = Mass / distanceBetween * RandomNumberThatFeelsRight;
			GameObject::AddForce(dir * strength);
		}
	}
	
	
};


#endif // customObjects_H_INCLUDED