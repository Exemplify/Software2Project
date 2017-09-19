#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/Time.h"

int const MAX_DEGREES = 360;
double const RAD_2_DEG = 3.141592653589793/180.0;
const int PLAY_SCREEN_WIDTH = ;
const int HALF_SCREEN = 540;

void Enemy::Update()
{
	Move();
}
void Enemy::Start()
{
	Initialise();
}
void Enemy::Initialise()
{
	double angle = rand()%MAX_DEGREES;
	angle*=RAD_2_DEG;
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
	if(curPos[0] > ,   curPos[1])
}


