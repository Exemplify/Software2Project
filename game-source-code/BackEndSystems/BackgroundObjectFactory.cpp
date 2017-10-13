#include "BackgroundObjectFactory.h"

std::shared_ptr<GameObject> BackgroundFactory::getGameObject()
{
	auto backgroundObject = std::make_shared<SplashScreen>(getGraphicObject(), getScale());
	return backgroundObject;
}