#include "Boundary.h"

bool Boundary::OutOfBounds(const Vector2D<double>& objectPosition) const
{
	// obtains the x and y components for the positions
	auto positonVect = objectPosition.xypVector();
	// Checks if either of the positions are out of bounds
	if(CheckxOutofBounds(positonVect.at(0)) || CheckyOutofBounds(positonVect.at(1)))
		return true;
	else
		return false;
}
bool Boundary::insideOfBounds(const Vector2D<double>& objectPosition) const
{
	/// Replace with return !OutofBoounds (de morgans theorem)
	auto positonVect = objectPosition.xypVector();
	if(!CheckxOutofBounds(positonVect.at(0)) && !CheckyOutofBounds(positonVect.at(1)))
		return true;
	else
		return false;
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