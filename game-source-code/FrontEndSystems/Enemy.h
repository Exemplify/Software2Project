#ifndef ENEM_H
#define ENEM_H
#include "PhysicsObject.h"
#include "Character.h"
#include "DelayComponent.h"
#include "ShootComponent.h"
#include "Boundary.h"

enum class EnemyMoveType
{
	linear,
	parabolic,
	spiral
};

class Enemy: public PhysicsObject
{
public:
	Enemy();
	virtual void Update() override;
    virtual void collisionAction(GameObjectType objectType) override;
    EnemyMoveType getMoveType() const {return _movementType;}
private:
	void Move();
	void Shoot();
	void CheckOutsideScreen();
	DelayComponent _shootDelay;
	Character _enemyStats;
	ShootComponent _enemyShoot;
	Boundary _screenBounds;
	EnemyMoveType _movementType;
	int _direction;

	// used to initialise the different enemy objects and vary the movement styles
	// Run from within the constructor
	void InitialiseObject();
	void EnemyDirection();
	void InitialiseMovementType(const int& randomChanceValue);
	void ConstructSpriteInfo();
	void InitialiseStartingPosition();
	void InitialiseLinearMovement(const double& angle);
	void InitialiseParabolicMovement();
	void InitialiseSpiralMovement(const double& angle);
	void DetermineDirection();
	double GenerateRandomAngle();
	
	// Different movement functions
	void SpiralMove();
	void LinearMove();
	void ParabolicMove();
};


#endif 