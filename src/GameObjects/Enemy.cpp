#include "Enemy.hpp"
#include "../SceneManager.hpp"

void Enemy::Start()
{
	speed = 4;
	collisionRange = 48;
}

void Enemy::Update()
{
	position.y += speed;

	float distanceToPlayer = position.Distance(*sceneManager->player->GetPosition());
	if (distanceToPlayer < collisionRange)
	{
		sceneManager->GameOver();
		sceneManager->DestroyGameObject(this);
	}
}
