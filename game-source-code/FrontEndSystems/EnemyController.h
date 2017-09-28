#ifndef ENEMY_CON_H
#define ENEMY_CON_H
#include "GameObject.h"
#include "Enemy.h"


class EnemyController: public GameObject
{
public:
	EnemyController();
	virtual void Update() override;
	void EnemyKilled();
	virtual EnemyController* Clone() override 
	{return new EnemyController(*this);}
private:
	void SpawnEnemyCountDown();
	void SpawnEnemy();
	
	int numberOfEnemiesKilled = 0;
	const int MAX_NUMBER_OF_ENEMIES = 10;
	const double ENEMY_SPAWN_DELAY = 3;
	double _timeBetweenSpawns;
	int enemyCount = 0;
};
#endif 