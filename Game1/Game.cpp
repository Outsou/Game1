#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "ServiceLocator.h"
#include "InputProviderSFML.h"
#include "AudioProviderSFML.h"

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Game1");

	//Create services
	InputProviderSFML inputProvider;
	ServiceLocator::RegisterServiceLocator(&inputProvider);

	AudioProviderSFML audioProvider;
	ServiceLocator::RegisterServiceLocator(&audioProvider);

	audioProvider.PlaySong("Assets/Audio/Soundtrack.ogg", true);

	//Create player
	PlayerPaddle *player1 = new PlayerPaddle();
	player1->SetPosition((SCREEN_WIDTH / 2), 700);
	_gameObjectManager.Add("Paddle1", player1);

	//Create wall
	Wall *wall = new Wall();
	wall->SetPosition(SCREEN_WIDTH / 2 - 300, 725);
	wall->Rotate(30);
	_gameObjectManager.Add("Wall1", wall);

	//Create ball
	/*
	GameBall *ball = new GameBall();
	ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);
	_gameObjectManager.Add("Ball", ball);
	*/

	_gameState = Game::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

const GameObjectManager& Game::GetGameObjectManager()
{
	return _gameObjectManager;
}

void Game::GameLoop()
{
	sf::Time elapsed = _clock.restart();

	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	switch (_gameState)
	{
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		case Game::Playing:
		{

			_mainWindow.clear(sf::Color::Black);

			_gameObjectManager.UpdateAll(elapsed);
			_gameObjectManager.DrawAll(_mainWindow);

			_mainWindow.display();

			if (currentEvent.type == sf::Event::Closed)
				_gameState = Game::Exiting;

			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape)
					ShowMenu();
			}

			break;
		}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	}
}

Game::GameState Game::_gameState = Uninitialized;

sf::RenderWindow Game::_mainWindow;
sf::Clock Game::_clock;

GameObjectManager Game::_gameObjectManager;