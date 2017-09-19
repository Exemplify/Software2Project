#include "Player.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/GameTime.h"
#include "Projectile.h"

const double SHOOT_DELAY = 0.5; 
const double SHOOT_SPEED = 150;

Player::Player(Vector2D<double>& startPosition, Character playerStats):
_leftUnitVector{1, -M_PI, 0, VectorType::rtp},
_rightUnitVector{1, M_PI, 0, VectorType::rtp},
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY}
{
    _position = startPosition;
}
void Player::Update()
{
	move();
	ShootConditionalCheck();
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
void Player::ShootConditionalCheck()
{
	_shootDelay.reduceTime();
	if(Input::IsButtonPressed(Keys::space) && _shootDelay.DelayFinished())
	{
		Shoot();
		_shootDelay.resetDelay();
	}
}

void Player::Shoot()
{
	
	auto scene = GameManager::activeScene;
	auto shotDirec = _position * -1.0;
	shotDirec /= shotDirec.magnitude(shotDirec);
	auto bullet = std::make_shared<Projectile>(_position, shotDirec,SHOOT_SPEED);
	scene->Instantiate(bullet);
}

