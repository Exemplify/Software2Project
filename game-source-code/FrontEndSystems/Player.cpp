#include "Player.h"
#include "SpriteInfo.h"
#include "../BackEndSystems/GameTime.h"
#include "Projectile.h"

/// Information needs to be stored in a database
const double SHOOT_DELAY = 0.35; 
const double SHOOT_SPEED = 150;
/// Player constructor needs to be reworked too much database implementation is used 
Player::Player(Vector2D<double>& startPosition, Character playerStats):
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY}
{	
	/// Needs to be stored in a database
	_position = startPosition;
	auto playerBulletSprite = std::make_shared<SpriteInfo>();
	playerBulletSprite->textureLocation = "resources/Rock.png";
	playerBulletSprite->scale = Vector2f(0.05f,0.05f);
    _objectSize = 25;
	_type = GameObjectType::player;
	_graphicName = "player";
	_shootComp = ShootComponent(playerBulletSprite, GameObjectType::playerBullet);
}

Player::Player(Vector2D<double>& startPosition, Character playerStats, std::shared_ptr<SpriteInfo> bulletSprite):
PhysicsObject(),
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY},
_shootComp{bulletSprite, GameObjectType::playerBullet}
{
	_type = GameObjectType::player;
    _position = startPosition;
    _objectSize = 25;
}
// Each update a check to move and shoot is done
void Player::Update()
{
	move();
	ShootConditionalCheck();
}
/// needs to be put into a movement interface
void Player::move()
{
	auto direc = Input::getAxis(Axis::horizontal);
	auto curPos = _position.rtpVector();
	curPos[1] += GameTime::getDeltaTime() * _playerStats.getMoveSpeed() * direc;
	Vector2D<double> newPos{curPos[0], curPos[1], curPos[2], VectorType::rtp};
    _position = newPos;
}
// Checks if the player must shoot
void Player::ShootConditionalCheck()
{
	/// Shoot Delay reduceTime must be removed and incorportaed into DelayFinished
	_shootDelay.reduceTime();
	// Checks if the space key has been pressed and if the delay has finished then creates 
	// a player bullet in the current scene at the specified shootspeed and position
	if(Input::IsButtonPressed(Keys::space) && _shootDelay.DelayFinished())
	{
		Vector2D<double> origin;
		_shootComp.Shoot(origin, _position, SHOOT_SPEED, *_scene);
		_shootDelay.resetDelay();
	}
}


void Player::collisionAction(GameObjectType objectType)
{
	// if the player collides with the enemy or enemy bullet the player loses and the lose screen is loaded
	/// Magic Number needs to be removed (can be replaced by an enumerator class or static variable)
    if (objectType == GameObjectType::enemyBullet || objectType == GameObjectType::enemy)
        GameManager::LoadScene(3);
}