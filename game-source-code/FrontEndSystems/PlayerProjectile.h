#ifndef PLAYER_PROJ_H
#define PLAYER_PROJ_H
#include "Projectile.h"

/**
 * @class PlayerProjectile
 * @brief Used to represent the PlayerProjectile within the game
 * @details The template design pattern is used to create the PlayerProjectile
 * from the base Projectile object so that only the most necessary functions 
 * are overriden to vary the PlayerProjectile and the EnemyProjectile
 */
class PlayerProjectile : public Projectile
{
public:
	/**
	* @brief Constructs the PlayerProjectile Object
	* @param physicsObject Base PhysicsObject members are copied 
	* @param move The MovableInterface that defined the movement style for the projectile
	* @param destroyBounds The region in which the Porjectile is destroyed when it is inside of it
	*/
	PlayerProjectile(const PhysicsObject& physicsObject,
					 const std::shared_ptr<MovableInterface>& move, 
					 const Boundary& destroyBounds);
	/**
	 * @brief Destroyed itself when the object is close to the centre of the screen (inside the Boundary defined)
	 */
	virtual void DestroySelf() override;
	/**
	 * @brief Destroys itself when the object collides with the various types of enemy objects
	 * @param objectType The GameObjectType representing the type of object that was collided with
	 */
	virtual void collisionAction(const GameObjectType& objectType) override;
};


#endif