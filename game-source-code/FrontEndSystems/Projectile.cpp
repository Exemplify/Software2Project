#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/GameManager.h"
#include <memory>


Projectile::Projectile(std::shared_ptr<SpriteInfo> spriteInfo, GameObjectType projectileType):
PhysicsObject(),
_enemyDestroyBounds{},
_playerDestroyBounds{PLAYER_PROJECTILE_DESTROY_REGION, PLAYER_PROJECTILE_DESTROY_REGION}
{
	_type = projectileType;
    _spriteInfo = spriteInfo;
    _objectSize = 5;
}

Projectile::Projectile(const Projectile& copyProjectile):
PhysicsObject()
{
	_enemyDestroyBounds = copyProjectile._enemyDestroyBounds;
	_playerDestroyBounds = copyProjectile._playerDestroyBounds;
	_spriteInfo = copyProjectile._spriteInfo;
	_type = copyProjectile._type;
    _objectSize = copyProjectile._objectSize;
}
void Projectile::Update()
{
	Move();
	DestroySelf();
}
void Projectile::Move()
{
	_position += _direction * _moveSpeed * GameTime::getDeltaTime();
}
void Projectile::DestroySelf()
{
	if(_type == GameObjectType::playerBullet)
 		DestroyPlayerProjectile();
	else
		DestroyEnemyProjectile();
}
void Projectile::DestroyPlayerProjectile()
{
	if(_playerDestroyBounds.insideOfBounds(_position))
	{
		Destroy();
	}
}
void Projectile::DestroyEnemyProjectile()
{
	if(_enemyDestroyBounds.OutOfBounds(_position))
	{
		Destroy();
	}
}
void Projectile::Initialise(Vector2D<double> startingPos, Vector2D<double> direction, double moveSpeed)
{
	_position = startingPos;
	_direction = direction;
	_moveSpeed = moveSpeed;
}

void Projectile::collisionAction(GameObjectType objectType)
{
    if(_type != objectType && (objectType == GameObjectType::enemyBullet || objectType == GameObjectType::playerBullet))
        Destroy();
    else if(objectType == GameObjectType::enemy && _type == GameObjectType::playerBullet)
        Destroy();
    else if(objectType == GameObjectType::player && _type == GameObjectType::enemyBullet)
        Destroy();
}