#include "SpiralMove.h"
#include "../BackEndSystems/GameTime.h"

SpiralMove::SpiralMove(const double& radialSpeed, const double& angularSpeed):
MovableInterface{radialSpeed},
_angularSpeed{angularSpeed}
{}

void SpiralMove::Move(Vector2D& currentPosition)
{
	auto curPos = currentPosition.getRTVector();
	curPos.r += _movespeed * GameTime::getDeltaTime();
	curPos.t += _angularSpeed* GameTime::getDeltaTime();
	currentPosition = Vector2D{curPos};
}