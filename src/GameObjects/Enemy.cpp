#include "Enemy.hpp"
#include "../SceneManager.hpp"
#include "../LogManager.hpp"

bool movingRight;
sf::Clock turningClock;
float delay;

void Enemy::Start()
{
	speed = 400 + (std::rand() % 100);
	mass = 50;
	collisionRange = 45;

	movingRight = std::rand() % 2;
	delay = std::rand() % 2000;
}

void Enemy::Update()
{
	UpdatePhysics();

	//velocity = Vector2::Down() * speed;

	if (turningClock.getElapsedTime().asMilliseconds() > delay)
	{
		delay = std::rand() % 2000;
		movingRight = std::rand() % 2;
		turningClock.restart();
	}

	velocity = Vector2(velocity.x, speed);
	if (movingRight)
	{
		SetForce(Vector2(30000, 0));
	}
	else
	{
		SetForce(Vector2(-30000, 0));
	}
	

	float distanceToPlayer = position.Distance(sceneManager->player->GetPosition());
	if (distanceToPlayer < collisionRange)
	{
		sceneManager->GameOver();
	}

	if (position.y > SCREEN_HEIGHT)
	{
		sceneManager->DestroyGameObject(this);
	}

	if (position.x > SCREEN_WIDTH - 120)
	{
		position.x = SCREEN_WIDTH - 120;
	}
	else if (position.x < 70)
	{
		position.x = 70;
	}
}
