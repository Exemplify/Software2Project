#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/GameManager.h"
#include <memory>


Projectile::Projectile(std::shared_ptr<SpriteInfo> spriteInfo, GameObjectType projectileType):
GraphicObject(spriteInfo)
{
	_type = projectileType;
}
Projectile::Projectile(const Projectile& copyProjectile):
GraphicObject()
{
	_spriteInfo = copyProjectile.getSpriteInfo();
	_type = copyProjectile.getType();
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
	if(_position.magnitude(_position) < PROJECTILE_DESTROY_REGION)
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
