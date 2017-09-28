#include "EnemyController.h"
#include "Character.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/GameTime.h"
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
	auto deltaTime = GameTime::getDeltaTime();
	_timeBetweenSpawns -= deltaTime;
	if(_timeBetweenSpawns <= 0 && enemyCount < 10)
	{
		SpawnEnemy();
		_timeBetweenSpawns = ENEMY_SPAWN_DELAY;
	}
}

void EnemyController::SpawnEnemy()
{
	auto scene = GameManager::activeScene;
	// health and lives
	std::shared_ptr<GameObject> enemy = std::make_shared<Enemy>();
	scene->Instantiate(enemy);
	enemyCount++;
}
