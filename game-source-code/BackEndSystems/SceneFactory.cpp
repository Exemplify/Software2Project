#include "SceneFactory.h"

std::shared_ptr<Scene> SceneFactory::getScene(std::shared_ptr<DatabaseInterface> database) const
{
	auto gameObjectList = getGameObectList(database);
	auto scene = std::make_shared<Scene>();
	for(auto& GO: gameObjectList)
	{
		scene->Instantiate(GO);
	}
	return scene;
}