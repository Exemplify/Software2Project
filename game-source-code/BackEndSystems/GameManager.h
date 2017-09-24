#ifndef GAME_MAN_H
#define GAME_MAN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <mutex>

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
	string game_name = "#FMF";
};

class GameTime;
// why is the above necessary, and how is GameTime defined in terms of an include .h?
class GameManager
{
public:
	GameManager() {};
	void GameLoop();
	static scene_ptr activeScene;
    // is scene_ptr from SFML?
	static void Exit();
	static void LoadScene(unsigned int index);
	void AddScene(scene_ptr newScene);
private:
	GameTime* _gameTime;
    // why a GameTime pointer, also can this be implemented as a unique pointer
    // Variables
	WindowSettings _defaultSetup;
	// Backend Objects 
	static bool closeWindow;
    // why is this a static?
	DisplayManager _dispManager;
    // creates an instance of the DisplayManeger class as a _dispManager object, why?
	EventManager _eventManager;
    // creates an instance of the EventManager class as an _eventManager object, why?
	// Scene Objects
	static std::vector<scene_ptr> _game_scenes;
    // understandably the above vector stores all the scenes that is intended to be run by the game.
	
    // Methods
    void initialiseWindow(RenderWindow&_gameWindow);
};

#endif
