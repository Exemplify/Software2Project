#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/GameTime.h"


const int MAX_DEGREES = 360;
const double DEG_2_RAD = 3.141592653589793/180.0;
const double ENEMY_SHOOT_DELAY = 2; 


Enemy::Enemy(Character enem):
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
	auto curPos = getPosition().rtpVector();
	curPos[0] += _enemyStats.getMoveSpeed() * GameTime::getDeltaTime();
	Vector2D<double> newPos{curPos, VectorType::rtp};
	_position = newPos;
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
	_shootDelay.reduceTime();
	if(_shootDelay.DelayFinished())
	{
		_shootDelay.resetDelay();
		auto target = _position.rtpVector();
		target[0] += 1;
		Vector2D<double> targetVec{target, VectorType::rtp};
		_enemyShoot.Shoot(targetVec, _position, 3*_enemyStats.getMoveSpeed(), *_scene);
	}
}


