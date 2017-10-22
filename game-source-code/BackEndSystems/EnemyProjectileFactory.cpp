#include "EnemyProjectileFactory.h"
#include "../Vector2D.h"
#include "GameObjectDataAdaptor.h"
#include "../FrontEndSystems/LinearMove.h"

std::shared_ptr<GameObject> EnemyProjectileFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto objectData = getObjectData(database);
	auto physicsObject = std::dynamic_pointer_cast<PhysicsObject>(PhysicsObjectFactory::getGameObject(database));
	auto move = std::make_shared<LinearMove>(objectData.move_speed);
	return std::make_shared<EnemyProjectile>(*physicsObject, move, Boundary());
}

GameObjectData EnemyProjectileFactory::getObjectData(const std::shared_ptr<DatabaseInterface>& database)
{
	return database->getGameObjectData("enemyProjectile");
}