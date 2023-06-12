#pragma once

#include "../PhysicsObject.hpp"

class Player : public PhysicsObject
{
public:
	using PhysicsObject::PhysicsObject;

	virtual void Start() override;
	virtual void Update() override;
private:
	float power;
	int timePerScorePoint;
	sf::Clock scoreClock;
	sf::Clock animationClock;
};