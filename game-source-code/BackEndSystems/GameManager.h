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

/**
 * @class SceneDoesntExist
 * @brief Exception thrown if a scene does not exist at the specific index that is requested
 */
class SceneDoesntExist{};

/**
 * @class WindowSettings
 * @brief Contains the Default settings for the Game Window, is assigned default information from the repository
 */
struct WindowSettings
{
	WindowSettings(unsigned int screen_width, unsigned int screen_height, std::string game_name):
	screenWidth{screen_width},
	screenHeight{screen_height},
	gameName{game_name}
	{}
    unsigned int screenWidth; /**<Screen Width of the game*/
	unsigned int screenHeight;/**<Screen Height of the game*/
	std::string gameName; /**<Name of the game*/
	Uint32 winStyle = sf::Style::Default; /**<*/
};

/**
 * @class GameManager
 * @brief GameManager is responsible for intialising and maintaining the game state, and updating the game loop through the composition of different Scene objects that exist within the game, 
 * it communicates with the EventManager, DisplayManager and CollisionDetection classes regarding the state of the game
 */
class GameManager
{
public:
	/**
	* @brief Constructs the GameManager object neccesary for the Game loop
	* @param repository The instance of the Repository used to generate the Scenes for the game
	*/
	GameManager(std::shared_ptr<RepositioryInterface> repository);
	/**
	 * @brief Runs the main game loop of the game, and updates the various GameObjects Stored inside of the activeScene
	 */
	virtual void GameLoop();
	
	/**
	 * @brief Closes the game window 
	 */
	virtual void Exit();
	/**
	 * @brief Changes the active Scene to the Scene at the desired SceneIndex
	 * @param index The index for which the desired scene is located
	 */
	virtual void LoadScene(unsigned int index);
	/**
	 * @brief Returns the current scene index
	 * @return The Current Scene Index
	 */
	virtual unsigned int getSceneIndex()
	{
		return _scene_index;
	}
	/**
	 * @brief Identifies whether the game has been closed 
	 * @return Returns a constant bool whether the game is closed
	 */
	static const bool gameClosed()
	{return closeWindow;} 

	static std::shared_ptr<Scene> activeScene; /**<public static variable that represents the active Scene - Bad design reveals too much information*/
private:
	std::shared_ptr<RepositioryInterface> _repository; /**<The RepositoryInterface used to generate the Scenes for the game*/
	sf::RenderWindow _window; /**<The sfml RenderWindow used for the game*/
	std::unique_ptr<GameTime> _gameTime; /**<A unique pointer to a GameTime object, used to update the time between frames*/
	// represents the current scene that the game is in
	static int _scene_index; /**<The current Scene Index for the game*/
    // Variables
	WindowSettings _defaultSetup; /**<the default Setup information for the game*/
	// Backend Objects 
	static bool closeWindow; /**<bool used to identify when the game should be closed*/
	// Scene Objects
	std::vector<std::shared_ptr<Scene>> _game_scenes; /**<A vector of Scene Objects used to represent the different Scenes of the game*/
		
	/**
	 * @brief Initialises the sfml RenderWindow to the properties defined by the default window settings
	 * @param _gameWindow
	 */
    void initialiseWindow(sf::RenderWindow&_gameWindow); 
};

#endif
