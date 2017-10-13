#include "SceneFactory.h"

std::shared_ptr<Scene> SceneFactory::getScene() const
{
	auto gameObjectList = getGameObectList();
	auto scene = std::make_shared<Scene>(gameObjectList);
	return scene;
}