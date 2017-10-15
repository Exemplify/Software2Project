#include "BackgroundFactory.h"
#include "GameObjectDataAdaptor.h"

std::shared_ptr<GameObject> BackgroundFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{
	auto objectdata = database->getGameObjectData(_backgroundID);
	auto graphicObject = GameObjectDataAdaptor::graphicObjectAdaptor(objectdata);
	auto scale = GameObjectDataAdaptor::ScaleAdaptor(objectdata);
	auto backgroundObject = std::make_shared<SplashScreen>(graphicObject, scale);
	return backgroundObject;
}