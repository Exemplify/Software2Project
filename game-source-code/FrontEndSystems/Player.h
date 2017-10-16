#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"
#include "../Vector2D.h"
#include <memory>
#include "Character.h"
#include "DelayComponent.h"
#include "ShootInterface.h"
#include "GraphicObject.h"
#include "MovableInterface.h"

using namespace std;
/// Character rework required here as well 

/* Player Description
 * Player is used to contain the responsibilities of the user as they play the game. 
 * The class has the responsibilities of moving shooting all based off of input from the user. 
 * The player also detects when it has collided with either the enemy or the enemy bullets
 */
class Player : public PhysicsObject
{
public:
	
	Player()
	{
		_type = GameObjectType::player;
	}
	Player(Vector2D& startPosition);
    Player(Vector2D& startPosition, GraphicObject playerGraphic, 
					xyVector scale, std::shared_ptr<MovableInterface> move, std::shared_ptr<ShootInterface> shoot);
	// override functions called by external objects
    void Update() override;
    virtual void collisionAction(GameObjectType objectType) override;
	
private:
	// moves the player in the specified direction
	
	// Composition Variables 
	/// character needs to be adjusted and the additional components pushed into it
	DelayComponent _shootDelay;
	std::shared_ptr<ShootInterface> _shootComp;
	std::shared_ptr<MovableInterface> _moveComp;
	// Checks if the conditions for shooting have been met, delay is over and shoot input is pressed
	void ShootConditionalCheck();
	
	
};

#endif