#ifndef PLAYER_PROJ_FAC
#define PLAYER_PROJ_FAC
#include "GameObjectFactory.h"

/**
 * @class PlayerProjectileFactory
 * @brief PlayerProjectileFactory is responsible for the construction of any PlayerProjectile objects
 */
class PlayerProjectileFactory: public GameObjectFactory
{
public:
	/**
	 * @brief Function call used to create an PlayerProjectile Object 
	 * @return Returns an An PlayerProjectile Object with the specific characteristics for this game
	 */
	virtual std::shared_ptr<GameObject> getGameObject() override;
	virtual ~PlayerProjectileFactory() {}
};


#endif
