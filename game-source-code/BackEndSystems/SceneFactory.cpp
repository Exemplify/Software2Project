#include "SceneFactory.h"

std::shared_ptr<Scene> SceneFactory::getScene() const
{
	auto gameObjectList = getGameObectList();
	auto scene = std::make_shared<Scene>();
	for(auto& GO: gameObjectList)
	{
		scene->Instantiate(GO);
	}
	return scene;
}