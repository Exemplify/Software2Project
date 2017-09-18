#ifndef TIME_H
#define TIME_H
#include <ctime>
#include "GameManager.h"

class GameTime
{
	friend class GameManager;
public:
	static double getDeltaTime();
private:
	// Methods
	double calcProcessTime();
	void calcDeltaTime();
	void calcCurrentTime();
	void TimeFrame();
	// Variables
	static double _current_time;
	static double _deltaTime;
};

#endif