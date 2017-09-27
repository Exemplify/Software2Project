#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>
#include "GameObject.h"
#include <mutex>


using gameObj_ptr = std::shared_ptr<GameObject>;

class Scene: public std::enable_shared_from_this<Scene>
{
public:
	// Runs the Update function within each gameobject
	void SceneUpdate();
	// Adds a gameobject to the list objects in the scene
	void Instantiate(shared_ptr<GameObject> gameObj);
	void DestroyGameObject(gameObj_ptr gameObject);
	std::vector<gameObj_ptr> getGameObjectList() const;
	bool UpdatingList() const {return _updatingList;}
	std::mutex _gameObj_list_mutex;
private:
	std::vector<gameObj_ptr> _gameObject_list;
	bool _updatingList = false;
};

#endif