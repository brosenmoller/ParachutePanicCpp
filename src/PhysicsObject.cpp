#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject(std::string name, const char* textureSheetFilePath, sf::RenderWindow* window, SceneManager* sceneManager, Vector2 position)
	: GameObject(name, textureSheetFilePath, window, sceneManager, position), forceDirection(Vector2(0, 0)), velocity(Vector2(0, 0)), forceMagnitude(0), mass(10)
{}

void PhysicsObject::UpdatePhysics()
{
	float gravityForce = mass * GRAVITY_CONSTANT;
	float forceResitance = gravityForce * FRICTION_COEFFICIENT;

	// When object doesn't have a force, keep the force direction so that the resitance can be applied correctly
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
}

void PhysicsObject::SetForce(const Vector2& forceVector)
{
	forceMagnitude = forceVector.Magnitude();
	forceDirection = forceVector.Normalized();
}

void PhysicsObject::AddForce(const Vector2& forceVector)
{
	forceDirection = (forceVector.Normalized() + forceDirection).Normalized();
	forceMagnitude = forceDirection.Magnitude();
}