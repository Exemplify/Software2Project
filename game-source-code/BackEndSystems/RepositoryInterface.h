#ifndef REPO_INTER_H
#define REPO_INTER_H
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include "../Vector2D.h"
#include <string>
#include <vector>
#include <memory>

/**
 * @class RepositioryInterface
 * @brief RepositoryInterface provides the game systems access to the database layer and the information it contains. Is also responsible for constructing the objects and Scenes used within the game.
 */

class RepositioryInterface
{
public:
	/**
	 * @brief Constructs the various Scenes required for the game implementation
	 * @return Returns a Vector of shared pointers of Scenes that are to exist in the game
	 */
	virtual std::vector<std::shared_ptr<Scene>> getGameScenes() const = 0;
	/**
	 * @brief Used to Construct GameObjects that are MAKE_MOCK0()nly created once the game is already running 
	 * @param objtype The type of GameObject that is required
	 * @returns Returns the desired GameObject
	 */
	virtual std::shared_ptr<GameObject> getGameObjectbyTypeDuringRuntime(GameObjectType objtype) const = 0;
	/**
	 * @brief Returns the Screen Size of the game
	 * @return returns a vector where the first element is the x Screen Size value and the second element is the y Screen Size value
	 */
	virtual std::vector<unsigned int> getGameScreenSize() const = 0;
	/**
	 * @brief returns the name of the game
	 * @return Returns a string that represents the name of the game
	 */
	virtual std::string getGameName() const = 0;
	
	virtual ~RepositioryInterface() = default;
};

#endif