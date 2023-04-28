#pragma once

#include "../GameObject.hpp"

class Enemy : public GameObject
{
	using GameObject::GameObject;

	virtual void Start() override;
	virtual void Update() override;
private:
	int speed;
	int collisionRange;
};