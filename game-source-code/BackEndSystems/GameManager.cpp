#include "GameManager.h"
#include "GameTime.h"
#include "../FrontEndSystems/CollisionDetection.h"
#include <mutex>

std::shared_ptr<Scene> GameManager::activeScene = NULL;
std::vector<std::shared_ptr<Scene>> GameManager::_game_scenes{};
std::shared_ptr<Scene> GameManager::original_activeScene = NULL;

bool GameManager::closeWindow = false;
int GameManager::_scene_index = 0;
class SceneDoesntExist{};

void GameManager::GameLoop()
{
	// Set-up window to current specifications
	initialiseWindow(_window);

	// initialises the display thread
	DisplayManager _displayThread(_window);
	_displayThread.InitialiseThread();
    CollisionDetection collisionDetection(&_window);

    // The main game loop
    while (_window.isOpen())
    {
		// Determines the Time Between each frame
		_gameTime->TimeFrame();
        // check all the window's events that were triggered since the last iteration of the loop
		_eventManager.EventLoop(_window);
		// Calls the SceneUpdate function to run the game functionality
		if(activeScene != NULL)
			activeScene->SceneUpdate();
		// Checks if Input causes window to be closed
		if(closeWindow)
			_window.close();
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

// used to add a scene to the gameManager scene list
void GameManager::AddScene(std::shared_ptr<Scene> newScene)
{
	// checks if any scenes currently exist
	if (_game_scenes.size() == 0)
	{
		// assigns active scene to the first scene created 
		activeScene = newScene;
		// attempts to duplicate the current scene
		///still needs to be fixed so that the game scene and menu scenes can be reloaded
		original_activeScene = std::make_shared<Scene>(*newScene);
	}
	// adds the scene to the list of scenes in the game
	_game_scenes.push_back(newScene);
}
/// Exit function needs to be moved into Scene or a seperate Application class
void GameManager::Exit()
{
	closeWindow = true;
}
// loads a specific scene based off of the current index 
/// Should be called from an application class but remains inside of gameManager
void GameManager::LoadScene(unsigned int index)
{
	if(_game_scenes.size() <= index)
		throw SceneDoesntExist();
	else
	{
		*_game_scenes.at(_scene_index) = *original_activeScene;
		original_activeScene = std::make_shared<Scene>(*_game_scenes.at(index));
		activeScene = _game_scenes.at(index);
		_scene_index = index;
	}
}



