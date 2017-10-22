#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/GameTime.h"
#include "EnemyController.h"
#include <assert.h>


const double DEG_2_RAD = 3.141592653589793f/180.0f;
const double MAX_DISTANCE = 450; 

Enemy::Enemy(const PhysicsObject& physicsObject, const double& shootDelay,
			const std::shared_ptr<MovableInterface>& moveComp, const std::shared_ptr<ShootInterface>& shootComp):
PhysicsObject{physicsObject},
_shootDelay{shootDelay},
_enemyShoot{shootComp},
_screenBounds{},
_sizeReduction{MAX_DISTANCE, _scale, _objectSize},
_moveComp{moveComp}
{
	_type = GameObjectType::enemy;
}

void Enemy::Start()
{
	auto randomDirec = GenerateRandomMoveDirection();
	_moveComp->setDirection(randomDirec);
}
void Enemy::Update()
{
	_moveComp->Move(_position);
	Shoot();
	CheckOutsideScreen();
	_sizeReduction.ReduceSize(_position, _scale, _objectSize);
}

void Enemy::AssignEnemyController(const std::shared_ptr<GameObject>& enemyController)
{
	_enemyController = std::dynamic_pointer_cast<EnemyController>(enemyController);
	assert(_enemyController != nullptr);
}
Vector2D Enemy::GenerateRandomMoveDirection()
{
	const auto MAX_DEGREE_RAND_VALUE = 360;
	auto angle = static_cast<double>(rand()%MAX_DEGREE_RAND_VALUE);
	angle*=DEG_2_RAD;
	return Vector2D(1, angle, VectorType::rt);
}


void Enemy::CheckOutsideScreen()
{
	if(_screenBounds.OutOfBounds(_position))
	{
		_enemyController->EnemyOutofBounds();
		Destroy();
	}
}

void Enemy::Shoot()
{
	if(_shootDelay.DelayFinished())
	{
		_shootDelay.resetDelay();
		auto target = _position.getRTVector();
		target.r += 1;
		Vector2D targetVec{target};
		_enemyShoot->Shoot(_position , targetVec, _scene);
	}
}

// Function override from PhysicsObject, called by CollisionDetection
void Enemy::collisionAction(const GameObjectType& objectType)
{
	// Checks if object is either the player or the players projectile
    if(objectType == GameObjectType::playerBullet || objectType == GameObjectType::player)
	{
		PlayerProjectileCollision();
	}
}
// collision function for when enemy object is destroyed
void Enemy::PlayerProjectileCollision()
{
	_enemyController->EnemyKilled();
	// Removes the current object from the scene
	Destroy();
}