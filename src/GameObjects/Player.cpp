#include "Player.hpp"
#include "../GameData.hpp"
#include "../SceneManager.hpp"

void Player::Start()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT - 100;

	speed = 8;
	timePerScorePoint = 500;

	LogInfo("Player Started");
}

void Player::Update()
{
	if (scoreClock.getElapsedTime().asMilliseconds() > timePerScorePoint)
	{
		scoreClock.restart();
		sceneManager->scoreCount++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		position.x -= speed;
		spriteRect.top = 16;
		spriteRect.left = 48;
		sprite.setTextureRect(spriteRect);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
			 sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		position.x += speed;
		spriteRect.top = 16;
		spriteRect.left = 32;
		sprite.setTextureRect(spriteRect);
	}
	else
	{
		spriteRect.top = 16;
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
