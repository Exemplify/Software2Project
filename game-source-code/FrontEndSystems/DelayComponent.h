#ifndef DEL_COMP_H
#define DEL_COMP_H

// DelayComponent is a composition class which is used to prevent the repetition of code it is used by the game logic whenever a delay is
// required, this includes firing rates and enemy spawning. this delay should only be attached to GameObjects or the derivatives of the GameObjects
// reduceTime should only be called from inside an Update function call.

/// could require some rethinking because a lot of the responsibility is on the client to call the appropriate functions
/// Functions should be incorporated into one so that the client only needs to check if the delay has finished
class DelayComponent
{
public:
	// takes in a value for the delay time and immediate use which identifies whether 
	// the delayFinished check can be used immediately on initialisation or if the delay needs to complete first
	DelayComponent(double value, bool InitialUseBeforeDelay = false);
	// Returns true if the delay has finished
	bool DelayFinished();
	// resets the delay so to the original value
	void resetDelay();
	
private:
	// The current value of time until the delay is finished
	double _currentValue;
	// The original value of the delay
	double _delayValue;
	// the boolean stored for whether the delay has finished, used to allow immediateUse
	bool _delayFinished;
	// Reduces the delay time by deltaTime each time it is called
	void reduceTime();
};

#endif