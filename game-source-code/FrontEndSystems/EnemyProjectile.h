#ifndef ENEMY_PROJ_H
#define ENEMY_PROJ_H
#include "Projectile.h"


class EnemyProjectile : public Projectile
{
public:
	EnemyProjectile(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, const Boundary& destroyBounds);
	virtual void DestroySelf() override; 
	virtual void collisionAction(const GameObjectType& objectType) override;
};


#endif