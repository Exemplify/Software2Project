#ifndef PARABOLIC_MOVE_H
#define PARABOLIC_MOVE_H
#include "MovableInterface.h"


class ParabolicMove : public MovableInterface
{
public:
	ParabolicMove(const double& parabolic_coefficient, const double& movespeed);
	virtual void Move(Vector2D& currentPosition) override;
private:
	double _parabolic_coefficient;
	double MoveSpeed(const Vector2D& position);
};
#endif