#ifndef ENEM_H
#define ENEM_H
#include "GraphicObject.h"
#include "Character.h"
#include "DelayComponent.h"
#include "ShootComponent.h"
#include "Boundary.h"

class Enemy: public GraphicObject
{
public:
	Enemy() {}
	Enemy(Character enem, GameObjectType _Enemtype);
	virtual void Update() override;
private:
	void Move();
	void InitialisePosition();
	void Shoot();
	void CheckOutsideScreen();
	DelayComponent _shootDelay;
	Character _enemyStats;
	ShootComponent _enemyShoot;
	Boundary _screenBounds;
	int _direction;
	void ComplexMove();
	void BasicMove();
	void Enemy2Direction();

	
};

#endif 