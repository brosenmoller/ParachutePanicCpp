#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "LogManager.hpp"
#include "GameData.hpp"
#include "SceneManager.hpp"

class GameManager
{
public:
	GameManager();
	~GameManager() {}

	void handleEvents();
	void update();
	void render();
	void clean();

	bool getIsRunning() { return isRunning; }

private:
	int frameCounter;
	bool isRunning;
	sf::RenderWindow* window;
};
