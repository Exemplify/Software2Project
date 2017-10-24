#include "EnemyControllerFactory.h"

std::shared_ptr<GameObject> EnemyControllerFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto gameObject = GameObjectFactory::getGameObject(database);
	auto objectdata = getObjectData(database);
	auto max_num_Enemies = objectdata.max_enemies;
	auto spawn_delay = objectdata.enemy_spawn_delay;
	return std::make_shared<EnemyController>(*gameObject, max_num_Enemies, spawn_delay);
}

GameObjectData EnemyControllerFactory::getObjectData(const std::shared_ptr<DatabaseInterface>& database)
{
	return database->getGameObjectData("enemyController");
}