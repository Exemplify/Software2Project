#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "../BackEndSystems/GameTime.h"


const int MAX_DEGREES = 360;
// why is this necessary? | refere to InitialisePosition()
///refer to InitialisePosition()
const double DEG_2_RAD = 3.141592653589793/180.0;
// Ok might be usefull but why exactly | refere to InitialisePosition()
///refer to InitialisePosition()

const double ENEMY_SHOOT_DELAY = 2; 
// ok.. why
/// Rate of fire for each enemy how often do we want the to shoot
Enemy::Enemy(Character enem):
_shootDelay{ENEMY_SHOOT_DELAY, true},
//what is the true for?
/// causes the enemy to shoot immediately after being spawned was doing this for bug testing forgot to remove
_enemyStats{enem}
// similar to Player, should the enemy object have access to enemy statistics?
/// yes because there are multiple Enemy objects being created this means that each one will have a different set of values to
/// store and control that elsewhere will be difficult to implement properly esspecially because objects will be deleted as the game progresses.
{
	_spriteInfo->textureLocation = "resources/AdamHabib.png";
	_spriteInfo->scale = sf::Vector2f{0.25f,0.25f};
	InitialisePosition();
    // The enemy object should access this through a get graphic function
    // a simillar is not present in the player, why?
	/// So this will change to the responsibility of the database and DisplayManager as they  will hold the data and pull the information
	auto bulletSpriteInfo = std::make_shared<SpriteInfo>();
	bulletSpriteInfo->textureLocation = "resources/SouthAfricanPS.png";
	bulletSpriteInfo->scale = Vector2f(0.1f,0.1f);
    // similarly this should not be instantiated by the enemy. the enemy should not know anything about the bullet sprite
	/// this was implemented like this incase we had a different enemy type which shoots different bullets but yes it can be replaced with an enumerator instead
    
	_enemyShoot = ShootComponent(bulletSpriteInfo, GameObjectType::enemyBullet);
    // investigate..
	/// ???
	
}
void Enemy::Update()
{
	Move();
	Shoot();
	CheckOutsideScreen();
	// these functions are good
}
void Enemy::InitialisePosition()
{
	double angle = rand()%MAX_DEGREES;
	angle*=DEG_2_RAD;
    // surely the above becomes redundant if simpl
	/// so it is easier to conceptualise degrees and the rand function produces a random integer, so by using degrees then converting to radians
	/// the resolution of the angle is smaller
    
	Vector2D<double> startPos{1, angle, 0, VectorType::rtp};
    // I understand now, there may be some ambiguity with the Vector2D class, by default (and the only implementation deployed) the theta is declared in radians
    /// I used radians
	_position = startPos;
}
void Enemy::Move()
{
	auto curPos = getPosition().rtpVector();
	curPos[0] += _enemyStats.getMoveSpeed() * GameTime::getDeltaTime();
	Vector2D<double> newPos{curPos, VectorType::rtp};
	_position = newPos;
    // there is better implementation for this. Additional movement class functionality implementation
	/// As discussed this can be moved into a movement composition class but i feel that the DeltaTIme Element must stay
}

void Enemy::CheckOutsideScreen()
{
	if(_screenBounds.OutOfBounds(_position))
	{
		InitialisePosition();
	}
    // good simple implementation 
	/// I am not entirely happy with the function name 
}

void Enemy::Shoot()
{
	_shootDelay.reduceTime();
	if(_shootDelay.DelayFinished())
	{
		_shootDelay.resetDelay();
        // should this not rather be at the end of this if statement? to avoid functional overrun
		/// yes.
        
		auto target = _position.rtpVector();
		target[0] += 1;
		Vector2D<double> targetVec{target, VectorType::rtp};
        // there is much better implementation possible with the Vector2D operators
		/// possibly this is caused by my lack of understanding within the vector class
        
		_enemyShoot.Shoot(targetVec, _position, 3*_enemyStats.getMoveSpeed(), *_scene);
        // investigate.
	}
    // there is better implementation for this
	/// I would disagree this seperates the responsibility of instantiating the game objects from the enemy
	/// the current functionality provides versitility to the enemy to decide where they want to shoot from. 
	/// It can be refined though
}


