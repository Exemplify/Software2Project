#ifndef ENEM_H
#define ENEM_H
#include "GraphicObject.h"
#include "Character.h"
#include "DelayComponent.h"
#include "ShootComponent.h"

class Enemy: public GraphicObject
{
public:
	Enemy(Character enem);
	virtual void Update() override;
private:
	void Move();
	void InitialisePosition();
	void Shoot();
	DelayComponent _shootDelay;
	Character _enemyStats;
	ShootComponent _enemyShoot;
	void CheckOutsideScreen();
	bool CheckxOutofBounds(double xPos);
	bool CheckyOutofBounds(double yPos);
	
};

#endif 