#pragma once

#include <vector>
#include <list>
#include <SFML/Audio.hpp>
#include "GameData.hpp"
#include "GameObject.hpp"
#include "GameObjects/Player.hpp"
#include "GameObjects/Enemy.hpp"

class GameManager;

class SceneManager
{
public:
	SceneManager(sf::RenderWindow* window, GameManager* gameManager, sf::Font* mainFont);
	~SceneManager();

	void OnUpdate();
	void OnRender();
	void Clean();
	
	void InstantiateGameObject(GameObject* gameObject);
	GameObject* GetGameObjectByName(std::string name);
	void DestroyGameObjectByName(std::string name);
	void DestroyGameObject(GameObject* gameObject);
	void GameOver();
	
	int scoreCount;
	Player* player;
private:
	bool gameOver;
	sf::RenderWindow* window;

	GameManager* gameManager;

	sf::Font* mainFont;
	sf::Text* scoreText;
	sf::Text* gameOverText;

	sf::Sprite scoreBoardSprite;
	sf::Texture scoreBoardTexture;

	std::list<GameObject*> ActiveGameObjects;
	std::vector<GameObject*> UnInitializedGameObjects;
	std::vector<GameObject*> GameObjectsToBeRemoved;

	sf::Music highwayAmbience;
	sf::SoundBuffer engineStartBuffer;
	sf::Sound engineStartSound;
	sf::SoundBuffer crashBuffer;
	sf::Sound crashSound;
};