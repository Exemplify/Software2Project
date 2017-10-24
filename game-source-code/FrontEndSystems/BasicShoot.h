#ifndef BASIC_SHOOT_H
#define BASIC_SHOOT_H
#include "ShootInterface.h"
/**
 * @class NonProjectileObjectShot
 * @brief Exception thrown if an object that doesnt derive from Projectile is used
 */
class NonProjectileObjectShot{};

/**
 * @class BasicShoot
 * @brief Used to create a basic shoot component which creates a single projectile and shoots it in a straightline towards a target.
 */
class BasicShoot : public ShootInterface
{
public:
	/**
	* @brief Constructs the BasicShoot Object used to create a projectile that fires in a straight line to a target
	* @param projectileType The GameObjectType used to define the specific Projectile that is created and shot
	*/
	BasicShoot(GameObjectType projectileType);
	
	virtual void Shoot(Vector2D startPosition, Vector2D target, std::shared_ptr<Scene> scene) override;
protected:
/**
 * @brief Overriden function used to get the projectile used by the BasicShoot object
 * @details Uses the Repository to construct the specific projectile object that is defined by the _projectileType
 * @return Returns the generated projectile that needs to be shot by the shoot component
 */
	virtual std::shared_ptr<Projectile> getProjectile() override;
private:
	/**
	 * @brief Calculates the direction that the projectile from the start position to the target
	 * @param startPosition The starting position of the projectile
	 * @param target The target that the projectile needs to move towards
	 * @return Returns a Vector2D that represents the unit direction from the start position to the target 
	 */
	Vector2D CalculateShootDirection(Vector2D startPosition, Vector2D target);
	GameObjectType _projectileType; /**< The GameObjectType used to deferentiat the various projectiles that can be created*/
};

#endif