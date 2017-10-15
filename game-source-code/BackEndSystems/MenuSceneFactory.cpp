#include "MenuSceneFactory.h"

std::list<std::shared_ptr<GameObject>> MenuSceneFactory::getGameObectList(std::shared_ptr<DatabaseInterface> database) const
{
	std::list<std::shared_ptr<GameObject>> gameObjectlist;
	auto backgroundFactory = getFactory();
	auto backgroundObject = backgroundFactory->getGameObject(database);
	gameObjectlist.push_back(backgroundObject);
	return gameObjectlist;
}