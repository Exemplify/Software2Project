#ifndef PROJ_H
#define PROJ_H
#include "PhysicsObject.h"
#include "MovableInterface.h"
#include "SizeReduction.h"
#include "Boundary.h"

/// needs to be moved into a database
const double PLAYER_PROJECTILE_DESTROY_REGION = 10;
/// Object needs to be converted into a polymorphic object, one for player and one for enemy with virtual destorys and boundaries
/// corresponds to the type information in a better way
class Projectile: public PhysicsObject
{
public:

	// constructor used to identify whether the gameobject type is an enemy projectile or a player projectile 
	// with the corresponding graphical information
	Projectile(GraphicObject bulletGraphic, GameObjectType projectileType, xyVector scale,  std::shared_ptr<MovableInterface> move, double colliderSize);
	// Overrides Update function for specific responsibilities 
	virtual void Update() override;
	// used to define the characteristics of the projectile once is has been created by the copy constructor
	// this is necessary because the start position of each projectile is always changing
	void Initialise(const Vector2D& startingPos, const Vector2D& direction);
	// Override function used to determine when a collision has occured with the specific object types
    virtual void collisionAction(GameObjectType objectType) override;
	// virtual Destructor
	virtual ~Projectile() override{}
private:
	// Projectile direction
	Vector2D _direction;
	/// Need to remove both boundaries, should be passed through the constructor redundant information
	Boundary _enemyDestroyBounds;
	Boundary _playerDestroyBounds;
	// projectile movement speed
	std::shared_ptr<MovableInterface> _moveComp;
	SizeReduction _sizeReduction;
	/// should be virtual 
	void DestroySelf();
	void Move();
	
	void DestroyPlayerProjectile();
	void DestroyEnemyProjectile();
};

#endif
