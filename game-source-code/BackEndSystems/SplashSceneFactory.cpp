#include "SplashSceneFactory.h"
#include "SplashScreenBackgroundFactory.h"

std::vector<std::shared_ptr<GameObject>> SplashSceneFactory::getGameObectList() const
{
	std::vector<std::shared_ptr<GameObject>> gameObjectVec;
	SplashScreenBackgroundFactory backgroundFactory;
	auto backgroundObject = backgroundFactory.getGameObject();
	gameObjectVec.push_back(backgroundObject);
	return gameObjectVec;
}