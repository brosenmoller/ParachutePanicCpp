#include "GameManager.hpp"

SceneManager* sceneManager;

GameManager::GameManager()
{
	frameCounter = 0;
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME);
	window->setFramerateLimit(FRAME_RATE);

	sceneManager = new SceneManager(window);

	isRunning = true;
}

void GameManager::handleEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			isRunning = false;
		}
	}
}

void GameManager::update()
{
	sceneManager->OnUpdate();
}

void GameManager::render()
{
	window->clear(sf::Color(50, 50, 50, 255));
	
	sceneManager->OnRender();
	
	window->display();
}

void GameManager::clean()
{
	window->close();

	LogInfo("Game Terminated");
}

