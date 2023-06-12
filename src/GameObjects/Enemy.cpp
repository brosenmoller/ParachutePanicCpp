#include "Enemy.hpp"
#include "../SceneManager.hpp"
#include "../LogManager.hpp"

void Enemy::Start()
{
	speed = 400 + (rand() % 100);
	mass = 50;
	collisionRange = 45;
}

void Enemy::Update()
{
	UpdatePhysics();

	velocity = Vector2::Down() * speed;
	//velocity = Vector2(velocity.x, speed);
	//SetForce(Vector2(-40000 + (rand() % 80000), 0));

	float distanceToPlayer = position.Distance(sceneManager->player->GetPosition());
	if (distanceToPlayer < collisionRange)
	{
		sceneManager->GameOver();
	}

	if (position.y > SCREEN_HEIGHT)
	{
		sceneManager->DestroyGameObject(this);
	}
}
