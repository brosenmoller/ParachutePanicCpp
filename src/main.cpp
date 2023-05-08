#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

GameManager* gameManager = nullptr;

int main(int argc, char* argv[])
{
	gameManager = new GameManager();

	while (gameManager->getIsRunning())
	{
		gameManager->HandleEvents();
		gameManager->Update();
		gameManager->Render();
	}

	gameManager->Clean();

	return 0;
}