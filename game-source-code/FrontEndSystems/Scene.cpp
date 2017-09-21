#include "Scene.h"
#include <algorithm>

using gameObj_ptr = std::shared_ptr<GameObject>;

void Scene::SceneUpdate()
{
	if(_gameObject_list.size() == 0)
		return;
		
	auto temporyGameObjList = _gameObject_list;
	
	for(auto GO : temporyGameObjList)
	{
		GO->Update();
	}
}

std::vector<gameObj_ptr> Scene::getGameObjectList() const
{
	return _gameObject_list;
}
void Scene::Instantiate(GameObject* gameObj)
{
	gameObj->Start();
	gameObj_ptr thisGameObj_ptr{gameObj};
	_gameObject_list.push_back(thisGameObj_ptr);
}
void Scene::Instantiate(gameObj_ptr gameObj)
{
	gameObj->Start();
	_gameObject_list.push_back(gameObj);
}
void Scene::DestroyGameObject(GameObject* gameObj)
{
	_updatingList = true;
	std::shared_ptr<GameObject> gameObject_ptr{gameObj};
	std::remove(std::begin(_gameObject_list), std::end(_gameObject_list), gameObject_ptr);
	_updatingList = false;
}