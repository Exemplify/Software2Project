#include "BasicShoot.h"

BasicShoot::BasicShoot(GameObjectType projectileType):
_projectileType{projectileType}
{}

std::shared_ptr<Projectile> BasicShoot::getProjectile()
{
	auto bulletObject = Application::getGameRepository()->getGameObjectbyTypeDuringRuntime(_projectileType);
	auto bullet = std::dynamic_pointer_cast<Projectile>(bulletObject);
	if(bullet == nullptr)
		throw NonProjectileObjectShot();
	return bullet;
}

void BasicShoot::Shoot(Vector2D startPosition, Vector2D target, std::shared_ptr<Scene> scene)
{	
	// Calculates the shoot direction based off of the target
	auto shotDirec = CalculateShootDirection(startPosition, target);
	auto bullet = getProjectile();
	bullet->Initialise(startPosition, shotDirec);
	// Instantiates the copied bullet
	scene->Instantiate(bullet);
}

Vector2D BasicShoot::CalculateShootDirection(Vector2D startPosition, Vector2D target)
{
	auto shotDirec = target - startPosition;
	return shotDirec.normalize();
}