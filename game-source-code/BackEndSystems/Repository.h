#ifndef REPO_H
#define REPO_H
#include "RepositoryInterface.h"
#include "DataMapperInterface.h"
#include "DatabaseInterface.h"
/**
 * @class GameObjectTypeConstructionNotDefined
 * @brief Exception thrown if a GameObjectType is consturcted during runtime and it has not been defined
 */
class GameObjectTypeConstructionNotDefined{};

/**
 * @class Repository
 * @brief Repository object used to create the specific scenes and objects defined for the current game implementation
 */
class Repository : public RepositioryInterface
{
public:
	/**
	 * @brief Constructs the repository object used by the game to create the various GameObjects and Scenes for the current game
	 * @param datamapper the DataMapperInterface used to update the _runtime_database
	 * @param runtime_database The DatabaseInterface that stores the information of the game during game runtime
	 */
	Repository(std::shared_ptr<DataMapperInterface> dataMapper, std::shared_ptr<DatabaseInterface> runtime_database);
	/**
	 * @brief Used to generate a specific GameObject during runtime of the game, is only defined for the various gameObjects that are created during game runtime
	 * @param objtype The GameObjectType that represents the object that needs to be created
	 * @return Returns the desired GameObject
	 */
	virtual std::shared_ptr<GameObject> getGameObjectbyTypeDuringRuntime(GameObjectType objtype) const override;
	/**
	 * @brief Used to create the various scenes for the game
	 * @return Returns a Vector of shared pointers of Scenes that are to exist in the game
	 */
	virtual std::vector<std::shared_ptr<Scene>> getGameScenes() const override;
	/**
	 * @brief Obtains the Size of the Screen from the DatabaseInterface 
	 * @return Returns the Screen Size of the game
	 */
	virtual std::vector<unsigned int> getGameScreenSize() const override;
	/**
	 * @brief Obtains the game name from the DatabaseInterface
	 * @return Returns the Name of the Game as a string 
	 */
	virtual std::string getGameName() const override;
	
	virtual ~Repository() = default;
private:
	std::shared_ptr<DataMapperInterface> _dataMapper; /**<The DataMapperInterface used to update the _runtime_database*/
	std::shared_ptr<DatabaseInterface> _runtime_database; /**<The DatabaseInterface used to store the game object information at during runtime of the application*/
};


#endif