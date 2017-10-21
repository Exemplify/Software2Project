#ifndef SPIRAL_MOVE_H
#define SPIRAL_MOVE_H
#include "MovableInterface.h"
#include "../Vector2D.h"

class SpiralMove: public MovableInterface
{
public:
	SpiralMove(const double& radialSpeed, const double& angularSpeed);
	virtual void Move(Vector2D& currentPosition) override;
	virtual ~SpiralMove() {};
private:
	double _angularSpeed;
	
};
#endif