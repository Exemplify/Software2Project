#include "DelayComponent.h"
#include "../BackEndSystems/GameTime.h"

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