#pragma once

#include "../GameObject.hpp"
#include "Enemy.hpp"

class EnemySpawner : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void Start() override;
	virtual void Update() override;

private:
	sf::Clock clock;
	int spawnDelay;
	int decreaseAmount;
};