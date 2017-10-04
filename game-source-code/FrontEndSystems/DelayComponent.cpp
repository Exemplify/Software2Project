#include "DelayComponent.h"
#include "../BackEndSystems/GameTime.h"

// constructs the delay component from the provided values
DelayComponent::DelayComponent(double value, bool immediateUse):
_currentValue{value},
_delayValue{value},
_delayFinished{immediateUse}
{}

// Checks if the delay is complete
bool DelayComponent::DelayFinished()
{
	return _delayFinished;
}
// Reduces the time until the delay is finished
void DelayComponent::reduceTime()
{
	_currentValue -= GameTime::getDeltaTime();
	if(_currentValue <= 0)
		_delayFinished = true;
}
// Resets the delay to its original value
/// should and a default argument that can be changed to change the delay rate
void DelayComponent::resetDelay()
{
	_currentValue = _delayValue;
	_delayFinished = false;
}