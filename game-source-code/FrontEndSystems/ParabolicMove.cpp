#include "ParabolicMove.h"
#include "../BackEndSystems/GameTime.h"

ParabolicMove::ParabolicMove(const double& parabolic_coefficient, const double& movespeed):
MovableInterface(movespeed),
_parabolic_coefficient{parabolic_coefficient}
{}

void ParabolicMove::Move(Vector2D& currentPosition)
{
	auto curPos = currentPosition.getXYVector();
	auto movespeed = MoveSpeed(currentPosition);
	curPos.x += movespeed * GameTime::getDeltaTime();
	curPos.y = _parabolic_coefficient * pow(curPos.x,2);
	currentPosition = Vector2D(curPos);
}

double ParabolicMove::MoveSpeed(const Vector2D& position)
{
	if(Vector2D::magnitude(position) > 100)
		return _movespeed/2;
	else
		return _movespeed;
}