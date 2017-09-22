#include "Scene.h"
#include <algorithm>

using gameObj_ptr = std::shared_ptr<GameObject>;

void Scene::SceneUpdate()
{
	if(_gameObject_list.size() == 0)
		return;
		
	vector<GameObject> temporyGameObjList;
	for(auto GO_ptr : _gameObject_list)
	{
		temporyGameObjList.push_back(*GO_ptr);
	}
	
	for(auto GO : temporyGameObjList)
	{
		GO.Update();
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
void Scene::DestroyGameObject(gameObj_ptr& gameObj)
{
	_updatingList = true;
	for(auto idx = begin(_gameObject_list); idx != end(_gameObject_list); )
	{
		if(*idx == gameObj)
		{
			_gameObject_list.erase(idx);
		}
		else
			idx++;
	}
	_updatingList = false;
}