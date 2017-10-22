#include "SpiralEnemyFactory.h"
#include "../FrontEndSystems/SpiralMove.h"

std::shared_ptr<MovableInterface> SpiralEnemyFactory::getMovableType(const GameObjectData& data)
{
	auto move = std::make_shared<SpiralMove>(data.move_speed, data.enemy_angular_speed);
	return move;
}

GameObjectData SpiralEnemyFactory::getObjectData(const std::shared_ptr<DatabaseInterface>& database)
{
	auto data = database->getGameObjectData("enemy_spiral");
	return data;
}