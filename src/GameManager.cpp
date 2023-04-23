#include "GameManager.hpp"

SceneManager* sceneManager;

GameManager::GameManager()
{
	frameCounter = 0;
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Parachute Panic");
	window->setFramerateLimit(FRAME_RATE);

	sceneManager = new SceneManager(window);

	isRunning = true;
}

GameManager::~GameManager()
{}

void GameManager::handleEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			isRunning = false;
	}
}

void GameManager::update()
{
	//frameCounter++;
	//LogInfo(std::to_string(frameCounter).c_str());

	sceneManager->OnUpdate();
}

void GameManager::render()
{
	window->clear();
	
	sceneManager->OnRender();
	
	window->display();
}

void GameManager::clean()
{
	window->close();

	LogInfo("Game Terminated");
}

