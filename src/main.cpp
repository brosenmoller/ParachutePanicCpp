#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

int main()
{
	srand(time(NULL));

	GameManager* gameManager = new GameManager();

	while (gameManager->GetIsRunning())
	{
		gameManager->HandleEvents();
		gameManager->Update();
		gameManager->Render();
	}

	gameManager->Clean();

	return 0;
}