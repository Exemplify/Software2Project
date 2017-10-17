#include "PlayerProjectileFactory.h"
#include "../FrontEndSystems/Projectile.h"
#include "../FrontEndSystems/LinearMove.h"
#include "../Vector2D.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> PlayerProjectileFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{
	auto bulletType = GameObjectType::playerBullet;
	auto objectData = database->getGameObjectData("playerProjectile");
	auto bulletGraphic = GameObjectDataAdaptor::graphicObjectAdaptor(objectData);
	auto scale = GameObjectDataAdaptor::ScaleAdaptor(objectData);
	auto move = std::make_shared<LinearMove>(objectData.move_speed);
	return std::make_shared<Projectile>(bulletGraphic, bulletType, scale, move, objectData.collider_size);
}