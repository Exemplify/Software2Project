#include "DelayComponent.h"
#include "../BackEndSystems/GameTime.h"


DelayComponent::DelayComponent(double value, bool immediateUse):
_currentValue{value},
_delayValue{value},
_delayFinished{immediateUse}
{}

bool DelayComponent::DelayFinished()
{
	return _delayFinished;
}

void DelayComponent::reduceTime()
{
	_currentValue -= GameTime::getDeltaTime();
	if(_currentValue <= 0)
		_delayFinished = true;
}

void DelayComponent::resetDelay()
{
	_currentValue = _delayValue;
	_delayFinished = false;
}