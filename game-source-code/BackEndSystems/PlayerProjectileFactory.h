#ifndef PLAYER_PROJ_FAC
#define PLAYER_PROJ_FAC
#include "PhysicsObjectFactory.h"

/**
 * @class PlayerProjectileFactory
 * @brief PlayerProjectileFactory is responsible for the construction of any PlayerProjectile objects
 */
class PlayerProjectileFactory: public PhysicsObjectFactory
{
public:
	/**
	 * @brief Function call used to create an PlayerProjectile Object 
	 * @return Returns an An PlayerProjectile Object with the specific characteristics for this game
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) override;
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
	virtual ~PlayerProjectileFactory() = default;
};


#endif
