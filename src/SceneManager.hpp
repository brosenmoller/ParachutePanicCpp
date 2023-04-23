#pragma once

#include <list>
#include "GameObject.hpp"
#include "GameObjects/Player.hpp"

class SceneManager
{
public:

	SceneManager(sf::RenderWindow* window);
	~SceneManager() {}

	void OnUpdate();
	void OnRender();

	GameObject* GetGameObjectByName(std::string name);

private:
	sf::RenderWindow* window;

	std::list<GameObject*> UnInitializedGameObjects;
	std::list<GameObject*> ActiveGameObjects;
	sf::Text* scoreText;
	sf::Font mainFont;
};