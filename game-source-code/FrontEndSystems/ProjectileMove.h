#ifndef PROJ_MOVE_H
#define PROJ_MOVE_H
#include "MovableInterface.h"
#include "../BackEndSystems/GameTime.h"

class ProjectileMove: public MovableInterface
{
public:
	ProjectileMove(double moveSpeed):
	MovableInterface(moveSpeed)
	{}
	void Move(Vector2D& currentPosition) override
	{
		currentPosition += _direction *_movespeed *GameTime::getDeltaTime();
	}
	void setDirection(const Vector2D& direction){  _direction = direction;}
	virtual ~ProjectileMove() = default;
protected:
	Vector2D _direction;
};

#endif 