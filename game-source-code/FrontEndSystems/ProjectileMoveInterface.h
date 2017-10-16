#ifndef PROJ_MOVE_INTER_H
#define PROJ_MOVE_INTER_H
#include "MovableInterface.h"


class ProjectileMoveInterface : public MovableInterface
{
public:
	void setDirection(const Vector2D& direction)
	{ 
		_direction = direction
	}
protected:
	Vector2D _direction;
}

#endif