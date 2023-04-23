#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow* window)
{
	this->window = window;

	mainFont.loadFromFile("assets/Roboto-Black.ttf");
	scoreText = new sf::Text;
	scoreText->setFont(mainFont);
	scoreText->setString("0");
	scoreText->setCharacterSize(48);
	scoreText->setFillColor(sf::Color::White);
	scoreText->setStyle(sf::Text::Bold);
	scoreText->setPosition(sf::Vector2f(10, 0));


	UnInitializedGameObjects.push_front(new Player("Player", "assets/player.png", window));
}

void SceneManager::OnUpdate()
{
	if (UnInitializedGameObjects.size() > 0)
	{
		for (GameObject* gameObject : UnInitializedGameObjects)
		{
			gameObject->Start();
			ActiveGameObjects.push_front(gameObject);
		}
	}

	UnInitializedGameObjects.clear();

	for (GameObject* gameObject : ActiveGameObjects)
	{
		gameObject->Update();
	}
}

void SceneManager::OnRender()
{
	for (GameObject* gameObject : ActiveGameObjects)
	{
		gameObject->Render();
	}

	window->draw(*scoreText);
}

GameObject* SceneManager::GetGameObjectByName(std::string name)
{
	for (GameObject* gameObject : ActiveGameObjects)
	{
		if (gameObject->GetName() == name)
		{
			return gameObject;
		}
	}

	return nullptr;
}
