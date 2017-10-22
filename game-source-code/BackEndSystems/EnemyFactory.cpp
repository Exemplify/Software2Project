#include "EnemyFactory.h"
#include "../FrontEndSystems/Enemy.h"
#include "../FrontEndSystems/BasicShoot.h"
#include "GameObjectDataAdaptor.h"

/**
 * @details Creates the required parameters for each object and passes them by value to ensure that the information is copied to the object
 * This is done so that the default object information is not changed.
 */
std::shared_ptr<GameObject> EnemyFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto enemyData = getObjectData(database);
	auto physicsObject = std::dynamic_pointer_cast<PhysicsObject>(PhysicsObjectFactory::getGameObject(database));
	auto enemyMove = getMovableType(enemyData);
	auto enemyShoot = std::make_shared<BasicShoot>(GameObjectType::enemyBullet);
	return std::make_shared<Enemy>(*physicsObject, enemyData.enemy_shoot_delay, enemyMove, enemyShoot);
}