#include "Player.hpp"
#include "../GameData.hpp"

void Player::Start()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT - 100;

	speed = 10;

	LogInfo("Player Started");
}

void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += speed;
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
