#include "Enemy.hpp"
#include "../SceneManager.hpp"

void Enemy::Start()
{
	speed = 7 + (rand() % 2);
	collisionRange = 45;
}

void Enemy::Update()
{
	position.y += speed;

	float distanceToPlayer = position.Distance(*sceneManager->player->GetPosition());
	if (distanceToPlayer < collisionRange)
	{
		sceneManager->GameOver();
	}

	if (position.y > SCREEN_HEIGHT)
	{
		sceneManager->DestroyGameObject(this);
	}
}
