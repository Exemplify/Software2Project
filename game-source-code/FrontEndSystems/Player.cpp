#include "Player.h"
#include "../BackEndSystems/Time.h"

Player::Player(Vector2D<double>& startPosition, Character playerStats):
_leftUnitVector{1, -M_PI, 0, VectorType::rtp},
_rightUnitVector{1, M_PI, 0, VectorType::rtp},
_playerStats{playerStats}
{
    _position = startPosition;
}

void Player::moveLeft()
{
}

void Player::moveRight()
{

}

void Player::Update()
{
	move();
}

void Player::TestMoveLeft()
{
    _position*=_leftUnitVector;
}

void Player::TestMoveRight()
{
    _position*=_rightUnitVector;
}
void Player::move()
{
	auto direc = Input::getAxis(Axis::horizontal);
	auto curPos = _position.rtpVector();
	curPos[1] += GameTime::getDeltaTime() * _playerStats.getMoveSpeed() * direc;
	Vector2D<double> newPos{curPos[0], curPos[1], curPos[2], VectorType::rtp};
    _position = newPos;
}