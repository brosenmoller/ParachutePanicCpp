#include "SceneManager.hpp"
#include "GameObjects/EnemySpawner.hpp"

SceneManager::SceneManager(sf::RenderWindow* window)
{
	this->window = window;

	mainFont.loadFromFile("assets/Roboto-Black.ttf");

	scoreCount = 0;
	playerLiveCount = 3;

	scoreText = new sf::Text;
	scoreText->setFont(mainFont);
	scoreText->setCharacterSize(48);
	scoreText->setFillColor(sf::Color::White);
	scoreText->setStyle(sf::Text::Bold);
	scoreText->setPosition(sf::Vector2f(10, 0));

	liveText = new sf::Text;
	liveText->setFont(mainFont);
	liveText->setString("0");
	liveText->setCharacterSize(48);
	liveText->setFillColor(sf::Color::Red);
	liveText->setStyle(sf::Text::Bold);
	liveText->setPosition(sf::Vector2f(SCREEN_WIDTH - 50, 0));

	player = new Player("Player", "assets/Cars.png", window, this);
	UnInitializedGameObjects.push_front(player);

	UnInitializedGameObjects.push_front(new EnemySpawner("EnemySpawner", "assets/SlimeEnemy.png", window, this, Vector2(-100, -100)));
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

	for (GameObject* gameObject : GameObjectsToBeRemoved)
	{
		ActiveGameObjects.remove(gameObject);
		delete gameObject;
	}

	GameObjectsToBeRemoved.clear();


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

	scoreText->setString(std::to_string(scoreCount));
	window->draw(*scoreText);
	liveText->setString(std::to_string(playerLiveCount));
	window->draw(*liveText);
}

void SceneManager::InstantiateGameObject(GameObject* gameObject)
{
	UnInitializedGameObjects.push_front(gameObject);
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

void SceneManager::DestroyGameObjectByName(std::string name)
{
	for (GameObject* gameObject : ActiveGameObjects)
	{
		if (gameObject->GetName() == name)
		{
			DestroyGameObject(gameObject);
		}
	}
}

void SceneManager::DestroyGameObject(GameObject* gameObject)
{
	GameObjectsToBeRemoved.push_front(gameObject);
}