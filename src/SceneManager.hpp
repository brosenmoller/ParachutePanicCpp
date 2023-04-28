#pragma once

#include <list>
#include "GameData.hpp"
#include "GameObject.hpp"
#include "GameObjects/Player.hpp"
#include "GameObjects/Enemy.hpp"

class SceneManager
{
public:
	SceneManager(sf::RenderWindow* window);
	~SceneManager() {}

	void OnUpdate();
	void OnRender();
	
	void InstantiateGameObject(GameObject* gameObject);
	GameObject* GetGameObjectByName(std::string name);
	void DestroyGameObjectByName(std::string name);
	void DestroyGameObject(GameObject* gameObject);
	
	int scoreCount;
	int playerLiveCount;
	Player* player;
private:
	sf::RenderWindow* window;

	sf::Font mainFont;
	sf::Text* scoreText;
	sf::Text* liveText;

	std::list<GameObject*> UnInitializedGameObjects;
	std::list<GameObject*> ActiveGameObjects;
	std::list<GameObject*> GameObjectsToBeRemoved;
};