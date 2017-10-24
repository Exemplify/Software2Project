#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/GameManager.h"
#include <memory>
#include <assert.h>


Projectile::Projectile(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, const Boundary& destroyBounds):
PhysicsObject(physicsObject),
_destroyBounds{destroyBounds},
_moveComp{move},
_sizeReduction{_scale, _objectSize}
{}
void Projectile::Start()
{
	_sizeReduction.ReduceSize(_position, _scale, _objectSize);
}
void Projectile::Update()
{
	_moveComp->Move(_position);
	_sizeReduction.ReduceSize(_position, _scale, _objectSize);
	DestroySelf();
}

// Used to initialise the object after the copy constructor is run
// necessary because the starting position and direction vary frequently
void Projectile::Initialise(const Vector2D& startingPos, const Vector2D& direction)
{
	_position = startingPos;
	_moveComp->setDirection(direction);
}
