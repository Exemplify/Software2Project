#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/GameTime.h"


const int MAX_DEGREES = 360;
const double DEG_2_RAD = 3.141592653589793/180.0;
const double ENEMY_SHOOT_DELAY = 2; 
const double thetaToRadiusMovementRatio = 0.5;

Enemy::Enemy(Character enem, GameObjectType enemytype):
_shootDelay{ENEMY_SHOOT_DELAY, true},
_enemyStats{enem}
{
	_spriteInfo->textureLocation = "resources/AdamHabib.png";
	_spriteInfo->scale = sf::Vector2f{0.25f,0.25f};
	InitialisePosition();
	
	auto bulletSpriteInfo = std::make_shared<SpriteInfo>();
	bulletSpriteInfo->textureLocation = "resources/SouthAfricanPS.png";
	bulletSpriteInfo->scale = Vector2f(0.1f,0.1f);
	_enemyShoot = ShootComponent(bulletSpriteInfo, GameObjectType::enemyBullet);
	_type = enemytype;
	
	Enemy2Direction();
}

void Enemy::Enemy2Direction()
{
	auto randDir = rand()%50;
	if(randDir > 25)
		_direction = 1;
	else
		_direction = -1;
	
}
void Enemy::Update()
{
	Move();
	Shoot();
	CheckOutsideScreen();
	
}
void Enemy::InitialisePosition()
{
	double angle = rand()%MAX_DEGREES;
	angle*=DEG_2_RAD;
	Vector2D<double> startPos{1, angle, 0, VectorType::rtp};
	_position = startPos;
}
void Enemy::Move()
{
	// If enemy is of type 1 or type 2 it performs a different movement type;
	if(_type == GameObjectType::enemy1)
		BasicMove();
	else
		ComplexMove();
}

void Enemy::CheckOutsideScreen()
{
	if(_screenBounds.OutOfBounds(_position))
	{
		InitialisePosition();
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

void Enemy::BasicMove()
{
	auto curPos = getPosition().rtpVector();
	curPos[0] += _enemyStats.getMoveSpeed() * GameTime::getDeltaTime();
	Vector2D<double> newPos{curPos, VectorType::rtp};
	_position = newPos;
}
void Enemy::ComplexMove()
{
	auto deltaTime = GameTime::getDeltaTime();
	auto deltaTheta = _enemyStats.getMoveSpeed()*deltaTime*_direction;
	auto deltaRadius = 1 +1*deltaTime;
	
	Vector2D<double> changeInPosition(deltaRadius, deltaTheta, 0, VectorType::rtp);
	_position *= changeInPosition;
}


