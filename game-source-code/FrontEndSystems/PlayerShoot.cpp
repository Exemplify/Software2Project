#include "PlayerShoot.h"

std::shared_ptr<Projectile> PlayerShoot::getProjectile()
{
	auto bulletObject = Application::getGameRepository()->getGameObjectbyType(GameObjectType::playerBullet);
	auto bullet = std::dynamic_pointer_cast<Projectile>(bulletObject);
	return bullet;
}