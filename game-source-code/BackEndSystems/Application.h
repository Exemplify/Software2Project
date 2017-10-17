#ifndef APPLICATION_INTER_H 
#define APPLICATION_INTER_H

#include "RepositoryInterface.h"
#include "GameManager.h"
#include <memory>
#include "DatabaseInterface.h"
/**
 * @class MultipleRepositoryIntialisations
 * @brief Exception that is thrown if multiple repositories are created at run time.S
 */
class MultipleRepositoryIntialisations{};
/**
 * @class Application
 * @brief Application acts as the main interface between the game objects and the game system. It allows game objects to access information about the current state of the game
 * and to load scenes when certain conditions are met. It also provides game objects with access to the Repository object so that new gameObjects can be instantiated into the 
 * current scene of the game.
 */
class Application
{
public:
	Application(std::shared_ptr<RepositioryInterface> repository);
	/**
	 * @brief getter used to provide global access to the repository object used within the game system. The object is returned as a constant pointer to ensure that it cannot be changed.
	 * @return Returns the repository object used within the game
	 */
	static const std::shared_ptr<RepositioryInterface> getGameRepository();
	/**
	 * @brief Callback used to change the active scene to a different one at a particular index. 
	 * @param index The index value of the desired Scene that the game needs to change to.
	 */
	static void LoadScene(int index);
	/**
	 * @brief Closes the Current application window
	 */
	static void CloseApplication();
	/**
	 * @brief Runs the application
	 */
	void RunApplication();
	/**
	 * @brief obtains the scene index of the game
	 * @return Returns the scene index that is currently being used 
	 */
	static const unsigned int currentSceneIndex();
private:
	static std::shared_ptr<RepositioryInterface> _repository; /**< RepositoryInterface object that can only be initialised once at runtime*/
	static std::shared_ptr<GameManager> _gameManager; /**< GameManager object used to run the initialise and run the game loop*/
};
#endif 