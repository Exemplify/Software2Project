#ifndef ENEMY_PROJ_H
#define ENEMY_PROJ_H
#include "Projectile.h"

/**
 * @class EnemyProjectile
 * @file EnemyProjectile.h
 * @brief Used to represent the enemy projectile and how it interacts with the various objects, inherits from Projectile
 */
class EnemyProjectile : public Projectile
{
public:
	/**
	* @brief Constructs the Enemy Projectile object 
	* @param physicsObject Assigns the properties of the Physics object to the EnemyProjectile constructed   
	* @param move MoveInterface used by the EnemyProjectile
	* @param destroyBounds Boundary for which the object exists inside
	*/
	EnemyProjectile(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, const Boundary& destroyBounds);
	/**
	 * @brief Object destroys itself when the object goes outside of the specified boundary 
	 */
	virtual void DestroySelf() override; 
	/**
	 * @brief Response to colliding with the various objects within the game
	 * @param objectType The type of object that has collided with the current EnemyProjectile
	 */
	virtual void collisionAction(const GameObjectType& objectType) override;
};


#endif