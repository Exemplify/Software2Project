#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"
#include "../Vector2D.h"
#include <memory>
#include "DelayComponent.h"
#include "ShootInterface.h"
#include "GraphicObject.h"
#include "MovableInterface.h"

/** Player Description
 * @brief Player is used to contain the responsibilities of the object that the user controls.
 * @details The Player is required to respond to various inputs and events from the user.
 */
class Player : public PhysicsObject
{
public:
	/**
	 * @brief Constructs the player used for the game with the corresponding parameters.
	 * @param physicsObject The properties of the physics object specified are copied to the player
	 * @param move A MovableInterface defined for the player's specific movement style
	 * @param shoot The ShootInterface defined for the player's specific shoot style
	 * @param shootDelay The amount of time required before the player can shoot again after having shot
	 */
    Player(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, 
					const std::shared_ptr<ShootInterface>& shoot, const double& shootDelay);
	/**
	 * @brief Checks for input from the user to determine the players appropriate response
	 */
    void Update() override;
	/**
	 * @brief Checks if the Player has collided with the Enemy or the EnemyProjectile, then responds accordingly
	 * @param objectType The GameObjectType that the player has collided with
	 */
    virtual void collisionAction(const GameObjectType& objectType) override;
private:
	DelayComponent _shootDelay; /**<The delay between player shots*/
	std::shared_ptr<ShootInterface> _shootComp; /**<The ShootInterface that the player uses*/
	std::shared_ptr<MovableInterface> _moveComp; /**<The MovableInterface that the player uses*/
	
	/**
	 * @brief Checks if the conditions for shooting have been met ie. The delay is finished and the user has pressed the correct button
	 */
	void ShootConditionalCheck();
	
	
};

#endif