#include "Scene.h"
#include <algorithm>
#include <mutex>
#include "../BackEndSystems/GameManager.h"



// Scene Update is run from a gamemanager object within the gameloop 
// it is called once per frame
void Scene::SceneUpdate()
{
	// Checks if the scene contains any gameobjects returns from the function if it does not
	if(_gameObject_list.size() == 0)
		return;
	
	// locks the mutex so that display manager and physics cannot access the gameobject_list while the scene performs operations on it 
	std::lock_guard<std::mutex> lock(_gameObject_list_mutex);
	// duplicates the object list so that if changes are made to the original list the duplicate does not get affected
	auto temporyGameObjList = _gameObject_list;	
	// loops through each game object and runs their Update Function
	for(auto GO : temporyGameObjList)
	{
		GO->Update();
	}
}
// returns the game object list
std::list<std::shared_ptr<GameObject>> Scene::getGameObjectList() const
{
	return _gameObject_list;
}
// Adds a GameObject pointer to the current list of gameobjects in the scene
void Scene::Instantiate(std::shared_ptr<GameObject> gameObj)
{
	gameObj->Start();
	// sets the scene of the gameobject to the scene that it was added to
	gameObj->setScene(shared_from_this());
	_gameObject_list.push_back(gameObj);
}
// Removes the specific gameObject from the current list of gameobjects
void Scene::DestroyGameObject(std::shared_ptr<GameObject> gameObj)
{
	// iterates through the _gameObject list until it finds the specific game object
	// std remove does not work
	for(auto idx = _gameObject_list.begin(); idx != _gameObject_list.end(); idx++)
	{
		// checks if the deferenence of the idx is that same as the parameter
		if(*idx == gameObj)
		{
			// Erases the object from the list of gameobjects
			_gameObject_list.erase(idx);
			break;
		}
	}
}