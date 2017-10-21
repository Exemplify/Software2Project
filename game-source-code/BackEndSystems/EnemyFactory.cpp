#include "EnemyFactory.h"
#include "../FrontEndSystems/Enemy.h"
#include "../FrontEndSystems/BasicShoot.h"
#include "GameObjectDataAdaptor.h"

/**
 * @details Creates the required parameters for each object and passes them by value to ensure that the information is copied to the object
 * This is done so that the default object information is not changed.
 */
std::shared_ptr<GameObject> EnemyFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{
	auto enemyData = getEnemyData(database);
	auto startingPosition = getStartingPosition(enemyData);
	auto scale = GameObjectDataAdaptor::ScaleAdaptor(enemyData);
	auto enemyGraphic = GameObjectDataAdaptor::graphicObjectAdaptor(enemyData);
	auto enemyMove = getMovableType(enemyData);
	auto enemyShoot = std::make_shared<BasicShoot>(GameObjectType::enemyBullet);
	return std::make_shared<Enemy>(startingPosition,scale, enemyGraphic, enemyData.collider_size, enemyData.enemy_shoot_delay, enemyMove, enemyShoot);
}
Vector2D EnemyFactory::getStartingPosition(const GameObjectData& data)
{
	return Vector2D::origin;
}