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
void Scene::Instantiate(gameObj_ptr gameObj)
{
	gameObj->Start();
	gameObj->setScene(shared_from_this());
	gameObj_ptr thisGameObj_ptr{gameObj};
	_gameObject_list.push_back(thisGameObj_ptr);
}
void Scene::DestroyGameObject(gameObj_ptr gameObj)
{
	_updatingList = true;
	for(auto idx = _gameObject_list.begin(); idx != _gameObject_list.end(); idx++)
	{
		if(*idx == gameObj)
		{
			_gameObject_list.erase(idx);
			break;
		}
	}
	_updatingList = false;
}