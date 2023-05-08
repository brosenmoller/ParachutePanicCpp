#include "GameManager.hpp"
#include <fstream>

GameManager::GameManager()
{
	// --- Initialise Variables ---
	gameOver = false;
	score = 0;

	// --- Setting up SaveSystem ---
	saveFilePath = "highScore.save"; 
	std::ifstream highScoreFileInput; 
	highScoreFileInput.open(saveFilePath);
	if (!highScoreFileInput)
	{
		std::ofstream highScoreFileOutput;
		highScoreFileOutput.open(saveFilePath);
		highScoreFileOutput << "0";
		highScoreFileOutput.close();

		highScoreFileInput.close();
		highScoreFileInput.open(saveFilePath);
	}

	std::string highScoreString;
	while(std::getline(highScoreFileInput, highScoreString))

	highScoreFileInput.close();

	highScore = std::stoi(highScoreString);


	// --- Create Window ---
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME);
	window->setFramerateLimit(FRAME_RATE);
	isRunning = true;
	
	// --- Set Window Icon ---
	sf::Image windowIcon;
	windowIcon.loadFromFile("assets/CarsIcon.png");
	window->setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());
	
	// --- Setup SceneManager ---
	sceneManager = new SceneManager(window, this, &mainFont);

	// --- Settings up text
	mainFont.loadFromFile("assets/ARCADECLASSIC.ttf");

	finalScoreText = new sf::Text("Score\t0000", mainFont, 50);
	finalScoreText->setFillColor(sf::Color::Black);
	finalScoreText->setPosition(sf::Vector2f(320, 250));

	highScoreText = new sf::Text("Highscore\t0000", mainFont, 50);
	highScoreText->setFillColor(sf::Color::Black);
	highScoreText->setPosition(sf::Vector2f(205, 200));

	continueText = new sf::Text("Press\tSpace\tto\tContinue", mainFont, 50);
	continueText->setFillColor(sf::Color::Black);
	continueText->setPosition(sf::Vector2f(100, 300));
	continueTextFlickerEnabledDelay = 500;
	continueTextFlickerDisabledDelay = 100;
	drawContinueText = true;

	// --- Background ---
	backgroundTexture.loadFromFile("assets/Background.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(sf::Vector2f(10, 10));
	backgroundTextureRect = sf::IntRect(0, 0, 80, 180);
	backgroundSprite.setPosition(0, -SCREEN_HEIGHT * 2);
	backgroundSprite.setTextureRect(backgroundTextureRect);
	backgroundScrollSpeed = 6;
}

void GameManager::HandleEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			isRunning = false;
		}
	}
}

void GameManager::Update()
{
	if (gameOver) 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			delete sceneManager;
			sceneManager = new SceneManager(window, this, &mainFont);

			gameOver = false;
		}
	}
	else
	{
		backgroundSprite.setPosition(0, backgroundSprite.getPosition().y + backgroundScrollSpeed);
		if (backgroundSprite.getPosition().y > 0) { backgroundSprite.setPosition(0, -SCREEN_HEIGHT * 2); }

		sceneManager->OnUpdate();
	}
}

void GameManager::Render()
{
	window->clear();

	window->draw(backgroundSprite);
	
	sceneManager->OnRender();

	if (gameOver)
	{
		window->draw(*finalScoreText);
		window->draw(*highScoreText);

		if (drawContinueText)
		{
			window->draw(*continueText);

			if (continueTextFlickerClock.getElapsedTime().asMilliseconds() > continueTextFlickerEnabledDelay)
			{
				continueTextFlickerClock.restart();
				drawContinueText = false;
			}
		}
		else
		{
			if (continueTextFlickerClock.getElapsedTime().asMilliseconds() > continueTextFlickerDisabledDelay)
			{
				continueTextFlickerClock.restart();
				drawContinueText = true;
			}
		}
	}
	
	window->display();
}

void GameManager::Clean()
{
	window->close();

	LogInfo("Game Terminated");
}

void GameManager::GameOver(int score)
{
	this->score = score;
	gameOver = true;
	drawContinueText = true;
	continueTextFlickerClock.restart();

	std::string scoreString = std::to_string(score);
	while (scoreString.length() < 5)
	{
		scoreString = "0" + scoreString;
	}

	finalScoreText->setString("Score\t" + scoreString);

	if (score > highScore)
	{
		highScore = score;


		std::ofstream highScoreFileInput; 
		highScoreFileInput.open(saveFilePath);
		highScoreFileInput << std::to_string(highScore);

		highScoreFileInput.close();
	}

	std::string highScoreString = std::to_string(highScore);
	while (highScoreString.length() < 5)
	{
		highScoreString = "0" + highScoreString;
	}

	highScoreText->setString("HighScore\t" + highScoreString);
}

