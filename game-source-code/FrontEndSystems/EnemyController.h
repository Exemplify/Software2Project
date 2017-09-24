#ifndef ENEMY_CON_H
#define ENEMY_CON_H
#include "GameObject.h"
#include "Enemy.h"

/* This class is essentially the choreographer and instructs by a path defenition haw an enemy/ group of enemies should behave...
 * should this not be a polymorphic base class that can hold all possible patterned movesets of the enemy.
 * that is as an example:
 *      randomSpawnAtCentre
 *      inwardTwerlSpawn
 *      convergeToCentre
 * 
 * Further would this not be a composition within a Scene i.e. Scene1 contains Act1 (randomSpawnAtCentre, Act2(convergeToCentre), Act3(randomSpawnAtCentre), Act4(inwardTwerlSpawn), etc.
 * So this class could be called the choreographer and allow for the base virtual functions for complex enemy move sets.
*/
class EnemyController: public GameObject
{
public:
	EnemyController();
	virtual void Update() override;
private:
	void SpawnEnemyCountDown();
	void SpawnEnemy();
	
	const double ENEMY_SPAWN_DELAY = 2;
	double _timeBetweenSpawns;
	int enemyCount = 0;
};
#endif 