#include "GameObject.hpp"
#include "SceneManager.hpp"

GameObject::GameObject(std::string name, const char* textureSheetFilePath, sf::RenderWindow* window, SceneManager* sceneManager, Vector2 position)
{
	this->position = position;
	this->window = window;
	this->name = name;
	this->sceneManager = sceneManager;

	this->scale = Vector2(4, 4);
	this->rotation = 0;

	this->forceDirection = Vector2(0, 0);
	this->forceMagnitude = 0;
	this->mass = 0;

	spriteRect.height = 16;
	spriteRect.width = 16;
	spriteRect.top = 0;
	spriteRect.left = 0;

	texture.loadFromFile(textureSheetFilePath);
	sprite = sf::Sprite(texture, spriteRect);
}

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

void GameObject::UpdatePhysics()
{
	float acceleration = forceMagnitude / mass;

	Vector2 displacement = Vector2(
		0.5f * acceleration * pow(FRAME_TIME, 2),
		0.5f * acceleration * pow(FRAME_TIME, 2)
	);

	position.x += displacement.x;
	position.y += displacement.y;
}

void GameObject::SetForce(const Vector2& forceVector)
{
	
}

void GameObject::AddForce(const Vector2& forceVector)
{

}
