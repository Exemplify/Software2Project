#ifndef PROJ_H
#define PROJ_H
#include "GraphicObject.h"

class Projectile: public GraphicObject
{
public:
	Projectile(Vector2D<double> startingPos, Vector2D<double> direction, double moveSpeed);
	virtual void Update() override;

private:
	Vector2D<double> _direction;
	double _moveSpeed;
	void DestroySelf();
	void Move();
};

#endif
