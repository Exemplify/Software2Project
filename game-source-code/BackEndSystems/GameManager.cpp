#include "GameManager.h"
#include "GameTime.h"
#include "CollisionDetection.h"
#include <mutex>



std::shared_ptr<Scene> GameManager::activeScene = NULL;
bool GameManager::closeWindow = false;

void GameManager::GameLoop()
{
	//active_scene
	activeScene = _game_scenes[_scene_index];
	// Set-up window to current specifications
	initialiseWindow(_window);

	// initialises the display thread
	DisplayManager _displayThread(_window);
	_displayThread.InitialiseThread();
    CollisionDetection collisionDetection(&_window);
	collisionDetection.InitializeCollisionThread();
	
	//Creates the event manager
	EventManager eventManager;

    // The main game loop
    while (_window.isOpen())
    {
		// Determines the Time Between each frame
		_gameTime->TimeFrame();
        // check all the window's events that were triggered since the last iteration of the loop
		eventManager.EventLoop(_window);
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
	_defaultSetup.gameName,
	_defaultSetup.winStyle);
	// Sets the game window to be inactive so that the display
	// can be done in a seperate thread
    gameWindow.setActive(false);
}

void GameManager::Exit()
{
	closeWindow = true;
}
// loads a specific scene based off of the current index 
void GameManager::LoadScene(unsigned int index)
{
	if(_game_scenes.size() <= index)
		throw SceneDoesntExist();
	else
	{
		auto originalScenes = _repository->getGameScenes();
		_game_scenes.at(_scene_index) = originalScenes.at(_scene_index);
		activeScene = _game_scenes.at(index);
		_scene_index = index;
	}
}


GameManager::GameManager(std::shared_ptr<RepositioryInterface> repository):
_repository{repository},
_defaultSetup{repository->getGameScreenSize().at(0),repository->getGameScreenSize().at(1), repository->getGameName()},
_game_scenes{repository->getGameScenes()} 
{}
int GameManager::_scene_index = 0;