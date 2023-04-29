#include "GameManager.hpp"

SceneManager* sceneManager;

GameManager::GameManager()
{
	frameCounter = 0;
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME);
	window->setFramerateLimit(FRAME_RATE);
	
	sf::Image windowIcon;
	windowIcon.loadFromFile("assets/CarsIcon.png");

	window->setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

	sceneManager = new SceneManager(window);

	isRunning = true;

	backgroundTexture.loadFromFile("assets/Background.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(sf::Vector2f(10, 10));
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
	window->clear();

	window->draw(backgroundSprite);
	
	sceneManager->OnRender();
	
	window->display();
}

void GameManager::clean()
{
	window->close();

	LogInfo("Game Terminated");
}

