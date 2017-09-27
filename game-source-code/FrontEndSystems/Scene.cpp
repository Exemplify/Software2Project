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
	/// it is not was used to debug
	std::lock_guard<std::mutex> lock(_gameObj_list_mutex);
    // if this is to prevent modification could this not be done by const auto& Go in the for loop below?
	/// No Mutex is much more powerful 
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
// Why would a scene need to return its game object list? Additionally does the const prevent modification later on... is this intended?
/// Display manager needs to access the list, no the const means that getGameObjectList() 
void Scene::Instantiate(gameObj_ptr gameObj)
{
	gameObj->Start();
	gameObj->setScene(shared_from_this());
    //what is the above line for?
	/// tells each gameObject which scene they are attached to so that they can remove themselves
	gameObj_ptr thisGameObj_ptr{gameObj};
	_gameObject_list.push_back(thisGameObj_ptr);
}
// Understandably generates the instance of the game object.
/// yes.
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
	/// 1) not arrow code only 2 conditional checks, 2 no way to prevent it
	/// 2) purpose is to remove the object not set it as inactive, that is if we want the object at a later stage ie, make a player flash

}