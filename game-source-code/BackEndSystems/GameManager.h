#ifndef GAME_MAN_H
#define GAME_MAN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <mutex>

#include "DisplayManager.h"
#include "EventManager.h"
#include "RepositoryInterface.h"
#include "../FrontEndSystems/Scene.h"
#include "GameTime.h"


// Struct that contains the default settings for the window 
/// must be moved into a database class
struct WindowSettings
{
	WindowSettings(unsigned int screen_width, unsigned int screen_height, std::string game_name):
	screenWidth{screen_width},
	screenHeight{screen_height},
	gameName{game_name}
	{}
    unsigned int screenWidth;
	unsigned int screenHeight;
	std::string gameName;
	Uint32 winStyle = sf::Style::Default;
};
// forwared declaration for game time
/**
 * @class GameManager
 * @brief GameManager is responsible for intialising and maintaining the game state,  and updating the game loop through the composition of different Scene objects that exist within the game, 
 * it communicates with the EventManager, DisplayManager and CollisionDetection classes regarding the state of the game
 */
class GameManager
{
public:
	/// redundant default constructor
	GameManager(std::shared_ptr<RepositioryInterface> repository, int startingSceneindex = 0);
	// The main game loop game only starts when this is called
	void GameLoop();
	// the current scene that is being used by the game and the collection of objects insied of it
	static std::shared_ptr<Scene> activeScene;
	// Exit is used to close the game
	static void Exit();
	// Load Scene is used to change game scenes 
	void LoadScene(unsigned int index);
	static int getSceneIndex()
	{
		return _scene_index;
	}

	// returns the current scenes index within the vector of scenes 
	static const bool gameClosed()
	{return closeWindow;} 
private:
	std::shared_ptr<RepositioryInterface> _repository;
	sf::RenderWindow _window;
	std::unique_ptr<GameTime> _gameTime;
	// represents the current scene that the game is in
	static int _scene_index;
    // Variables
	WindowSettings _defaultSetup;
	// Backend Objects 
	static bool closeWindow;
	EventManager _eventManager;
	// Scene Objects
	std::vector<std::shared_ptr<Scene>> _game_scenes;
		
	// Initialises the sfml RenderWindow, specifies the required size and informatio
    void initialiseWindow(sf::RenderWindow&_gameWindow);
};

#endif
