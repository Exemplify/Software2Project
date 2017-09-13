#ifndef GAME_MAN_H
#define GAME_MAN_H

#include <SFML/Graphics.hpp>
#include <string>

#include "DisplayManager.h"
#include "EventManager.h"

using namespace sf;
using std::string;

// Struct that contains the default settings for the window
struct WindowSettings
{
    unsigned int screenWidth = 1920;
	unsigned int screenHeight = 1080;
	string Style = "Default";
	string game_name = "Gyrus";
};

class GameManager
{
	
public:
	GameManager();
	void GameLoop();
private:
    // Variables
	WindowSettings _defaultSetup;
	
	RenderWindow _gameWindow;
	DisplayManager _dispManager;
	EventManager _eventManager;
	
    
    // Methods
    void initialiseWindow();
};




#endif
