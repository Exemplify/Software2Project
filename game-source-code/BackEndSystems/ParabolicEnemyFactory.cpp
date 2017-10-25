#include "ParabolicEnemyFactory.h"
#include "../FrontEndSystems/ParabolicMove.h"
#include "GameObjectDataAdaptor.h"

GameObjectData ParabolicEnemyFactory::getObjectData(const std::shared_ptr<DatabaseInterface>& database)
{
	auto data = database->getGameObjectData("enemy_parabolic");
	return data;
}

std::shared_ptr<MovableInterface> ParabolicEnemyFactory::getMovableType(const GameObjectData& data)
{
	auto move = std::make_shared<ParabolicMove>(data.move_speed ,data.parabolic_coeff);
	return move;
}
