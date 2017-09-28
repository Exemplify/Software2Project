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
class GameManager
{
public:
	GameManager() {};
	void GameLoop();
	static scene_ptr activeScene;
	static void Exit();
	static void LoadScene(unsigned int index);
	void AddScene(scene_ptr newScene);
	static int getScene() {return _scene_index;}
private:
	GameTime* _gameTime;
	// represents the current scene that the player is in
	static int _scene_index;
    // Variables
	WindowSettings _defaultSetup;
	// Backend Objects 
	static bool closeWindow;
	DisplayManager _dispManager;
	EventManager _eventManager;
	// Scene Objects
	static std::vector<scene_ptr> _game_scenes;
	static scene_ptr original_activeScene;
    // Methods
    void initialiseWindow(RenderWindow&_gameWindow);
};

#endif
