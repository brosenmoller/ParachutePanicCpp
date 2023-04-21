#include "GameObject.hpp"

GameObject::GameObject(std::string name, const char* textureSheetFilePath, sf::RenderWindow* window, Vector2 position)
{
	this->position = position;
	this->window = window;
	this->name = name;

	this->scale = Vector2(4, 4);
	this->rotation = 0;

	spriteRect.height = 16;
	spriteRect.width = 16;
	spriteRect.top = 0;
	spriteRect.left = 0;

	texture.loadFromFile(textureSheetFilePath);
	sprite = sf::Sprite(texture, spriteRect);
}

GameObject::~GameObject()
{}

Vector2* GameObject::GetPosition()
{
	return &position;
}

Vector2* GameObject::GetScale()
{
	return &scale;
}

float GameObject::GetRotation()
{
	return rotation;
}

void GameObject::Render()
{
	sprite.setRotation(rotation);
	sprite.setScale(sf::Vector2f(scale.x, scale.y));
	sprite.setPosition(sf::Vector2f(position.x, position.y));

	window->draw(sprite);
}
