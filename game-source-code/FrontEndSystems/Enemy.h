#ifndef ENEM_H
#define ENEM_H
#include "PhysicsObject.h"
#include "Character.h"
#include "DelayComponent.h"
#include "ShootComponent.h"
#include "Boundary.h"
#include "GraphicObject.h"


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
	// Enemy Default constructor initialises class does not need external information
	Enemy();
	// Override Function from GameObject 
	virtual void Update() override;
	// Override function from PhysicsObject
    virtual void collisionAction(GameObjectType objectType) override;
	// Clone function necessary to duplicate the class using a covarient return type
	virtual Enemy* Clone() override 
	{return new Enemy(*this);}
    EnemyMoveType getMoveType() const {return _movementType;}
	const std::shared_ptr<GraphicObject> getGraphicObject() override {return _graphicObject;}
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
	ShootComponent _enemyShoot;
	// Boundary object used to detect when the object is outside the screen
	Boundary _screenBounds;
	EnemyMoveType _movementType;
	int _direction;
	//  graphic component of the enemy
	std::shared_ptr<GraphicObject> _graphicObject;
	

	// used to initialise the different enemy objects and vary the movement styles
	// Run from within the constructor
	void InitialiseObject();
	void EnemyDirection();
	/// Movement functions need to be moved into a seperate class 
	/// sprite information needs to be moved to a database
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
	
	// On Collision Functions
	// object response to colliding with a player bullet 
	void PlayerProjectileCollision();
	
};


#endif 