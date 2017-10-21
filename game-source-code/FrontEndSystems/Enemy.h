#ifndef ENEM_H
#define ENEM_H
#include "PhysicsObject.h"
#include "DelayComponent.h"
#include "ShootInterface.h"
#include "Boundary.h"
#include "GraphicObject.h"
#include "../BackEndSystems/EnemyProjectileFactory.h"
#include "SizeReduction.h"
#include "MovableInterface.h"
#include "EnemyController.h"

/// Needs to be changed into a polymorphic interaction where different characters define different movement types
/// requires a large amount of redesign for a better implementation
/// Needs a copy constructor and assignment opperator
class Enemy: public PhysicsObject
{
public:
	Enemy(const Vector2D& position, xyVector scale, GraphicObject enemyGraphic, double colliderSize, double shootDelay,
									const std::shared_ptr<MovableInterface>& moveComp, const std::shared_ptr<ShootInterface>& shootComp);
	virtual void Start() override; 
	// Override Function from GameObject 
	virtual void Update() override;
	// Override function from PhysicsObject
    virtual void collisionAction(GameObjectType objectType) override;
	void AssignEnemyController(const std::shared_ptr<GameObject>& enemyController);
private:
	// Shoot function used to instantiate enemy bullets
	void Shoot();
	// Checks if the enemy is outside of the screen bounds
	void CheckOutsideScreen();
	// delay used between each shot per object
	DelayComponent _shootDelay;
	std::shared_ptr<ShootInterface> _enemyShoot;
	// Boundary object used to detect when the object is outside the screen
	Boundary _screenBounds;
	SizeReduction _sizeReduction;
	std::shared_ptr<MovableInterface> _moveComp;
	void InitialiseObject();
	Vector2D GenerateRandomMoveDirection();
	std::shared_ptr<EnemyController> _enemyController;
	// object response to colliding with a player bullet 
	void PlayerProjectileCollision();
};


#endif 