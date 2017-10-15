#include "EnemyControllerFactory.h"

std::shared_ptr<GameObject> EnemyControllerFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{
	auto objectdata = database->getGameObjectData("enemyController");
	auto max_num_Enemies = objectdata.max_enemies;
	auto spawn_delay = objectdata.enemy_spawn_delay;
	return std::make_shared<EnemyController>(max_num_Enemies, spawn_delay);
}