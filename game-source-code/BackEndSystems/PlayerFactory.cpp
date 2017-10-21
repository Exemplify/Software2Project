#include "PlayerFactory.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/PlayerMove.h"
#include "../FrontEndSystems/BasicShoot.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> PlayerFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{
	auto playerData = database->getGameObjectData("player");
	auto startPosition = GameObjectDataAdaptor::PositionAdaptor(playerData);
	auto scale = GameObjectDataAdaptor::ScaleAdaptor(playerData);
	auto playerGraphic = GameObjectDataAdaptor::graphicObjectAdaptor(playerData);
	auto playerMove = std::make_shared<PlayerMove>(playerData.move_speed);
	auto playerShoot = std::make_shared<BasicShoot>(GameObjectType::playerBullet);
	return std::make_shared<Player>(startPosition, playerGraphic, scale, playerMove, playerShoot, playerData.collider_size);
}