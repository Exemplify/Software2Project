#ifndef PROJ_H
#define PROJ_H
#include "PhysicsObject.h"
#include "MovableInterface.h"
#include "SizeReduction.h"
#include "Boundary.h"

class Projectile: public PhysicsObject
{
public:
	// constructor used to identify whether the gameobject type is an enemy projectile or a player projectile 
	// with the corresponding graphical information
	Projectile(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, const double& colliderSize, const Boundary& destroyBounds;
	// Overrides Update function for specific responsibilities 
	virtual void Update() override;
	// used to define the characteristics of the projectile once is has been created by the copy constructor
	// this is necessary because the start position of each projectile is always changing
	void Initialise(const Vector2D& startingPos, const Vector2D& direction);
	// Override function used to determine when a collision has occured with the specific object types
    virtual void collisionAction(GameObjectType objectType) override;
	// virtual Destructor
	virtual ~Projectile() override{}
protected:
	virtual void DestroySelf() = 0;
private:
	Boundary _destroyBounds;
	// projectile movement speed
	std::shared_ptr<MovableInterface> _moveComp;
	SizeReduction _sizeReduction;
	void Move();
	void DestroyProjectile();
};

#endif
