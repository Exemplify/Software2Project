#include "PlayerMove.h"
#include "../BackEndSystems/Input.h"
#include "../BackEndSystems/GameTime.h"


PlayerMove::PlayerMove(double moveSpeed):
MovableInterface(moveSpeed)
{}

void PlayerMove::Move(Vector2D& currentPosition)
{
	auto curPos = currentPosition.getRTVector();
	curPos.t += GameTime::getDeltaTime() * _movespeed * determineMoveDirection();
	Vector2D newPos{curPos};
    currentPosition = newPos;
}

int PlayerMove::determineMoveDirection()
{
	return Input::getAxis(Axis::horizontal);
}