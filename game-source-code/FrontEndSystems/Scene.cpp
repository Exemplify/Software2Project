#include "Scene.h"

using gameObj_ptr = std::shared_ptr<GameObject>;

void Scene::SceneUpdate()
{
	if(_gameObject_list.size() == 0)
		return;
	
	for(auto GO : _gameObject_list)
	{
		GO->Update();
	}
}
const std::vector<gameObj_ptr> Scene::getGameObjectList()
{
	return _gameObject_list;
}
void Scene::Instantiate(GameObject* gameObj)
{
	gameObj->Start();
	gameObj_ptr thisGameObj_ptr{gameObj};
	_gameObject_list.push_back(thisGameObj_ptr);
}