#include "Boundary.h"

const unsigned int DEFAULT_WIDTH = 1920;
const unsigned int DEFAULT_HEIGHT = 1080;
// default boundary is set to the screen bounds 
Boundary::Boundary()
{
	_xBound = DEFAULT_HEIGHT/2;
	_yBound = DEFAULT_HEIGHT/2;
}
// constructor that uses the defined bounds for the boundary
Boundary::Boundary(double xbound, double ybound):
_xBound{xbound},
_yBound{ybound}
{}

bool Boundary::OutOfBounds(const Vector2D& objectPosition) const
{
	// obtains the x and y components for the positions
	auto positonVect = objectPosition.getXYVector();
	// Checks if either of the positions are out of bounds
	if(CheckxOutofBounds(positonVect.x) || CheckyOutofBounds(positonVect.y))
		return true;
	else
		return false;
}
bool Boundary::insideOfBounds(const Vector2D& objectPosition) const
{
	return !OutOfBounds(objectPosition);
}

bool Boundary::CheckxOutofBounds(double xPos) const
{
	// compares the xPosition to the x boundaries 
	if(xPos > _xBound || xPos < -_xBound)
		return true;
	else
		return false;
}
bool Boundary::CheckyOutofBounds(double yPos) const
{
	// compares the y position to the y boundaries
	if(yPos > _yBound || yPos < -_yBound)
		return true;
	else
		return false;
}