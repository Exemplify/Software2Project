#ifndef ENEMY_CON_H
#define ENEMY_CON_H
#include "GameObject.h"
#include "../BackEndSystems/EnemyFactory.h"
#include "Enemy.h"

/*
 * Enemy controller is responsible or spawning new enemy objects and monitoring how many 
 * enemies have been destroyed, when an enemy is destroyed the enemy controller is notified, 
 * the total number of enemies spawned and destroyed is tracked
 */
 /// loading the next scene needs to be removed from this object and placed into a "SceneController" which is responsible for the
 /// scene state, including win/lose condition checks as well as information about the state of the game, score graphics display etc
 /// Enemy Tracker and Enemy Spawner break up into less responsibilites
 /// needs copy constructor and assignment opperator
class EnemyController: public GameObject
{
public:
	// Default construtor
	EnemyController(unsigned int max_enemies, double enemySpawnDelay);
	// Update override function
	virtual void Update() override;
	// public function that is called by the enemy that has been killed
	void EnemyKilled();
private:
	/// Delay code needs to be replaced with a delaycomponent
	void SpawnEnemyCountDown();
	void SpawnEnemy();
	// Integer that stores the number of enemies killed 
	int numberOfEnemiesKilled = 0;
	///delay code needs to moved to a database and a delaycomponent
	const int MAX_NUMBER_OF_ENEMIES;
	const double ENEMY_SPAWN_DELAY;
	double _timeBetweenSpawns;
	EnemyFactory _enemyFactory;
	// enemy count tracks the number of enemies spawned into the scene
	int enemyCount = 0;
};
#endif 