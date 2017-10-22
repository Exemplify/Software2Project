#include "PlayerProjectile.h"

PlayerProjectile::PlayerProjectile( const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, const Boundary& destroyBounds):
Projectile(physicsObject, move, destroyBounds)
{
	_type = GameObjectType::playerBullet;
}

void PlayerProjectile::DestroySelf()
{
	if(_destroyBounds.insideOfBounds(_position))
	{
		Destroy();
	}
}

void PlayerProjectile::collisionAction(const GameObjectType& objectType)
{
	if(objectType == GameObjectType::enemy || objectType == GameObjectType::enemyBullet)
	{
		Destroy();
	}
}

