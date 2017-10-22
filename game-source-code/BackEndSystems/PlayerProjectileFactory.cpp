#include "PlayerProjectileFactory.h"
#include "../FrontEndSystems/PlayerProjectile.h"
#include "../FrontEndSystems/LinearMove.h"
#include "../Vector2D.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> PlayerProjectileFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto objectData = database->getGameObjectData("playerProjectile");
	auto physicsObject = std::dynamic_pointer_cast<PhysicsObject>(PhysicsObjectFactory::getGameObject(database));
	auto move = std::make_shared<LinearMove>(objectData.move_speed);
	auto boundary = Boundary(objectData.player_projectile_destry_region, objectData.player_projectile_destry_region);
	return std::make_shared<PlayerProjectile>(*physicsObject, move, boundary);
}

GameObjectData PlayerProjectileFactory::getObjectData(const std::shared_ptr<DatabaseInterface>& database)
{
	return database->getGameObjectData("playerProjectile");
}