#pragma once

#include "Vector2.hpp"
#include "GameObject.hpp"

class PhysicsObject : public GameObject 
{
private:
	float forceMagnitude;
	Vector2 forceDirection;

protected:
	Vector2 velocity;
	float mass;
	void UpdatePhysics();

public:
	PhysicsObject(std::string name, const char* textureSheetFilePath, sf::RenderWindow* window, SceneManager* sceneManager, Vector2 position = Vector2());

	void SetForce(const Vector2& forceVector);
	void AddForce(const Vector2& forceVector);
};