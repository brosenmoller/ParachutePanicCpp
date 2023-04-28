#include "Player.hpp"
#include "../GameData.hpp"
#include "../SceneManager.hpp"

void Player::Start()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT - 100;

	speed = 10;
	timePerScorePoint = 200;

	LogInfo("Player Started");
}

void Player::Update()
{
	if (clock.getElapsedTime().asMilliseconds() > timePerScorePoint)
	{
		clock.restart();
		sceneManager->scoreCount++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= speed;
		spriteRect.top = 16;
		spriteRect.left = 48;
		sprite.setTextureRect(spriteRect);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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

	if (position.x > SCREEN_WIDTH - 60)
	{
		position.x = SCREEN_WIDTH - 60;
	}
	else if (position.x < 0)
	{
		position.x = 0;
	}
}
