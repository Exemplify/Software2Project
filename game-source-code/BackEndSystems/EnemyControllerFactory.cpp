#include "EnemyControllerFactory.h"

std::shared_ptr<GameObject> EnemyControllerFactory::getGameObject()
{
	auto max_num_Enemies = 10u;
	auto spawn_delay = 2.0;
	auto enemyController = std::make_shared<EnemyController>(max_num_Enemies, spawn_delay);
	return enemyController;
}