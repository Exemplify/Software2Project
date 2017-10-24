#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../FrontEndSystems/Scene.h"
/**
 * @class CollisionDetection
 * @brief Determines when PhysicsObjects have collided with each other.
 * @details Runs in a seperate thread and copies the list of GameObjects stored within the Scene 
 */
class CollisionDetection
{
public:
	/**
	* @brief Constructs the CollisionDetection object with the specific RenderWindow that is required to create a CollisionDetection loop
	* @param dispWindow The RenderWindow that is used for the game loop
	*/
    CollisionDetection(sf::RenderWindow* dispWindow);
	/**
	 * @brief Initialises the CollisionDetection thread
	 */
    void InitializeCollisionThread();
private:
    sf::RenderWindow* _dispwindow_ptr; /**<pointer to the RenderWindow used for the game*/
    
	// Private Methods
	/**
	 * @brief Contains the Collision Detection loop, checks for collisions on each iteration of the loop
	 */
	void runCollisionThread(); 
	/**
	 * @brief Loops through each GameObject and determines if it has collided with a different one
	 */
    void checkCollisions();
	/**
	 * @brief Checks if the two PhysicsObjects have collided with each other by dynamically casting the provided GameObjects
	 * @param gameObj1 primary GameObject, if a collision has occured collisionOccured is called
	 * @param gameObj2 secondary GameObject, used to check if collision has occure with primary GameObject
	 */
    void checkObjects(std::shared_ptr<GameObject> gameObj1, std::shared_ptr<GameObject> gameObj2);
};

#endif