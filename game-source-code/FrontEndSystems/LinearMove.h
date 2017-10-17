#ifndef LIN_MOVE_H
#define LIN_MOVE_H
#include "MovableInterface.h"
#include "../BackEndSystems/GameTime.h"

class LinearMove: public MovableInterface
{
public:
	LinearMove(double moveSpeed):
	MovableInterface(moveSpeed)
	{}
	void Move(Vector2D& currentPosition) override;
	virtual ~LinearMove() = default;

};

#endif 