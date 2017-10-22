#include "Player.h"
#include "SpriteInfo.h"
#include "../BackEndSystems/GameTime.h"
#include "../BackEndSystems/PlayerProjectileFactory.h"
#include "Projectile.h"
#include "../BackEndSystems/Application.h"

Player::Player(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, 
					const std::shared_ptr<ShootInterface>& shoot, const double& shootDelay):
PhysicsObject(physicsObject),
_shootDelay{shootDelay},
_shootComp{shoot},
_moveComp{move}
{
	_type = GameObjectType::player;
}
// Each update a check to move and shoot is done
void Player::Update()
{
	_moveComp->Move(_position);
	ShootConditionalCheck();
}
// Checks if the player must shoot
void Player::ShootConditionalCheck()
{
	// Checks if the space key has been pressed and if the delay has finished then creates 
	// a player bullet in the current scene at the specified shootspeed and position
	if(_shootDelay.DelayFinished() && Input::IsButtonPressed(Keys::space))
	{
		Vector2D origin;
		_shootComp->Shoot( _position, origin, _scene);
		_shootDelay.resetDelay();
	}
}


void Player::collisionAction(const GameObjectType& objectType)
{
	// if the player collides with the enemy or enemy bullet the player loses and the lose screen is loaded
    if (objectType == GameObjectType::enemyBullet || objectType == GameObjectType::enemy)
	{
		const int LOSING_SCENE = 3;
		//Application::LoadScene(LOSING_SCENE);
	}
}