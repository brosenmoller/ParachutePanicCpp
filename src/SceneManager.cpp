#include "SceneManager.hpp"
#include "GameObjects/EnemySpawner.hpp"

SceneManager::SceneManager(sf::RenderWindow* window)
{
	// --- Initializing Variables ---
	this->window = window;

	scoreCount = 0;
	gameOver = false;

	// --- Setting up Text ---
	mainFont.loadFromFile("assets/ARCADECLASSIC.ttf");

	scoreText = new sf::Text;
	scoreText->setFont(mainFont);
	scoreText->setCharacterSize(50);
	scoreText->setFillColor(sf::Color::White);
	scoreText->setPosition(sf::Vector2f(25, 2));

	gameOverText = new sf::Text;
	gameOverText->setFont(mainFont);
	gameOverText->setString("Game Over");
	gameOverText->setCharacterSize(120);
	gameOverText->setFillColor(sf::Color::Red);
	gameOverText->setPosition(sf::Vector2f(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 10));

	scoreBoardTexture.loadFromFile("assets/ScoreBoard.png");
	scoreBoardSprite.setTexture(scoreBoardTexture);
	scoreBoardSprite.setScale(sf::Vector2f(10, 10));

	// --- Sounds and Music ---
	highwayAmbience.openFromFile("assets/Audio/Highway.wav");
	highwayAmbience.play();

	engineStartBuffer.loadFromFile("assets/Audio/MixKit-EngineStart.wav");
	engineStartSound.setBuffer(engineStartBuffer);
	engineStartSound.play();

	crashBuffer.loadFromFile("assets/Audio/CarCrash.wav");
	crashSound.setBuffer(crashBuffer);

	// --- Setting up Gameobject ---
	player = new Player("Player", "assets/Cars.png", window, this);
	UnInitializedGameObjects.push_front(player);

	UnInitializedGameObjects.push_front(new EnemySpawner("EnemySpawner", "assets/Cars.png", window, this, Vector2(-100, -100)));
}

void SceneManager::OnUpdate()
{
	if (gameOver) 
	{
		return; 
	}


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

	window->draw(scoreBoardSprite);

	scoreText->setString(std::to_string(scoreCount));
	window->draw(*scoreText);

	if (gameOver)
	{
		window->draw(*gameOverText);
	}
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

void SceneManager::GameOver()
{
	gameOver = true;
	crashSound.play();
}
