#pragma once
#include "Vector2.hpp"
#include "LogManager.hpp"
#include "GameData.hpp"
#include <string>
#include <SFML/Graphics.hpp>

class SceneManager;

class GameObject
{
protected:
	Vector2 position;
	Vector2 scale;
	float rotation;
	std::string name;

	SceneManager* sceneManager;
	sf::RenderWindow* window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect spriteRect;

public:
	GameObject(std::string name, const char* textureSheetFilePath, sf::RenderWindow* window, SceneManager* sceneManager, Vector2 position = Vector2());
	~GameObject() {}

	Vector2* GetPosition();
	Vector2* GetScale();
	float GetRotation();

	virtual void Start() {}
	virtual void Update() {}
	void Render();

	std::string GetName() { return name; }

// Physics System
private:
	float forceMagnitude;
	Vector2 forceDirection;
	float mass;

protected:
	void UpdatePhysics();

public:
	void SetForce(const Vector2& forceVector);
	void AddForce(const Vector2& forceVector);
};