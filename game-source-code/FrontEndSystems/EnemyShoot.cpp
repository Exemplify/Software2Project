#include "EnemyShoot.h"

std::shared_ptr<Projectile> EnemyShoot::getProjectile()
{
	auto bulletObject = Application::getGameRepository()->getGameObjectbyType(GameObjectType::enemyBullet);
	auto bullet = std::dynamic_pointer_cast<Projectile>(bulletObject);
	return bullet;
}