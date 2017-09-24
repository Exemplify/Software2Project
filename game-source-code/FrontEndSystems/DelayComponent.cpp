#include "DelayComponent.h"
#include "../BackEndSystems/GameTime.h"


DelayComponent::DelayComponent(double value, bool immediateUse):
_currentValue{value},
_delayValue{value},
_delayFinished{immediateUse}
{}
// Again, what is the immediate use flag for.
// follow-up immidiate use is a default to false, if true the delay is autoflagged to true, this then needs to be reset by the function call resetDelay? 

bool DelayComponent::DelayFinished()
{
	return _delayFinished;
}
// understandably returns true based on if a delay is completed

void DelayComponent::reduceTime()
{
	_currentValue -= GameTime::getDeltaTime();
	if(_currentValue <= 0)
		_delayFinished = true;
}
// So this implements the timing mechanism?

void DelayComponent::resetDelay()
{
	_currentValue = _delayValue;
	_delayFinished = false;
}

// in conjunction with the GameTime class is there a more genral and intuitive timing mechanism (e.g. the timer in Lab2)?