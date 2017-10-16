#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "../Vector2D.h"

class MovableInterface
{
public:
	MovableInterface(double moveSpeed):
	_movespeed{moveSpeed}
	{}
	virtual void Move(Vector2D& currentPosition) = 0;
	virtual ~MovableInterface() = default;
protected:
	double _movespeed;
};

#endif