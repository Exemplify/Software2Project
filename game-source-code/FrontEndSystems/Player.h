#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"
#include "../Vector2D.h"
#include <memory>
#include "DelayComponent.h"
#include "ShootInterface.h"
#include "GraphicObject.h"
#include "MovableInterface.h"

/* Player Description
 * Player is used to contain the responsibilities of the user as they play the game. 
 * The class has the responsibilities of moving shooting all based off of input from the user. 
 * The player also detects when it has collided with either the enemy or the enemy bullets
 */
class Player : public PhysicsObject
{
public:

    Player(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, 
					const std::shared_ptr<ShootInterface>& shoot, const double& shootDelay);
    void Update() override;
    virtual void collisionAction(const GameObjectType& objectType) override;
private:
	DelayComponent _shootDelay;
	std::shared_ptr<ShootInterface> _shootComp;
	std::shared_ptr<MovableInterface> _moveComp;
	void ShootConditionalCheck();
	
	
};

#endif