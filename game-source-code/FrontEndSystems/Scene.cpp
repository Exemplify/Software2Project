#include "Scene.h"
#include <algorithm>
#include <mutex>
#include "../BackEndSystems/GameManager.h"

using gameObj_ptr = std::shared_ptr<GameObject>;

void Scene::SceneUpdate()
{
	if(_gameObject_list.size() == 0)
		return;
	
	auto temporyGameObjList = _gameObject_list;	
	std::lock_guard<std::mutex> lock(_gameObj_list_mutex);
	for(auto GO : temporyGameObjList)
	{
		_updatingList = true;
		GO->Update();
		_updatingList = false;
	}
}

std::vector<gameObj_ptr> Scene::getGameObjectList() const
{
	return _gameObject_list;
}
void Scene::Instantiate(gameObj_ptr gameObj)
{
	gameObj->Start();
	gameObj->setScene(shared_from_this());
	gameObj_ptr thisGameObj_ptr{gameObj};
	_gameObject_list.push_back(thisGameObj_ptr);
}
void Scene::DestroyGameObject(gameObj_ptr gameObj)
{
	
	for(auto idx = _gameObject_list.begin(); idx != _gameObject_list.end(); idx++)
	{
		if(*idx == gameObj)
		{
			_gameObject_list.erase(idx);
			break;
		}
	}


}