#include "GameTime.h"

double GameTime::_current_time = 0;
double GameTime::_deltaTime = 0;

double GameTime::calcProcessTime()
{
	auto time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}
void GameTime::calcDeltaTime()
{
	_deltaTime = calcProcessTime() - _current_time;
}
void GameTime::calcCurrentTime()
{
	_current_time = calcProcessTime();
}
double GameTime::getDeltaTime()
{
	return _deltaTime;
}
void GameTime::TimeFrame()
{
	calcDeltaTime();
	calcCurrentTime();
}
