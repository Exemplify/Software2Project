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
	
	const double ENEMY_SPAWN_DELAY = 3;
	double _timeBetweenSpawns;
	int enemyCount = 0;
};
#endif 