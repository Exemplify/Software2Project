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
/// Yes would be better to call current instance but since the frame is usually a negligable time difference to the game logic
/// if the current time is desired it can use this value, however it is more accurate to use deltaTime to determine the passing of time 
/// from within the game logic itself

void GameTime::calcCurrentTime()
{
	_current_time = calcProcessTime();
}
// again consider a more descriptive/ intuitive name (refere to above comment)
/// Agreed just couldnt think of one

double GameTime::getDeltaTime()
{
	return _deltaTime;
}
// is it therefore necessary to store the _deltaTime value privately?
/// Yes because we do not want other objects except for game manager to have the ability to set _deltaTime

void GameTime::TimeFrame()
{
	calcDeltaTime();
	calcCurrentTime();
}
// what exactly is this useful for, does it justify the use of the above functions?
/// deltaTime is the amount of time that has passed between each frame this is very useful as it allows for the game logic to 
/// run delays and it "linearises" values between each frame. so if we want an object to move 100 pixels per second, by multiplying by deltaTime 
/// we are successfully able to get the corrsponding movement required for each frame so that the object moves smoothly with the variable time step size. 