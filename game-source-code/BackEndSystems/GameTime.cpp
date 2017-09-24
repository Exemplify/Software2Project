#include "GameTime.h"

double GameTime::_current_time = 0;
//default time for performing tests
double GameTime::_deltaTime = 1;

double GameTime::calcProcessTime()
{
	auto time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}

void GameTime::calcDeltaTime()
{
	_deltaTime = calcProcessTime() - _current_time;
}
// would it not be more intuitive to call _current_time => _stored_time or _set_sime. Since _current_time is ambiguous
// given that calcProcesTime actually gets the real current time and "_current_time" is a stored earlier instance of time.

void GameTime::calcCurrentTime()
{
	_current_time = calcProcessTime();
}
// again consider a more descriptive/ intuitive name (refere to above comment)

double GameTime::getDeltaTime()
{
	return _deltaTime;
}
// is it therefore necessary to store the _deltaTime value privately?

void GameTime::TimeFrame()
{
	calcDeltaTime();
	calcCurrentTime();
}
// what exactly is this useful for, does it justify the use of the above functions?