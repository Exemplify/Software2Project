#include "ParabolicEnemyFactory.h"
#include "../FrontEndSystems/ParabolicMove.h"
#include "GameObjectDataAdaptor.h"

GameObjectData ParabolicEnemyFactory::getEnemyData(std::shared_ptr<DatabaseInterface> database)
{
	auto data = database->getGameObjectData("enemy_parabolic");
	return data;
}

std::shared_ptr<MovableInterface> ParabolicEnemyFactory::getMovableType(const GameObjectData& data)
{
	auto move = std::make_shared<ParabolicMove>(data.parabolic_coeff, data.move_speed);
	return move;
}

Vector2D ParabolicEnemyFactory::getStartingPosition(const GameObjectData& data)
{
	auto startPosition = GameObjectDataAdaptor::PositionAdaptor(data);
	return startPosition;
}