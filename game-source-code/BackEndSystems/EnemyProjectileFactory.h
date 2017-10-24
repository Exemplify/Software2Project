#ifndef ENEM_PROJ_FAC
#define ENEM_PROJ_FAC
#include "PhysicsObjectFactory.h"
#include "../FrontEndSystems/EnemyProjectile.h"
/**
 * @class EnemyProjectileFactory
 * @brief EnemyControllerFactory is responsible for the construction of any EnemyController objects
 */
class EnemyProjectileFactory: public PhysicsObjectFactory
{
public:
	/**
	 * @brief Function call used to create an EnemyProjectile Object 
	 * @return Returns an An EnemyProjectile Object with the specific characteristics for this game
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) override;
	/**
	* @brief used to obtain the specific GameObjectData defined for the current factory
	* @param database The specific DatabaseInterface that contains the information about the GameObject
	* @return The GameObjectData required for the construction of the object
	*/
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
};

#endif