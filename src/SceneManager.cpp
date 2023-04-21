#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow* window)
{
	this->window = window;
	UnInitializedGameObjects.insert(GameObject("Player", "assets/player.png", window));
}

SceneManager::~SceneManager()
{}

void SceneManager::OnUpdate()
{
	if (UnInitializedGameObjects.size() > 0)
	{
		for (GameObject gameObject : UnInitializedGameObjects)
		{
			gameObject.Start();
			ActiveGameObjects.insert(gameObject);
		}
	}

	UnInitializedGameObjects.clear();

	for (GameObject gameObject : ActiveGameObjects)
	{
		gameObject.Update();
	}
}

void SceneManager::OnRender()
{
	for (GameObject gameObject : ActiveGameObjects)
	{
		gameObject.Render();
	}
}

GameObject* SceneManager::GetGameObjectByName(std::string name)
{
	for (GameObject gameObject : ActiveGameObjects)
	{
		if (gameObject.GetName() == name)
		{
			return &gameObject;
		}
	}

	return nullptr;
}
