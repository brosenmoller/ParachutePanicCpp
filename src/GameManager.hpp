#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "LogManager.hpp"
#include "GameData.hpp"
#include "SceneManager.hpp"

class GameManager
{
public:
	GameManager();
	~GameManager() {}

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	void GameOver(int score);

	bool getIsRunning() { return isRunning; }

private:
	bool isRunning;
	bool gameOver;

	SceneManager* sceneManager;
	sf::RenderWindow* window;

	sf::Font mainFont;
	sf::Text* finalScoreText;
	sf::Text* highScoreText;
	sf::Text* continueText;
	sf::Clock continueTextFlickerClock;
	bool drawContinueText;
	int continueTextFlickerEnabledDelay;
	int continueTextFlickerDisabledDelay;

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	sf::IntRect backgroundTextureRect;
	int backgroundScrollSpeed;

	int score;
	int highScore;

	std::string saveFilePath;
};
