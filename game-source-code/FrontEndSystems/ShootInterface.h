#ifndef SHOOT_H
#define SHOOT_H
#include "../Vector2D.h"
#include "Scene.h"
#include "Projectile.h"
#include "../BackEndSystems/GameObjectFactory.h"
#include "../BackEndSystems/Application.h"

class ShootInterface
{
public:
	// Creates a projectile in the specified scene with the provided parameters to meet the components
	/// Scene needs to be moved into the constructor should be the current scene (use of Application Class)
	void Shoot(	Vector2D startPosition, Vector2D target, std::shared_ptr<Scene> scene);
	virtual ~ShootInterface() = default;
protected:
	virtual std::shared_ptr<Projectile> getProjectile() = 0;
	
private:
	Vector2D CalculateShootDirection(Vector2D startPosition, Vector2D target);

};

#endif