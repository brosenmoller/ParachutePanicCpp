#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

GameManager* gameManager = nullptr;

int main(int argc, char* argv[])
{
	gameManager = new GameManager();

	while (gameManager->getIsRunning())
	{
		gameManager->handleEvents();
		gameManager->update();
		gameManager->render();
	}

	gameManager->clean();

	return 0;
}