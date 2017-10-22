#include "EnemyProjectile.h"

EnemyProjectile::EnemyProjectile( const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, const Boundary& destroyBounds):
Projectile(physicsObject, move, destroyBounds)
{
	_type = GameObjectType::enemyBullet;
}

void EnemyProjectile::DestroySelf()
{
	if(_destroyBounds.OutOfBounds(_position))
	{
		Destroy();
	}
}

void EnemyProjectile::collisionAction(const GameObjectType& objectType)
{
	if(objectType == GameObjectType::player || objectType == GameObjectType::playerBullet)
	{
		Destroy();
	}
}