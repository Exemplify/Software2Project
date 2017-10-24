#ifndef SHOOT_H
#define SHOOT_H
#include "../Vector2D.h"
#include "Scene.h"
#include "Projectile.h"
#include "../BackEndSystems/GameObjectFactory.h"
#include "../BackEndSystems/Application.h"
/**
 * @class ShootInterface
 * @brief The Interface used to define the various methods of creating and shooting Projectile objects
 */
class ShootInterface
{
public:
	/**
	 * @brief Shoots a Projectile object in a way defined by the derived class, used as the main interface with the client
	 * @param startPosition The starting position of the Projectile
	 * @param target The target that the projectile moves towards
	 * @param scene The scene that the projectile is instantiated into
	 */
	virtual void Shoot(	Vector2D startPosition, Vector2D target, std::shared_ptr<Scene> scene) = 0;
	
	virtual ~ShootInterface() = default;
protected:
	/**
	 * @brief determines the projectile object used for the specific shoot component 
	 * @return Returns the desired projectile
	 */
	virtual std::shared_ptr<Projectile> getProjectile() = 0;

};

#endif