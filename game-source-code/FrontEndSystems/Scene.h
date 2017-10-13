#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <memory>
#include "GameObject.h"
#include <mutex>

/// Aliases need to be defined in a better way, possibly using a typedef
using gameObj_ptr = std::shared_ptr<GameObject>;

/*
 * Scene Description 
 * A scene object is used to contain each of the gameobjects that will be required for the current scenes functionallity.
 * Each scene represents a different functionallity of the game. This includes the a splash Screen and the main scene.
 * The Scene is responsible for running the Update on each gameobject that is stored within it. The active passes information about the
 * current state of the game to the Collision Detection and Display Manager Classes. It acts as the a bridging class between the display 
 * and the game logic
 */
class Scene: public std::enable_shared_from_this<Scene>
{
public:
	Scene(){}
	// Runs the Update function within each gameobject
	void SceneUpdate();
	// Adds a gameobject to the list objects in the scene
	void Instantiate(shared_ptr<GameObject> gameObj);
	// Removes the corresponding shared_ptr from the gameobject list
	void DestroyGameObject(gameObj_ptr gameObject);
	// returns the current list of all the game objects in the specific scene
	std::list<gameObj_ptr> getGameObjectList() const;
	
	// mutex declaration
	std::mutex _gameObject_list_mutex;
	
	// equals operator overload
	Scene& operator = (const Scene& rhs);
private:
	// Vector containing all of the gameObjects in the current scene
	/// would be better to use a doubly linked list instead of a list since it has a better time effeciency 
	/// when it deals with insertion and deletion of elements
	std::list<gameObj_ptr> _gameObject_list;
};

#endif