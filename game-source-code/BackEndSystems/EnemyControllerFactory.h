#ifndef ENEM_CON_FAC_H
#define ENEM_CON_FAC_H
#include "GameObjectFactory.h"
#include "../FrontEndSystems/EnemyController.h"

/**
 * @class EnemyControllerFactory
 * @brief EnemyControllerFactory is responsible for the construction of any EnemyController objects
 */
class EnemyControllerFactory: public GameObjectFactory
{
public:
	/**
	 * @brief Function call used to create an EnemyController Object 
	 * @return Returns an EnemyController Object with the specific characteristics for this game
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) override; 
	/**
	 * @brief used to obtain the specific GameObjectData defined for the current factory
	 * @param database The specific DatabaseInterface that contains the information about the GameObjects 
	 * @return The GameObjectData required for the construction of the object
	 */
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
	
	virtual ~EnemyControllerFactory() = default;
};

#endif