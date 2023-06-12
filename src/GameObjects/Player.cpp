#include "Player.hpp"
#include "../GameData.hpp"
#include "../SceneManager.hpp"

void Player::Start()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT - 100;
	spriteRect.top = 16;

	power = 50000;
	mass = 50;
	timePerScorePoint = 500;
}

void Player::Update()
{
	UpdatePhysics();

	if (scoreClock.getElapsedTime().asMilliseconds() > timePerScorePoint)
	{
		scoreClock.restart();
		sceneManager->scoreCount++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		SetForce(Vector2::Left() * power);

		spriteRect.left = 48;
		sprite.setTextureRect(spriteRect);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
			 sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		SetForce(Vector2::Right() * power);

		spriteRect.left = 32;
		sprite.setTextureRect(spriteRect);
	}
	else
	{
		SetForce(Vector2::Zero());

		spriteRect.left = 16;
		sprite.setTextureRect(spriteRect);
	}

	position.y = SCREEN_HEIGHT - 100 + sin(animationClock.getElapsedTime().asMilliseconds() * .3f) * 1.5f;

	if (position.x > SCREEN_WIDTH - 120)
	{
		position.x = SCREEN_WIDTH - 120;
	}
	else if (position.x < 70)
	{
		position.x = 70;
	}
}
