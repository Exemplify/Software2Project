#ifndef SCREEN_BOUND_H
#define SCREEN_BOUND_H
#include "../Vector2D.hpp"

// Default for bounds is the Screen boundary
const int PLAY_SCREEN_HALF_WIDTH = 960;
const int PLAY_SCREEN_HALF_HEIGHT = 700;

class Boundary
{
public: 
	Boundary()
	{
		_xBound = PLAY_SCREEN_HALF_WIDTH;
		_yBound = PLAY_SCREEN_HALF_HEIGHT;
	}
	Boundary(double xbound, double ybound):
	_xBound{xbound},
	_yBound{ybound}
	{}
	bool OutOfBounds(const Vector2D<double>& objectPosition) const;
	bool insideOfBounds(const Vector2D<double>& objectPosition) const;
private:
	bool CheckyOutofBounds(double yPos) const;
	bool CheckxOutofBounds(double xPos) const;
	double _xBound;
	double _yBound;
};
#endif