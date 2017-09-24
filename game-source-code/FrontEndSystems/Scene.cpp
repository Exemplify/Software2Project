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
    //Why is the above necessary? The above is a shared pointer type...
	std::lock_guard<std::mutex> lock(_gameObj_list_mutex);
    // if this is to prevent modification could this not be done by const auto& Go in the for loop below?
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
//Why would a scene need to return its game object list? Additionally does the const prevent modification later on... is this intended?

void Scene::Instantiate(gameObj_ptr gameObj)
{
	gameObj->Start();
	gameObj->setScene(shared_from_this());
    //what is the above line for?
	gameObj_ptr thisGameObj_ptr{gameObj};
	_gameObject_list.push_back(thisGameObj_ptr);
}
// Understandably generates the instance of the game object.

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
    // Arrow Code! is this preventable (Yes)
    // is this necessary given that a scene is a composition of gameObjects, and that there is an _active bool flag on the gameObject?

}