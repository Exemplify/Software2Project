#include "Boundary.h"

bool Boundary::OutOfBounds(const Vector2D<double>& objectPosition) const
{
	auto positonVect = objectPosition.xypVector();
	if(CheckxOutofBounds(positonVect.at(0)) || CheckyOutofBounds(positonVect.at(1)))
		return true;
	else
		return false;
}
bool Boundary::insideOfBounds(const Vector2D<double>& objectPosition) const
{
	auto positonVect = objectPosition.xypVector();
	if(!CheckxOutofBounds(positonVect.at(0)) && !CheckyOutofBounds(positonVect.at(1)))
		return true;
	else
		return false;
}

bool Boundary::CheckxOutofBounds(double xPos) const
{
	if(xPos > _xBound || xPos < -_xBound)
		return true;
	else
		return false;
}
bool Boundary::CheckyOutofBounds(double yPos) const
{
	if(yPos > _yBound || yPos < -_yBound)
		return true;
	else
		return false;
}