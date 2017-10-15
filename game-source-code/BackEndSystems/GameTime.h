#ifndef TIME_H
#define TIME_H
#include <ctime>
#include <cstdlib>

class GameTime
{
public:
	GameTime()
	{
		srand(time(NULL));
	}
	static double getDeltaTime();
	
	/// should make this a friend method rather than a friend class
	void TimeFrame();
private:

	// Calculates the current total process time
	double calcProcessTime();
	// Calcualtes the current delta time  
	void calcDeltaTime();
	// Calculates the current time for the frame
	void calcCurrentTime();
	//  function that us called from game manager

	// Variables
	// current time up till the current frame
	static double _current_time;
	// change in time between frames
	static double _deltaTime;
};

#endif