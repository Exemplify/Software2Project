#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/GameTime.h"


const double ENEMY_SHOOT_DELAY = 3; 
const auto DEG_2_RAD = 3.141592653589793/180.0;

Enemy::Enemy():
_shootDelay{ENEMY_SHOOT_DELAY, false}
{
	ConstructSpriteInfo();
		InitialiseObject();
}
void Enemy::ConstructSpriteInfo()
{
	_spriteInfo->textureLocation = "resources/AdamHabib.png";
	_spriteInfo->scale = sf::Vector2f{0.25f,0.25f};

	
	auto bulletSpriteInfo = std::make_shared<SpriteInfo>();
	bulletSpriteInfo->textureLocation = "resources/SouthAfricanPS.png";
	bulletSpriteInfo->scale = Vector2f(0.1f,0.1f);
	_enemyShoot = ShootComponent(bulletSpriteInfo, GameObjectType::enemyBullet);
}

void Enemy::Update()
{
	Move();
	Shoot();
	CheckOutsideScreen();
}

void Enemy::InitialiseObject()
{
	
	const auto MAX_MOVEMENT_RAND_VALUE = 100;
	auto randVal = rand();

	InitialiseMovementType(randVal%MAX_MOVEMENT_RAND_VALUE);
	InitialiseStartingPosition();
}

void Enemy::InitialiseMovementType(const int& randomChanceValue)
{
	// Probability Ranges for the different Movement Types
	const auto SPIRAL_MOVE_CHANCE = 30;
	const auto BASIC_MOVE_CHANCE = 50;
	
	// Tempory to ensure plain movement is working first
	if(randomChanceValue > BASIC_MOVE_CHANCE)
	{
		_movementType = EnemyMoveType::linear;
	}
	else if(randomChanceValue >SPIRAL_MOVE_CHANCE)
	{
		_movementType = EnemyMoveType::spiral;
	}
	else // PARABOLIC_MOVE_CHANCE = 20%
	{
		_movementType = EnemyMoveType::parabolic;
	}
}

// initialises the starting position based off of the various movement types
void Enemy::InitialiseStartingPosition()
{
	auto randomAngle = GenerateRandomAngle();
	switch(_movementType)
	{
		case EnemyMoveType::linear:
			InitialiseLinearMovement(randomAngle);
		break;
		case EnemyMoveType::spiral:
			InitialiseSpiralMovement(randomAngle);
			break;
		case EnemyMoveType::parabolic:
			InitialiseParabolicMovement();
		break;
		default:
		break;
	}
}

void Enemy::InitialiseLinearMovement(const double& angle)
{
	const auto PLAYER_LINEAR_MOVE_SPEED = 100;
	Vector2D<double> startPos{1, angle, 0, VectorType::rtp};
	_position = startPos;
	_enemyStats.setMoveSpeed(PLAYER_LINEAR_MOVE_SPEED);
}

void Enemy::InitialiseSpiralMovement(const double& angle)
{
	Vector2D<double> startPos{1, angle, 0, VectorType::rtp};
	_position = startPos;
	
}
void Enemy::InitialiseParabolicMovement()
{
	Vector2D<double> startPos{-400, -400, 0, VectorType::xyp};
	_position = startPos;
}

double Enemy::GenerateRandomAngle()
{
	const auto MAX_DEGREE_RAND_VALUE = 360;

	// Generates the random start angle
	auto angle = static_cast<double>(rand()%MAX_DEGREE_RAND_VALUE);
	angle*=DEG_2_RAD;
	return angle;
}
void Enemy::Move()
{
	switch(_movementType)
	{
		case EnemyMoveType::linear:
			LinearMove();
		break;
		case EnemyMoveType::spiral:
			SpiralMove();
			break;
		case EnemyMoveType::parabolic:
			ParabolicMove();
			break;
		default:
		break;
	}
}

void Enemy::CheckOutsideScreen()
{
	if(_screenBounds.OutOfBounds(_position))
	{
		InitialiseObject();
	}
}

void Enemy::Shoot()
{
	const double SHOOTSPEED = 200;
	_shootDelay.reduceTime();
	if(_shootDelay.DelayFinished())
	{
		_shootDelay.resetDelay();
		auto target = _position.rtpVector();
		target[0] += 1;
		Vector2D<double> targetVec{target, VectorType::rtp};
		_enemyShoot.Shoot(targetVec, _position, SHOOTSPEED, *_scene);
	}
}

void Enemy::LinearMove()
{
	auto curPos = getPosition().rtpVector();
	curPos[0] += _enemyStats.getMoveSpeed() * GameTime::getDeltaTime();
	Vector2D<double> newPos{curPos, VectorType::rtp};
	_position = newPos;
}
void Enemy::SpiralMove()
{
	auto PLAYER_ANGULAR_MOVEMENT_SPEED = 180*DEG_2_RAD;
	auto PLAYER_RADIAL_MOVEMENT_SPEED = 10;

	
	auto curPos = getPosition().rtpVector();
	curPos[0] += PLAYER_RADIAL_MOVEMENT_SPEED * GameTime::getDeltaTime();
	//PLAYER_ANGULAR_MOVEMENT_SPEED/=(2*3.141592*curPos[0]);
	curPos[1] += PLAYER_ANGULAR_MOVEMENT_SPEED* GameTime::getDeltaTime();
	Vector2D<double> newPos{curPos, VectorType::rtp};
	
	_position = newPos;
}
void Enemy::ParabolicMove()
{
	const auto parabolic_a = -0.002824019;
	double moveSpeed = 100;
	auto curPos = getPosition().xypVector();
	curPos[0] += moveSpeed * GameTime::getDeltaTime();
	curPos[1] = parabolic_a * pow(curPos[0],2);
	_position = Vector2D<double>(curPos);
}


