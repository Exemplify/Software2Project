#include "DelayComponent.h"
#include "../BackEndSystems/GameTime.h"


DelayComponent::DelayComponent(double value, bool immediateUse):
_currentValue{value},
_delayValue{value},
_delayFinished{immediateUse}
{}
// Again, what is the immediate use flag for.
// follow-up immidiate use is a default to false, if true the delay is autoflagged to true, this then needs to be reset by the function call resetDelay? 
/// Delay is a tricky class, but i found myself repeating the code a lot within the enemy spwaner and the shoot class so its main purpose is to 
/// ensure that it is easy to implement a delay but it does put responsibility on the client to reset the delay once they have checked the delay condition
/// Immediate use is so that there is no delay apon construction in the example of the player they must be able to shoot immediately after construction rather 
/// than having to wait the allocated delay time, or as an alternative example the enemy spawner if we wanted enemies to spawn immediatley rather than wait 2 seconds then spawn.

bool DelayComponent::DelayFinished()
{
	return _delayFinished;
}
// understandably returns true based on if a delay is completed
/// Yes.

void DelayComponent::reduceTime()
{
	_currentValue -= GameTime::getDeltaTime();
	if(_currentValue <= 0)
		_delayFinished = true;
}
// So this implements the timing mechanism?
/// yes.

void DelayComponent::resetDelay()
{
	_currentValue = _delayValue;
	_delayFinished = false;
}

// in conjunction with the GameTime class is there a more genral and intuitive timing mechanism (e.g. the timer in Lab2)?
/// Maybe, im not sure just used to doing this from game design, this is dependant on each frame of the game and i feel like that is valuable its like a discrete timer vs continuous, 
/// the game space is discrete and should therefor use the timer that corresponds to its state.