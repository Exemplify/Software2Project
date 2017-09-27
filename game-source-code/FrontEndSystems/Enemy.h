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
	Enemy(Character enem);
	virtual void Update() override;
private:
	void Move();
	void InitialisePosition();
	void Shoot();
	void CheckOutsideScreen();
	DelayComponent _shootDelay;
	Character _enemyStats;
    // does this class really need to know enemy character statistics. Should it not just execute the action of an enemy (and have those charateristics and stats handled elsewhere)?
	/// See cpp did talk about this in there 
	ShootComponent _enemyShoot;
	Boundary _screenBounds;

	
};

#endif 