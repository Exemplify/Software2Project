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
	/**
	 * @brief Constructs an EnemyController Object
	 * @param max_enemies The maximum number of enemies that the EnemyController will create
	 * @param enemySpawnDelay The time delay between spawning an enemy object
	 */
	EnemyController(unsigned int max_enemies, double enemySpawnDelay);
	/**
	 * @brief Creates enemies based on the spawn delay
	 */
	virtual void Update() override;
	/**
	 * @brief Called by the EnemyObject to inform the EnemyController that it has been destroyed by the Player object
	 */
	void EnemyKilled();
	/**
	 * @brief Called by the EnemyObject to inform the EnemyController that it has been destroyed by the moving out of bounds
	 * @details spawns a new enemy without checking the delay as the enemy has already been spawned
	 */
	void EnemyOutofBounds();
private:
	/**
	 * @brief Checks if an Enemy can be spawned due to the spawn delay, calls SpawnEnemy if it can be
	 */
	void SpawnEnemyCountDown();
	/**
	 * @brief Creates an enemy and adds it to the same Scene as the EnemyController
	 */
	void SpawnEnemy();
	
	unsigned int numberOfEnemiesKilled; /**<Tracks the number of enemies that the player has destroyed*/
	const unsigned int MAX_NUMBER_OF_ENEMIES; /**<The maximum number of enemies that the EnemyController can create*/
	DelayComponent _enemySpawnDelay; /**<The delay component used to track the delay between enemy spawns*/
	unsigned int enemyCount; /**<The current number of enemies that have been spawned*/
};
#endif 