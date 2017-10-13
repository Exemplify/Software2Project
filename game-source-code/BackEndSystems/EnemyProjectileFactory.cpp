#include "EnemyProjectileFactory.h"
#include "../Vector2D.h"

std::shared_ptr<GameObject> EnemyProjectileFactory::getGameObject()
{
	auto bulletType = GameObjectType::enemyBullet;
	GraphicObject bulletGraphic{"resources/SouthAfricanPS.png","enemyBullet"};
	xyVector scale{0.1, 0.1};
	auto projectile = std::make_shared<Projectile>(bulletGraphic, bulletType, scale);
	return projectile;
}