#include "BackgroundFactory.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> BackgroundFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto gameObject = GameObjectFactory::getGameObject(database);
	auto backgroundObject = std::make_shared<SplashScreen>(*gameObject);
	return backgroundObject;
}

GameObjectData BackgroundFactory::getObjectData(const std::shared_ptr<DatabaseInterface>& database)
{
	auto objectdata = database->getGameObjectData(_backgroundID);
	return objectdata;
}