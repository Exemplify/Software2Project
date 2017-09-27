#ifndef ENEMY_CON_H
#define ENEMY_CON_H
#include "GameObject.h"
#include "Enemy.h"


class EnemyController: public GameObject
{
public:
	EnemyController();
	virtual void Update() override;
private:
	void SpawnEnemyCountDown();
	void SpawnEnemy();
	void SpawnEnemyType1();
	void SpawnEnemyType2();
	
	const double ENEMY_SPAWN_DELAY = 2;
	double _timeBetweenSpawns;
	int enemyCount = 0;
};
#endif 