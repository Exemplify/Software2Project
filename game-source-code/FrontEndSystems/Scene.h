#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <memory>
#include "GameObject.h"
#include <mutex>

/**
 * @class Scene
 * @brief Scene is used to store and operate on the various gameobjects that define the functionality of the current scene
 * @details A scene object is used to contain each of the gameobjects that will be required for the current scenes functionallity.
 * Each scene represents a different functionallity of the game. This includes the a splash Screen and the main scene.
 * The Scene is responsible for running the Update on each gameobject that is stored within it. The active scene passes information about the
 * current state of the game to the Collision Detection and Display Manager Classes.
 */
 
class Scene: public std::enable_shared_from_this<Scene>
{
public:
	/**
	 * @brief Runs the Update function of all of the GameObjects stored within Scene 
	 */
	void SceneUpdate();
	/**
	 * @brief Adds the specified GameObject pointer to the scene
	 * @param gameObj The specific GameObject that is added to the Scene
	 */
	virtual void Instantiate(shared_ptr<GameObject> gameObj);
	
	/**
	 * @brief Removes the current Instance of the GameObject from the Scene
	 * @param gameObject The GameObject instance that is removed
	 */
	void DestroyGameObject(std::shared_ptr<GameObject> gameObject);
	/**
	 * @brief Returns the List of GameObjects stored to provide 
	 * the collisionDetection and DisplayManager with neccessary information
	 * @return The List of GameObjects Stored within the Scene Object
	 */
	std::list<std::shared_ptr<GameObject>> getGameObjectList() const;
	std::mutex _gameObject_list_mutex; /**<The mutex object used to enusre that the GameObject list is not accessed by the different threads at the same time*/
	
private:
	std::list<std::shared_ptr<GameObject>> _gameObject_list; /**<A doubly linked list used to store the various game objects of the */
};

#endif