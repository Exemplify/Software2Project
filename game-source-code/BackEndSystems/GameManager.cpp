#include "GameManager.h"
#include "GameTime.h"
#include "../FrontEndSystems/CollisionDetection.h"

std::shared_ptr<Scene> GameManager::activeScene = NULL;
std::vector<std::shared_ptr<Scene>> GameManager::_game_scenes{};

bool GameManager::closeWindow = false;

class SceneDoesntExist{};

void GameManager::GameLoop()
{
	// Initial Declarations	
	RenderWindow window;
	// Set-up window to current specifications
	initialiseWindow(window);

	// initialises the display thread
	_dispManager.InitialiseThread(window);
    CollisionDetection collisionDetection(&window);

    // The main game loop
    while (window.isOpen())
    {
		// Determines the Time Between each frame
		_gameTime->TimeFrame();
        // check all the window's events that were triggered since the last iteration of the loop
		_eventManager.EventLoop(window);
		// Calls the SceneUpdate function to run the game functionality
		if(activeScene != NULL)
			activeScene->SceneUpdate();
		// Checks if Input causes window to be closed
		if(closeWindow)
			window.close();
	}
}

void GameManager::initialiseWindow(RenderWindow& gameWindow) 
{
	// Creates the initial sfml window  with settings defined in default Setup
	gameWindow.create(
	VideoMode(_defaultSetup.screenWidth,_defaultSetup.screenHeight),
	_defaultSetup.game_name,
	_defaultSetup.winStyle);
	// Sets the game window to be inactive so that the display
	// can be done in a seperate thread
    gameWindow.setActive(false);
}

void GameManager::AddScene(std::shared_ptr<Scene> newScene)
{
	if (_game_scenes.size() == 0)
		activeScene = newScene;
	_game_scenes.push_back(newScene);
}

void GameManager::Exit()
{
	closeWindow = true;
}

void GameManager::LoadScene(unsigned int index)
{
	if(_game_scenes.size() <= index)
		throw SceneDoesntExist();
	else
	{
		activeScene = _game_scenes.at(index);
	}
}



