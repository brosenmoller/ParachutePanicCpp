#include "EnemySpawner.hpp"
#include "../SceneManager.hpp"
#include "Enemy.hpp"

void EnemySpawner::Start()
{
	spawnDelay = 2000;
	decreaseAmount = 200;
	minimumAmountOfCars = 2;
	clock.restart();
}

void EnemySpawner::Update()
{
	if (clock.getElapsedTime().asMilliseconds() > spawnDelay)
	{
		clock.restart();
		
		decreaseAmount -= 20;
		if (decreaseAmount < 20) { decreaseAmount = 20; }

		spawnDelay -= decreaseAmount;
		if (spawnDelay < 600) { spawnDelay = 600; }

		int amount = rand() % 5;
		amount += minimumAmountOfCars;

		for (int i = 0; i < amount; i++)
		{
			int enemyXPosition = rand() % (SCREEN_WIDTH - 200);
			enemyXPosition += 70;
			while (!IsValidPosition(enemyXPosition))
			{
				enemyXPosition = rand() % (SCREEN_WIDTH - 200);
				enemyXPosition += 70;
			}

			enemyPositionList.push_back(enemyXPosition);

			sceneManager->InstantiateGameObject(new Enemy(
				"Enemy " + std::to_string(i),
				"assets/Cars.png",
				window,
				sceneManager,
				Vector2(enemyXPosition, -50 - (rand() % 30)))
			);
		}

		enemyPositionList.clear();
	}
}

bool EnemySpawner::IsValidPosition(int enemyPosition)
{
	for (int position : enemyPositionList)
	{
		if (enemyPosition > position - 50 && enemyPosition < position + 50)
		{
			return false;
		}
	}

	return true;
}
