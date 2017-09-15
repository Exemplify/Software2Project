#ifndef GAME_MAN_H
#define GAME_MAN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>

#include "DisplayManager.h"
#include "EventManager.h"
#include "../FrontEndSystems/Scene.h"

using namespace sf;
using std::string;
using scene_ptr = std::shared_ptr<Scene>;

// Struct that contains the default settings for the window
struct WindowSettings
{
    unsigned int screenWidth = 1920;
	unsigned int screenHeight = 1080;
	Uint32 winStyle = Style::Default;
	string game_name = "Gyrus";
};

class GameManager
{
public:
	GameManager();
	void GameLoop();
	static scene_ptr activeScene;
private:
    // Variables
	WindowSettings _defaultSetup;
	// Backend Objects 
	RenderWindow _gameWindow;
	DisplayManager _dispManager;
	EventManager _eventManager;
	// Scene Objects
	std::vector<scene_ptr> _game_scenes;
	
    // Methods
    void initialiseWindow();
};




#endif
