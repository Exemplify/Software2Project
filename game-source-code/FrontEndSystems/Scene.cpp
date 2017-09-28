#include "Scene.h"
#include <algorithm>
#include <mutex>
#include "../BackEndSystems/GameManager.h"

using gameObj_ptr = std::shared_ptr<GameObject>;

Scene::Scene(const Scene& rhs)
{
	for(auto GO : rhs._gameObject_list)
	{
		auto temp_ptr = std::make_shared<GameObject>(*(GO->Clone()));
		_gameObject_list.push_back(temp_ptr);
	}
}


void Scene::SceneUpdate()
{
	if(_gameObject_list.size() == 0)
		return;
	
	std::lock_guard<std::mutex> lock(_gameObject_list_mutex);
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
	
	for(auto idx = _gameObject_list.begin(); idx != _gameObject_list.end(); idx++)
	{
		if(*idx == gameObj)
		{
			_gameObject_list.erase(idx);
			break;
		}
	}
}

Scene& Scene::operator =(const Scene& rhs)
{
	_gameObject_list = rhs._gameObject_list;
	return *this;
}