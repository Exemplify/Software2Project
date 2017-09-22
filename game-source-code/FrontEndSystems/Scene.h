#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>


#include "GameObject.h"

using gameObj_ptr = std::shared_ptr<GameObject>;

class Scene
{
public:
	// Runs the Update function within each gameobject
	void SceneUpdate();
	// Adds a gameobject to the list objects in the scene
	void Instantiate(GameObject* gameObj);
	void Instantiate(shared_ptr<GameObject> gameObj);
	void DestroyGameObject(gameObj_ptr& gameObject);
	std::vector<gameObj_ptr> getGameObjectList() const;
	bool getUpdateList() const {return _updatingList;}
private:
	std::vector<gameObj_ptr> _gameObject_list;
	bool _updatingList = false;
};

#endif