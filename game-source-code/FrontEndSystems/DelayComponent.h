#ifndef DEL_COMP_H
#define DEL_COMP_H

// DelayComponent is a composition class which is used to prevent the repetition of code it is used by the game logic whenever a delay is
// required, this includes firing rates and enemy spawning. this delay should only be attached to GameObjects or the derivatives of the GameObjects
// reduceTime should only be called from inside an Update function call.

/**
 * @class DelayComponent
 * @file DelayComponent.h
 * @brief DelayComponent is used to create and manage all delays for the game logic, it uses the delta time value stored within the GameTime class.
 */
class DelayComponent
{
public:
	/**
	 * @brief Constructor: Creates a delay component that uses the specific time value provided
	 * @param value The specific time value that represent the length of the delay until it is finished
	 * @param InitialUseBeforeDelay Allows the client to set whether the delay is initially true until use
	 * @return 
	 */
	DelayComponent(double value, bool InitialUseBeforeDelay = false);
	/**
	 * @brief reduces the delay value and then checks if it is finished
	 * @return Returns true if the delay is finished
	 */
	bool DelayFinished();
	/**
	 * @brief Resets the delay to original value
	 */
	void resetDelay();
	
private:
	 
	double _currentValue; /**<The current value of time until the delay is finished*/
	
	double _delayValue; /**<The original value of the delay*/
	
	bool _delayFinished; /**<The boolean stored for whether the delay has finished*/
	
	void reduceTime(); /**<Reduces the delay time by GameTime deltaTime, is called by DelayFinished*/
};

#endif