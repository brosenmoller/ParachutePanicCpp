#include "GameObject.hpp"
#include "SceneManager.hpp"

GameObject::GameObject(std::string name, const char* textureSheetFilePath, sf::RenderWindow* window, SceneManager* sceneManager, Vector2 position)
	: position(position), window(window), name(name), sceneManager(sceneManager), scale(Vector2(4, 4)), rotation(0)
{
	spriteRect.height = 16;
	spriteRect.width = 16;
	spriteRect.top = 0;
	spriteRect.left = 0;

	texture.loadFromFile(textureSheetFilePath);
	sprite = sf::Sprite(texture, spriteRect);
}

Vector2 GameObject::GetPosition()
{
	return position;
}

Vector2 GameObject::GetScale()
{
	return scale;
}

float GameObject::GetRotation()
{
	return rotation;
}

void GameObject::Render()
{
	sprite.setRotation(rotation);
	sprite.setScale(scale.x, scale.y);
	sprite.setPosition(position.x, position.y);

	window->draw(sprite);
}
