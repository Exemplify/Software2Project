#ifndef ENEM_H
#define ENEM_H
#include "PhysicsObject.h"
#include "Character.h"
#include "DelayComponent.h"
#include "ShootInterface.h"
#include "Boundary.h"
#include "GraphicObject.h"
#include "../BackEndSystems/EnemyProjectileFactory.h"
#include "SizeReduction.h"
#include "MovableInterface.h"


enum class EnemyMoveType
{
	linear,
	parabolic,
	spiral
};

/// Needs to be changed into a polymorphic interaction where different characters define different movement types
/// requires a large amount of redesign for a better implementation
/// Needs a copy constructor and assignment opperator
class Enemy: public PhysicsObject
{
public:
	Enemy(){}
	Enemy(xyVector scale, GraphicObject enemyGraphic, double colliderSize, double shootDelay, std::shared_ptr<MovableInterface> moveComp);
	// Override Function from GameObject 
	virtual void Update() override;
	// Override function from PhysicsObject
    virtual void collisionAction(GameObjectType objectType) override;
	
    EnemyMoveType getMoveType() const {return _movementType;}
	
private:
	// Move function that is called inside update to move the current enemy object
	void Move();
	// Shoot function used to instantiate enemy bullets
	void Shoot();
	// Checks if the enemy is outside of the screen bounds
	void CheckOutsideScreen();
	
	// delay used between each shot per object
	DelayComponent _shootDelay;
	/// Character needs to change
	Character _enemyStats;
	/// Enemy Shoot needs to be put into character
	std::unique_ptr<ShootInterface> _enemyShoot;
	// Boundary object used to detect when the object is outside the screen
	Boundary _screenBounds;
	EnemyMoveType _movementType;
	int _direction;
	SizeReduction _sizeReduction;
	std::shared_ptr<MovableInterface> _moveComp;
	

	// used to initialise the different enemy objects and vary the movement styles
	// Run from within the constructor
	void InitialiseObject();
	void EnemyDirection();
	/// Movement functions need to be moved into a seperate class 
	/// sprite information needs to be moved to a database
	void InitialiseMovementType(const int& randomChanceValue);
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
	
	// On Collision Functions
	// object response to colliding with a player bullet 
	void PlayerProjectileCollision();
	
};


#endif 