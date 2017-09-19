#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/Time.h"

int const MAX_DEGREES = 360;
double const RAD_2_DEG = 3.141592653589793/180.0;
const int PLAY_SCREEN_HALF_WIDTH = 1200;
const int PLAY_SCREEN_HALF_HEIGHT = 700;

void Enemy::Update()
{
	Move();
	CheckOutsideScreen();
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
	if(CheckxOutofBounds(curPos[0]) || CheckyOutofBounds(curPos[1]))
	{
		Initialise();
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

