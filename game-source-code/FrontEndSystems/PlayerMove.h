#ifndef PLAYER_MOVE_H
#define PLAYER_MOVE_H
#include "MovableInterface.h"

class PlayerMove : public MovableInterface
{
public:
	PlayerMove(double moveSpeed);
	virtual void Move(Vector2D& currentPosition) override;

private:
	int determineMoveDirection();
};

#endif