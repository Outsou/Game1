#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerPaddle.h"
#include "GameBall.h"
#include "GameObjectManager.h"
#include "InputManager.h"


class Game
{

public:
	static void Start();

	const static InputManager& GetInput();
	const static GameObjectManager& GetGameObjectManager();

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;

	static sf::RenderWindow _mainWindow;
	static sf::Clock _clock;

	static GameObjectManager _gameObjectManager;
	static InputManager _inputManager;
};
