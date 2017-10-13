#include "Player.h"
#include "SpriteInfo.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/PlayerProjectileFactory.h"
#include "Projectile.h"


/// Information needs to be stored in a database
const double SHOOT_DELAY = 0.35; 
const double SHOOT_SPEED = 150;
/// Player constructor needs to be reworked too much database implementation is used 
Player::Player(Vector2D& startPosition, Character playerStats):
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY}
{	
	/// Needs to be stored in a database
	_graphicObject = GraphicObject("resources/playerSprite.png", "player");
	_position = startPosition;
	_scale = xyVector(0.25f,0.25f);
	_type = GameObjectType::player;
    _objectSize = 25;
	GraphicObject bulletGraphic{"resources/Rock.png", "playerBullet"};
	auto projectileFactory = std::make_shared<PlayerProjectileFactory>();
	_shootComp = ShootComponent(projectileFactory);
}

Player::Player(Vector2D& startPosition, Character playerStats, GraphicObject playerGraphic, xyVector scale):
PhysicsObject(),
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY}
{
	_scale = scale;
	_graphicObject = playerGraphic;
	_type = GameObjectType::player;
    _position = startPosition;
    _objectSize = 25;
	auto projectileFactory = std::make_shared<PlayerProjectileFactory>();
	_shootComp = ShootComponent(projectileFactory);
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
	auto curPos = _position.getRTVector();
	curPos.t += GameTime::getDeltaTime() * _playerStats.getMoveSpeed() * direc;
	Vector2D newPos{curPos};
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
		Vector2D origin;
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