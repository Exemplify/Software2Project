#include "EnemyProjectileFactory.h"
#include "../Vector2D.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> EnemyProjectileFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{
	auto objectData = database->getGameObjectData("enemyProjectile");
	auto bulletType = GameObjectType::enemyBullet;
	auto bulletGraphic = GameObjectDataAdaptor::graphicObjectAdaptor(objectData);
	auto scale = GameObjectDataAdaptor::ScaleAdaptor(objectData);
	return std::make_shared<Projectile>(bulletGraphic, bulletType, scale, objectData.move_speed, objectData.collider_size);
}