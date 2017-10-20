#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "../Vector2D.h"

class MovableInterface
{
public:
	MovableInterface(double moveSpeed):
	_movespeed{moveSpeed},
	_direction{Vector2D::right}
	{}
	virtual void Move(Vector2D& currentPosition) = 0;
	void setDirection(const Vector2D& direction) {_direction = direction;}
	
	virtual ~MovableInterface() = default;
protected:
	double _movespeed;
	Vector2D _direction;
};

#endif