#include "MenuSceneFactory.h"

std::list<std::shared_ptr<GameObject>> MenuSceneFactory::getGameObectList() const
{
	std::list<std::shared_ptr<GameObject>> gameObjectlist;
	auto backgroundFactory = getFactory();
	auto backgroundObject = backgroundFactory->getGameObject();
	gameObjectlist.push_back(backgroundObject);
	return gameObjectlist;
}