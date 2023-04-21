#pragma once

#include <unordered_set>
#include "GameObject.hpp"

class SceneManager
{
public:

	SceneManager(sf::RenderWindow* window);
	~SceneManager();

	void OnUpdate();
	void OnRender();

	GameObject* GetGameObjectByName(std::string name);

private:
	sf::RenderWindow* window;

	std::unordered_set<GameObject> UnInitializedGameObjects;
	std::unordered_set<GameObject> ActiveGameObjects;
};