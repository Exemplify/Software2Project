#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/GameTime.h"

const int MAX_DEGREES = 360;
const double DEG_2_RAD = 3.141592653589793/180.0;
const int PLAY_SCREEN_HALF_WIDTH = 1200;
const int PLAY_SCREEN_HALF_HEIGHT = 700;
const double ENEMY_SHOOT_DELAY = 1; 


Enemy::Enemy(Character enem):
_shootDelay{ENEMY_SHOOT_DELAY},
_enemyStats{enem}
{
	_spriteInfo->textureLocation = "resources/AdamHabib.png";
	_spriteInfo->scale = sf::Vector2f{0.25f,0.25f};
	InitialisePosition();
	
}
void Enemy::Update()
{
	Move();
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
	auto curPos = getPosition().xypVector();
	if(CheckxOutofBounds(curPos[0]) || CheckyOutofBounds(curPos[1]))
	{
		InitialisePosition();
	}
}
bool Enemy::CheckxOutofBounds(double xPos)
{
	if(xPos <= -PLAY_SCREEN_HALF_WIDTH || xPos >= PLAY_SCREEN_HALF_WIDTH)
		return true;
	else
		return false;
}
bool Enemy::CheckyOutofBounds(double yPos)
{
	if(yPos <= -PLAY_SCREEN_HALF_HEIGHT || yPos >= PLAY_SCREEN_HALF_HEIGHT)
		return true;
	else
		return false;
}
void Enemy::Shoot()
{
	_shootDelay.reduceTime();
	if(_shootDelay.DelayFinished())
	{
		
	}
}


