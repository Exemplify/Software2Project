#ifndef TIME_H
#define TIME_H
#include <ctime>
#include <cstdlib>
/**
 * @class GameTime
 * @brief Determines the time that it takes for a single frame
 * @details Used to create smooth interactions between the Game logic and the BackEndSystems 
 */
class GameTime
{
public:
	/**
	 * @brief Constructs the GameTime object and seeds the random generator
	 */
	GameTime()
	{
		srand(time(NULL));
	}
	/**
	 * @brief Returns the difference in time between the last frame and the current frame
	 * @return Returns the difference in time between the last frame and the current frame
	 */
	static double getDeltaTime();
	
	/**
	 * @brief Times the current frame and determines the new delta time
	 */
	void TimeFrame();
private:

	/**
	 * @brief Determines the amount of time that has passes since the game began running, converts it into a double and returns the value
	 * @return Returns the amount of time that has passed since the game began
	 */
	double calcProcessTime();
	/**
	 * @brief Calculates the time between the current frame and the last frame
	 */
	void calcDeltaTime();
	/**
	 * @brief Calculates the time up until the current frame
	 */
	void calcCurrentTime();

	// Private Members

	static double _current_time; /**<current time up till the current frame*/

	static double _deltaTime;/**<change in time between frames*/
};

#endif