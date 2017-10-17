#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/GameManager.h"
#include <memory>

const double max_distance = 450;
/// Constructor Needs a Database Dependency
Projectile::Projectile(GraphicObject bulletGraphic, GameObjectType projectileType, xyVector scale, std::shared_ptr<MovableInterface> move, double colliderSize):
PhysicsObject(),
_enemyDestroyBounds{},
_playerDestroyBounds{PLAYER_PROJECTILE_DESTROY_REGION, PLAYER_PROJECTILE_DESTROY_REGION},
_moveComp{move},
_sizeReduction{max_distance, scale, colliderSize}
{
	_scale = scale;
	_type = projectileType;
    _graphicObject = bulletGraphic;
    _objectSize = colliderSize;
}

void Projectile::Update()
{
	_moveComp->Move(_position);
	_sizeReduction.ReduceSize(_position, _scale, _objectSize);
	DestroySelf();
}

// Moves the projectile in a specific direction
/// Needs a moveable component
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
void Projectile::Initialise(const Vector2D& startingPos, const Vector2D& direction)
{
	_position = startingPos;
	_moveComp->setDirection(direction);
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