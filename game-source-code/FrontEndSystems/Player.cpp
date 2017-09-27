#include "Player.h"
#include "SpriteInfo.h"
#include "../BackEndSystems/GameTime.h"
#include "Projectile.h"

const double SHOOT_DELAY = 0.35; 
const double SHOOT_SPEED = 150;
Player::Player(Vector2D<double>& startPosition, Character playerStats):
_leftUnitVector{1, -M_PI, 0, VectorType::rtp},
// this will become redundant with movement class
_rightUnitVector{1, M_PI, 0, VectorType::rtp},
// redundant with movement class
_playerStats{playerStats},
// should the player/ playing obbject have access to the statistics
_shootDelay{SHOOT_DELAY}
// investigate
{	
	_position = startPosition;
    
	auto playerBulletSprite = std::make_shared<SpriteInfo>();
    //The player doesn't need to know about the bullet data, It should just call a weapon/bullet and the bullet must generate its own graphic
	/// will be adjusted with database
    playerBulletSprite->textureLocation = "resources/Rock.png";
    // refere to above
    
	playerBulletSprite->scale = Vector2f(0.05f,0.05f);
    // refer to above
	
	_shootComp = ShootComponent(playerBulletSprite, GameObjectType::playerBullet);
    // investigate, possibly instantiates a bullet object
}


// is this a copy constructor?
Player::Player(Vector2D<double>& startPosition, Character playerStats, std::shared_ptr<SpriteInfo> bulletSprite):
GraphicObject(),
_leftUnitVector{1, -M_PI, 0, VectorType::rtp},
_rightUnitVector{1, M_PI, 0, VectorType::rtp},
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY},
_shootComp{bulletSprite, GameObjectType::playerBullet}
{
    _position = startPosition;
}

void Player::Update()
{
	move();//checks the movement input and calls the corresponding move function
	ShootConditionalCheck();// investigate
}

/* Redundant
void Player::TestMoveLeft()
{
    _position*=_leftUnitVector;
}

void Player::TestMoveRight()
{
    _position*=_rightUnitVector;
}
*/

void Player::move()
{
    //investigate this implementation
	auto direc = Input::getAxis(Axis::horizontal);
	auto curPos = _position.rtpVector();
	curPos[1] += GameTime::getDeltaTime() * _playerStats.getMoveSpeed() * direc; 
    // investigate GameTime. Should the player speed not be standard/updatable and be a direct concern of the player/playing object itself?
    
	Vector2D<double> newPos{curPos[0], curPos[1], curPos[2], VectorType::rtp};
    
    _position = newPos;
    // is this realy necessary with the vector operators?
	/// from what i saw the vector operators add the scalar to each value, this only increases the theta
}

void Player::ShootConditionalCheck()
{
	_shootDelay.reduceTime(); // why... investigate
	if(Input::IsButtonPressed(Keys::space) && _shootDelay.DelayFinished())
	{
		Vector2D<double> origin;
        
		_shootComp.Shoot(origin, _position, SHOOT_SPEED, *_scene);
        // can operators alone not impruve the implementation and ambiguity?
        
		_shootDelay.resetDelay();
	}
    // is there a better implementation of the delay functionality?
	/// Not that i can think of but it could be improvec
}


