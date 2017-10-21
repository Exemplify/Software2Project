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