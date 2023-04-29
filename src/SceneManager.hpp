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
	void GameOver() { gameOver = true; }
	
	int scoreCount;
	Player* player;
private:
	bool gameOver;
	sf::RenderWindow* window;

	sf::Font mainFont;
	sf::Text* scoreText;
	sf::Text* gameOverText;

	sf::Sprite scoreBoardSprite;
	sf::Texture scoreBoardTexture;

	std::list<GameObject*> UnInitializedGameObjects;
	std::list<GameObject*> ActiveGameObjects;
	std::list<GameObject*> GameObjectsToBeRemoved;
};