#pragma once

#include "../GameObject.hpp"
#include "Enemy.hpp"
#include <list>

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
	int minimumAmountOfCars;

	std::list<int> enemyPositionList;
	bool IsValidPosition(int enemyPosition);
};