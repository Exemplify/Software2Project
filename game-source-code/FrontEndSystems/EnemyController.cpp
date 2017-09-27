#include "EnemyController.h"
#include "Character.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/GameTime.h"
#include <memory>

int const MAXPERCENT = 100;
int const SPAWN_ENEMY2_PERCENT = 60;


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

void EnemyController::SpawnEnemyType2()
{
	auto scene = GameManager::activeScene;
	// health and lives
	Character enem1{1,4};
	std::shared_ptr<GameObject> enemy = std::make_shared<Enemy>(enem1, GameObjectType::enemy2);
	scene->Instantiate(enemy);
	enemyCount++;
}
void EnemyController::SpawnEnemy()
{
	auto randPercent = rand() % MAXPERCENT;
	if(randPercent < SPAWN_ENEMY2_PERCENT)
	{
		SpawnEnemyType2();
	}else 
	{
		SpawnEnemyType1();
	}
	
}
void EnemyController::SpawnEnemyType1()
{
	auto scene = GameManager::activeScene;
	// health and lives
	Character enem1{1,150};
	std::shared_ptr<GameObject> enemy = std::make_shared<Enemy>(enem1, GameObjectType::enemy1);
	scene->Instantiate(enemy);
	enemyCount++;
}
