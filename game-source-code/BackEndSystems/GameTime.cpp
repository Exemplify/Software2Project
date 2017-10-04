#include "GameTime.h"


/// variables and names need to be changed to make it more understandable
double GameTime::_current_time = 0;
//default time for performing tests
double GameTime::_deltaTime = 1;

// calculates the current total process time
double GameTime::calcProcessTime()
{
	auto time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}
// calculates the how long the previous frame took
void GameTime::calcDeltaTime()
{
	_deltaTime = calcProcessTime() - _current_time;
}
// calculates the starting time for the current frame
void GameTime::calcCurrentTime()
{
	_current_time = calcProcessTime();
}
// returns the difference in frame time 
double GameTime::getDeltaTime()
{
	return _deltaTime;
}
// calculates the deltatime and the current time from gamemanager
void GameTime::TimeFrame()
{
	calcDeltaTime();
	calcCurrentTime();
}
