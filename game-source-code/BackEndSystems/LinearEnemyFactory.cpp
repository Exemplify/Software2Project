#include "LinearEnemyFactory.h"
#include "../FrontEndSystems/LinearMove.h"

std::shared_ptr<MovableInterface> LinearEnemyFactory::getMovableType(const GameObjectData& data)
{
	auto move = std::make_shared<LinearMove>(data.move_speed);
	return move;
}
GameObjectData LinearEnemyFactory::getEnemyData(std::shared_ptr<DatabaseInterface> database)
{
	auto data = database->getGameObjectData("enemy_linear");
	return data;
}