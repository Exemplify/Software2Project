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
/// must be moved into a database class
struct WindowSettings
{
    unsigned int screenWidth = 1920;
	unsigned int screenHeight = 1080;
	Uint32 winStyle = Style::Default;
	string game_name = "#FMF";
};
// forwared declaration for game time
class GameTime; 
/// Needs to be converted into a singleton
class GameManager
{
public:
	/// redundant default constructor
	GameManager() {};
	// The main game loop game only starts when this is called
	void GameLoop();
	// the current scene that is being used by the game and the collection of objects insied of it
	static scene_ptr activeScene;
	// Exit is used to close the game
	static void Exit();
	// Load Scene is used to change game scenes 
	static void LoadScene(unsigned int index);
	// Adds a new scene to the list of scenes available
	void AddScene(scene_ptr newScene);
	// returns the current scenes index within the vector of scenes 
	static int getScene() {return _scene_index;}
private:
	/// convert to unique pointer
	GameTime* _gameTime;
	// represents the current scene that the player is in
	static int _scene_index;
    // Variables
	WindowSettings _defaultSetup;
	// Backend Objects 
	static bool closeWindow;
	EventManager _eventManager;
	// Scene Objects
	static std::vector<scene_ptr> _game_scenes;
	static scene_ptr original_activeScene;
		
	// Initialises the sfml RenderWindow, specifies the required size and information
	/// some responsibilites can be moved into the display manager
    void initialiseWindow(RenderWindow&_gameWindow);
};

#endif
