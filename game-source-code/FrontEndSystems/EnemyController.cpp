#include "EnemyController.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/Time.h"
#include <memory>


EnemyController::EnemyController():GameObject()
{
	_timeBetweenSpawns = ENEMY_SPAWN_DELAY;
}
void EnemyController::Update()
{
	SpawnEnemyCountDown();
}
void EnemyController::SpawnEnemyCountDown()
{
	_timeBetweenSpawns -= GameTime::getDeltaTime();
	if(_timeBetweenSpawns <= 0)
	{
		SpawnEnemy();
		_timeBetweenSpawns = ENEMY_SPAWN_DELAY;
	}
}

void EnemyController::SpawnEnemy()
{
	auto scene = GameManager::activeScene;
	std::shared_ptr<GameObject> enemy = std::make_shared<GameObject>();
	scene->Instantiate(enemy);
	enemyCount++;
}