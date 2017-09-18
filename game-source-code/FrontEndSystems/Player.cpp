#include "Player.h"
#include "../BackEndSystems/Time.h"

Player::Player(Vector2D<double>& startPosition):
_leftUnitVector{1, -M_PI, 0, VectorType::rtp},
_rightUnitVector{1, M_PI, 0, VectorType::rtp}
{
    _position = startPosition;
}

void Player::moveLeft()
{
	auto curPos = _position.rtpVector();
	curPos[1] -= GameTime::getDeltaTime() * _movespeed;
	Vector2D<double> newPos{curPos[0], curPos[1], curPos[2], VectorType::rtp};
    _position = newPos;
}

void Player::moveRight()
{
	auto curPos = _position.rtpVector();
	curPos[1] += GameTime::getDeltaTime() * _movespeed;
	Vector2D<double> newPos{curPos[0], curPos[1], curPos[2], VectorType::rtp};
    _position = newPos;
}

void Player::Update()
{
    if(Input::IsButtonPressed(Keys::left))
        moveLeft();
    if(Input::IsButtonPressed(Keys::right))
        moveRight();
}

void Player::TestMoveLeft()
{
    _position*=_leftUnitVector;
}

void Player::TestMoveRight()
{
    _position*=_rightUnitVector;
}