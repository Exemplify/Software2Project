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
	Scene(){}
	Scene(const Scene& rhs);
	// Runs the Update function within each gameobject
	void SceneUpdate();
	// Adds a gameobject to the list objects in the scene
	void Instantiate(shared_ptr<GameObject> gameObj);
	void DestroyGameObject(gameObj_ptr gameObject);
	std::vector<gameObj_ptr> getGameObjectList() const;
	
	// mutex declaration
	std::mutex _gameObject_list_mutex;
	
	// equals operator overload
	Scene& operator = (const Scene& rhs);
private:
	std::vector<gameObj_ptr> _gameObject_list;
};

#endif