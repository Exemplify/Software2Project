#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/GameManager.h"
#include <memory>


Projectile::Projectile(std::shared_ptr<SpriteInfo> spriteInfo, GameObjectType projectileType):
GraphicObject(spriteInfo),
_enemyDestroyBounds{},
_playerDestroyBounds{PLAYER_PROJECTILE_DESTROY_REGION, PLAYER_PROJECTILE_DESTROY_REGION}
// What is this and why is it necessary?
/// Enemy Destroy Bounds and Player Destroy bounds is the region in which the projectile destroys itself when it moves into that 
/// region depending on which object type it is
{
	_type = projectileType;
}
Projectile::Projectile(const Projectile& copyProjectile):
GraphicObject()
{
	_enemyDestroyBounds = copyProjectile._enemyDestroyBounds;
	_playerDestroyBounds = copyProjectile._playerDestroyBounds;
	_spriteInfo = copyProjectile._spriteInfo;
	_type = copyProjectile._type;
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
// Happy with this implementation, but where has _moveSpeed been defined?
/// _movespeed and direction is defined by the Initialise function, this is done so that the copy constructor can be cloned and then the game 
/// information is applied to it to tell it where to move to and how fast it can move.
void Projectile::DestroySelf()
{
	if(_type == GameObjectType::playerBullet)
 		DestroyPlayerProjectile();
	else
		DestroyEnemyProjectile();
}
// This function seems to check it this object is of type playerBullet or enemyBullet and destroys itself.
// is it not more intuitive to have this defined in the Projectile class itself and call it from the projectile functionality
// rather that checking in which state it belongs and then destroying it.
// Further, this implementation suggests that the player/enemy has knowledge about the projectile functionality; should it.
// would it not be easier to shift this responsiblity onto the projectile itself? can this not be done in a way that can prevent
// the necessary projectiles from destroying eachother?
/// this is the projectile class?? and it does ensure that only the projectile can destroy itself

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
