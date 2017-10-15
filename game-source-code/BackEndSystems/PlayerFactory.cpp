#include "PlayerFactory.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/Character.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> PlayerFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{
	auto playerData = database->getGameObjectData("player");
	auto startPosition = GameObjectDataAdaptor::PositionAdaptor(playerData);
	auto scale = GameObjectDataAdaptor::ScaleAdaptor(playerData);
	auto playerGraphic = GameObjectDataAdaptor::graphicObjectAdaptor(playerData);
	Character playerStats{3, playerData.move_speed};
	return std::make_shared<Player>(startPosition, playerStats, playerGraphic, scale);
}