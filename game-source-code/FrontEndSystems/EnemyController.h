#ifndef ENEMY_CON_H
#define ENEMY_CON_H
#include "GameObject.h"
#include "DelayComponent.h"
#include <memory>


/*
 * Enemy controller is responsible for spawning new enemy objects and monitoring how many 
 * enemies have been destroyed, when an enemy is destroyed the enemy controller is notified, 
 * the total number of enemies spawned and destroyed is tracked
 */
/**
 * @class EnemyController
 * @brief Enemy controller is responsible for spawning and monitoring new enemy objects
 * @details The number of enemies spawned and destroyed is moitored. When an enemy goes out of bounds it is destroyed and created a new.
 * The enemy objects have access to the EnemyController to communicate with it when they are destroyed by the player and when they leave the bounds of the screen.
 * If all the enemies have been destroyed the EnemyController changes scenes to the WinScreen 
 */
class EnemyController: public GameObject
{
public:
	// Default construtor
	EnemyController(unsigned int max_enemies, double enemySpawnDelay);
	// Update override function
	virtual void Update() override;
	// public function that is called by the enemy that has been killed
	void EnemyKilled();
	void EnemyOutofBounds();
private:
	void SpawnEnemyCountDown();
	void SpawnEnemy();
	// Integer that stores the number of enemies killed 
	unsigned int numberOfEnemiesKilled = 0;
	const unsigned int MAX_NUMBER_OF_ENEMIES;
	DelayComponent _enemySpawnDelay;
	double _timeBetweenSpawns;
	// enemy count tracks the number of enemies spawned into the scene
	unsigned int enemyCount = 0;
};
#endif 