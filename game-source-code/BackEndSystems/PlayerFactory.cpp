#include "PlayerFactory.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/PlayerMove.h"
#include "../FrontEndSystems/BasicShoot.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> PlayerFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto playerData = getObjectData(database);
	auto physicsObject = *(std::dynamic_pointer_cast<PhysicsObject>(PhysicsObjectFactory::getGameObject(database)));
	auto playerMove = std::make_shared<PlayerMove>(playerData.move_speed);
	auto playerShoot = std::make_shared<BasicShoot>(GameObjectType::playerBullet);
	return std::make_shared<Player>(physicsObject, playerMove, playerShoot, playerData.player_shoot_delay);
}

GameObjectData PlayerFactory::getObjectData(const std::shared_ptr<DatabaseInterface>& database)
{
	return database->getGameObjectData("player");
}