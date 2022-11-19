#include "GameObject.hpp"
#include "sfml/Graphics.hpp"

#ifndef customObjects_H_INCLUDED
#define customObjects_H_INCLUDED


const float slowmo = 0.1;;
const float RandomNumberThatFeelsRight = 0.01;
class Planet : public OBJ::GameObject {
public:
	Planet(float density, float mass, sf::Vector2f pos, sf::Color color, sf::Vector2f initForce) : GameObject("Planet") {
		Density = density;
		Mass = mass;
		SetForce(initForce);
		Pos = pos;
		Shape.setRadius((1 * mass * density  * 0.3f)/2);
		Shape.setPosition(pos);
		Shape.setFillColor(color);
	}
	float Density;
	float Mass;
	sf::CircleShape Shape;
	void CalculateGravity(Planet* targetPlanet) {
		float range = Mass * 4;
		float distanceBetween = DistanceToVector(targetPlanet->Pos);
		if (distanceBetween != 0) {
			if (range > distanceBetween) {
				sf::Vector2f dir = (targetPlanet->Pos - Pos);
				float strength = Mass / distanceBetween * RandomNumberThatFeelsRight * slowmo;
				AddForce(dir * strength);
			}
		}
		     
	}

	float GetTotalForce() {
		return std::abs(this->ForceThisFrame.x) + std::abs(this->ForceThisFrame.y);
	}

	void Update(std::vector<OBJ::GameObject*>& objects, float delta) {
		Shape.setPosition(GameObject::Pos);
		if (Kinectic)
			Pos = Pos + Force;
		std::vector<OBJ::GameObject*> Objects = GetObjectsByTag(objects, "Planet");
			for (int j = 0; j < Objects.size(); j++) {
					CalculateGravity(dynamic_cast<Planet*>(Objects[j]));
			}
	}

	void Draw(sf::RenderWindow& Window) {
		Window.draw(Shape);
	}
	
	
};

class UiObject : public OBJ::GameObject {
public:
	UiObject(sf::Vector2f initPos, sf::Text text) : GameObject("UI") {
		Pos = initPos;
		textObj = text;
	}

	sf::Text textObj;

	void Update(std::vector<OBJ::GameObject*>& objects, float delta) {
		textObj.setPosition(Pos);
	}

	void Draw(sf::RenderWindow& Window) {
		Window.draw(textObj);
	}
};


#endif // customObjects_H_INCLUDED