#pragma once
#include "GameManager.hpp"
#include "Vector2.hpp"
#include "LogManager.hpp"

class GameObject
{
public:
	GameObject(std::string name, const char* textureSheetFilePath, sf::RenderWindow* window, Vector2 position = Vector2());
	~GameObject();

	Vector2* GetPosition();
	Vector2* GetScale();
	float GetRotation();

	virtual void Start();
	virtual void Update();
	void Render();

	std::string GetName() { return name; }

protected:
	Vector2 position;
	Vector2 scale;
	float rotation;
	std::string name;

	sf::RenderWindow* window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect spriteRect;
};