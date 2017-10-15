#include "ShootComponent.h"
#include <memory>


ShootComponent::ShootComponent(std::shared_ptr<GameObjectFactory> projectileFactory):
_projectileFactory{projectileFactory}
{}


void ShootComponent::Shoot(	Vector2D target,
	Vector2D startPosition, double shootSpeed, Scene& scene)
{	
	// Calculates the shoot direction based off of the target
	auto shotDirec = target - startPosition;
	auto shotDirecVec = shotDirec.getRTVector();
	shotDirecVec.r = 1;
	shotDirec = Vector2D(shotDirecVec);
	// Copies the _bullet variable to be instantiated
	auto bulletObject = Application::getGameRepository()->getGameObjectbyType(GameObjectType::playerBullet);
	// Initialises the current bullet with the specific direction and speed
	auto bullet = std::dynamic_pointer_cast<Projectile>(bulletObject);
	bullet->Initialise(startPosition, shotDirec, shootSpeed);
	// Instantiates the copied bullet
	scene.Instantiate(bullet);
}
