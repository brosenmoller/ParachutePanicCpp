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
	this->velocity = Vector2(0, 0);
	this->forceMagnitude = 0;
	this->mass = 10;

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
	sprite.setScale(sf::Vector2f(scale.x, scale.y));
	sprite.setPosition(sf::Vector2f(position.x, position.y));

	window->draw(sprite);
}

void GameObject::InitializePhysics()
{
	gravityForce = GRAVITY_CONSTANT * mass;
}

void GameObject::UpdatePhysics()
{
	float forceResitance = gravityForce * FRICTION_COEFFICIENT;

	if (forceMagnitude < forceResitance && velocity != Vector2::Zero())
	{
		forceDirection = velocity.Normalized();
	}

	float forceResulting = forceMagnitude - forceResitance;
	float acceleration = forceResulting / mass;
	
	velocity.x += acceleration * FRAME_TIME * forceDirection.x;
	velocity.y += acceleration * FRAME_TIME * forceDirection.y;
	
	Vector2 displacement = velocity * FRAME_TIME;
	
	position.x += displacement.x;
	position.y += displacement.y;

	//LogInfo("Force Resistance: " + std::to_string(forceResitance));
	//LogInfo("Force Resulting: " + std::to_string(forceResitance));
	//LogInfo("Acceleration: " + std::to_string(forceResitance));
	//LogInfo("FRAME_TIME: " + std::to_string(FRAME_TIME));
	//LogInfo("forceDirection X: " + std::to_string(forceDirection.x));
	//LogInfo("Velocity X: " + std::to_string(velocity.x));
	//LogInfo("Deplacement X: " + std::to_string(displacement.x));
	//LogInfo("Position X: " + std::to_string(position.x));
}

void GameObject::SetForce(const Vector2& forceVector)
{
	forceMagnitude = forceVector.Magnitude();
	forceDirection = forceVector.Normalized();
}

void GameObject::AddForce(const Vector2& forceVector)
{
	forceDirection = (forceVector.Normalized() + forceDirection).Normalized();
	forceMagnitude = forceDirection.Magnitude();
}
