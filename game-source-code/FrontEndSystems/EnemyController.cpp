#include "EnemyController.h"
#include "Character.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/GameTime.h"
#include <memory>

EnemyController::EnemyController():GameObject()
{
	_timeBetweenSpawns = ENEMY_SPAWN_DELAY;
	_type = GameObjectType::enemyController;
}
void EnemyController::Update()
{
	SpawnEnemyCountDown();
}
void EnemyController::SpawnEnemyCountDown()
{
	auto deltaTime = GameTime::getDeltaTime();
	_timeBetweenSpawns -= deltaTime;
	if(_timeBetweenSpawns <= 0 && enemyCount < MAX_NUMBER_OF_ENEMIES)
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
void EnemyController::EnemyKilled()
{
	numberOfEnemiesKilled++;
	if(numberOfEnemiesKilled == MAX_NUMBER_OF_ENEMIES)
	{
		const auto WINNING_SCENE = 2;
		GameManager::LoadScene(WINNING_SCENE);
	}
}
