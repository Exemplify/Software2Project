#include "GameManager.h"

void GameManager::GameLoop()
{
	// Function Scope Declarations
	RenderWindow window(sf::VideoMode(800, 600), "My window");
	// Set-up window to current specifications
	initialiseWindow(window);

	_dispManager.InitialiseThread(window);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
		_eventManager.EventLoop(window);
	
    }
	// initialise physics and display threads 
//	_dispManager.InitialiseThread();
//	
//	while (_gameWindow.isOpen())
//	{
//		_eventManager.EventLoop();
//		if(activeScene != NULL)
//			activeScene->SceneUpdate();
//	}
}

std::shared_ptr<Scene> GameManager::activeScene = NULL;

void GameManager::initialiseWindow(RenderWindow&_gameWindow) 
{
	// Creates the initial sfml window  with settings defined in default Setup
	_gameWindow.create(
	VideoMode(_defaultSetup.screenWidth,_defaultSetup.screenHeight),
	_defaultSetup.game_name,
	_defaultSetup.winStyle);
	// Sets the game window to be inactive so that the display
	// can be done in a seperate thread
    _gameWindow.setActive(false);
}