#ifndef SHOOT_H
#define SHOOT_H
#include "../Vector2D.h"
#include "Scene.h"
#include "Projectile.h"
#include "../BackEndSystems/GameObjectFactory.h"
#include "../BackEndSystems/Application.h"

class ShootComponent
{
public:
	ShootComponent(){}
	ShootComponent(std::shared_ptr<GameObjectFactory> projectileFactory);
	// Creates a projectile in the specified scene with the provided parameters to meet the components
	/// Scene needs to be moved into the constructor should be the current scene (use of Application Class)
	void Shoot(
		Vector2D target,
		Vector2D startPosition, 
		double shootSpeed,
		Scene& scene
		);
private:
	// the projectile that is copied
	std::shared_ptr<GameObjectFactory> _projectileFactory;
	/// Shot speed needs to be part of the shoot component
};

#endif