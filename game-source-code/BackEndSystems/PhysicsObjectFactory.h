#ifndef PHYSICS_OBJ_FAC_H
#define PHYSICS_OBJ_FAC_H
#include "GameObjectFactory.h"

/**
 * @class PhysicsObjectFactory
 * @brief Used to construct a physics Object within the game
 */
class PhysicsObjectFactory : public GameObjectFactory
{
public:
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) override;
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override = 0;
};

#endif