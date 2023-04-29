#pragma once

#include "../GameObject.hpp"

class Player : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void Start() override;
	virtual void Update() override;
private:
	int speed;
	int timePerScorePoint;
	sf::Clock scoreClock;
	sf::Clock animationClock;
};