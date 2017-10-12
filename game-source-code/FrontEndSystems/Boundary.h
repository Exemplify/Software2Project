#ifndef SCREEN_BOUND_H
#define SCREEN_BOUND_H
#include "../Vector2D.h"

// Default for bounds is the Screen boundary
/// should be pulled from a database
const int PLAY_SCREEN_HALF_WIDTH = 960;
const int PLAY_SCREEN_HALF_HEIGHT = 700;

// boundary class is checks if a Vector2D position is inside or outside specific box that is 
// centered at the origin
class Boundary
{
public: 
	// default boundary is set to the screen bounds 
	Boundary()
	{
		_xBound = PLAY_SCREEN_HALF_WIDTH;
		_yBound = PLAY_SCREEN_HALF_HEIGHT;
	}
	// constructor that uses the defined bounds for the boundary
	/// implementation of constructor should be moved to the cpp file
	Boundary(double xbound, double ybound):
	_xBound{xbound},
	_yBound{ybound}
	{}

	// returns true when a position is outside of boundary
	bool OutOfBounds(const Vector2D& objectPosition) const;
	// returns true when a position is inside of the boundary
	bool insideOfBounds(const Vector2D& objectPosition) const;
	
private:
	// Checks if y position is out of bounds
	bool CheckyOutofBounds(double yPos) const;
	// Checks if x position is out of bounds
	bool CheckxOutofBounds(double xPos) const;
	// the x and y boundary 
	double _xBound;
	double _yBound;
};
#endif