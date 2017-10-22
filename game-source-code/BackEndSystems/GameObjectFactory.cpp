#include "GameObjectFactory.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> GameObjectFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto objectData = getObjectData(database);
	auto startPosition = GameObjectDataAdaptor::PositionAdaptor(objectData);
	auto graphicObject = GameObjectDataAdaptor::graphicObjectAdaptor(objectData);
	auto scale = GameObjectDataAdaptor::ScaleAdaptor(objectData);
	return std::make_shared<GameObject>(startPosition, scale, graphicObject);
}