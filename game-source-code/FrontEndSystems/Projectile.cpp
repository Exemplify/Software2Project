#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/GameManager.h"
#include <memory>

/// Constructor Needs a Database Dependency
Projectile::Projectile(GraphicObject bulletGraphic, GameObjectType projectileType, xyVector scale):
PhysicsObject(),
_enemyDestroyBounds{},
_playerDestroyBounds{PLAYER_PROJECTILE_DESTROY_REGION, PLAYER_PROJECTILE_DESTROY_REGION}
{
	_scale = scale;
	_type = projectileType;
    _graphicObject = bulletGraphic;
    _objectSize = 5;
}
// copy constructor used to duplicate the basic player and enemy projectile stored in the shoot components
Projectile::Projectile(const Projectile& copyProjectile):
PhysicsObject()
{
	_enemyDestroyBounds = copyProjectile._enemyDestroyBounds;
	_playerDestroyBounds = copyProjectile._playerDestroyBounds;
	_graphicObject = copyProjectile._graphicObject;
	_type = copyProjectile._type;
	_scale = copyProjectile._scale;
    _objectSize = copyProjectile._objectSize;
}

void Projectile::Update()
{
	Move();
	DestroySelf();
}
// Moves the projectile in a specific direction
/// Needs a moveable component
void Projectile::Move()
{
	_position += _direction * _moveSpeed * GameTime::getDeltaTime();
}
/// Destroy Self needs to become virtual and then cascade responsibilities for each type down the tree
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
// Used to initialise the object after the copy constructor is run
// necessary because the starting position and direction vary frequently
void Projectile::Initialise(Vector2D<double> startingPos, Vector2D<double> direction, double moveSpeed)
{
	_position = startingPos;
	_direction = direction;
	_moveSpeed = moveSpeed;
}
// The different responses when colliding with a different object
/// polymorphism will reduce this complexity
void Projectile::collisionAction(GameObjectType objectType)
{
    if(_type != objectType && (objectType == GameObjectType::enemyBullet || objectType == GameObjectType::playerBullet))
        Destroy();
    else if(objectType == GameObjectType::enemy && _type == GameObjectType::playerBullet)
        Destroy();
    else if(objectType == GameObjectType::player && _type == GameObjectType::enemyBullet)
        Destroy();
}