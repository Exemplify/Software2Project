#include "Player.h"

Player::Player(Vector2D<double>& startPosition):
_leftUnitVector{1, -1*M_PI/100000, 0, VectorType::rtp},
_rightUnitVector{1, M_PI/100000, 0, VectorType::rtp}
{
    _position = startPosition;
}

void Player::moveLeft()
{
    _position*=_leftUnitVector;
}

void Player::moveRight()
{
    _position*=_rightUnitVector;
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