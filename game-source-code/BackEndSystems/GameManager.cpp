#include "GameManager.h"

GameManager::GameManager():
_gameWindow(),
_dispManager(&_gameWindow)
{
	// Creates the initial sfml window 
	_gameWindow.create(
		VideoMode(_defaultSetup.screenWidth,_defaultSetup.screenHeight),
		_defaultSetup.game_name);
	// Sets the game window to be inactive so that the display can be 
	// can be done in a seperate thread
    _gameWindow.setActive(false);
}
void GameManager::BeginGameLoop()
{
	// initialise physics and display threads 
	
	while (_gameWindow.isOpen())
	{
		// Event Handler Runs here
	}
}

