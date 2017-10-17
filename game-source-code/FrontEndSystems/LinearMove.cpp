#include "LinearMove.h"

void LinearMove::Move(Vector2D& currentPosition)
{
	currentPosition += _direction *_movespeed *GameTime::getDeltaTime();
}