#include "ParabolicMove.h"
#include "../BackEndSystems/GameTime.h"

ParabolicMove::ParabolicMove(const double& movespeed,const double& parabolic_coefficient):
MovableInterface(movespeed),
_parabolic_coefficient{parabolic_coefficient}
{
	_movespeed = movespeed;
}

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
	return Vector2D::magnitude(position) < 15? _movespeed/10 : _movespeed;
}