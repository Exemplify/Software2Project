#ifndef PLAYER_PROJ_H
#define PLAYER_PROJ_H
#include "Projectile.h"


class PlayerProjectile : public Projectile
{
public:
	PlayerProjectile(const PhysicsObject& physicsObject,
					 const std::shared_ptr<MovableInterface>& move, 
					 const Boundary& destroyBounds);
	virtual void DestroySelf() override;
	virtual void collisionAction(const GameObjectType& objectType) override;
};


#endif