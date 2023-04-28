#include "EnemySpawner.hpp"
#include "../SceneManager.hpp"
#include "Enemy.hpp"

void EnemySpawner::Start()
{
	spawnDelay = 2500;
	decreaseAmount = 200;
	clock.restart();
}

void EnemySpawner::Update()
{
	if (clock.getElapsedTime().asMilliseconds() > spawnDelay)
	{
		clock.restart();
		decreaseAmount -= 10;
		if (decreaseAmount < 20) decreaseAmount = 20;
		spawnDelay -= 50;
		if (spawnDelay < 600) spawnDelay = 600;


		int amount = rand() % 6;

		for (int i = 0; i < amount; i++)
		{
			int enemyPosition = rand() % SCREEN_WIDTH - 50;
			sceneManager->InstantiateGameObject(new Enemy(
				"Enemy " + std::to_string(i),
				"assets/Cars.png",
				window,
				sceneManager,
				Vector2(enemyPosition, 0))
			);
		}
	}
}
