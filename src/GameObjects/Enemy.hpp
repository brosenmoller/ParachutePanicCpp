#pragma once

#include "../PhysicsObject.hpp"

class Enemy : public PhysicsObject
{
	using PhysicsObject::PhysicsObject;

	virtual void Start() override;
	virtual void Update() override;
private:
	int speed;
	int collisionRange;
};