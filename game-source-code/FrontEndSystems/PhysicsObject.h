#ifndef PHYSICS_OBJ_H
#define PHYSICS_OBJ_H

#include "GameObject.h"

#include "../Vector2D.h"
#include "MovableInterface.h"

/**
 * @class PhysicsObject
 * @brief Acts as the main interface between the collisionDetection and the game logic.
 * @details Provides the size for the collisionDetection to check as well as a function call for when a collision occurs.
 */
class PhysicsObject : public GameObject
{
public:
	/**
	 * @brief Default Constructor
	 */
	PhysicsObject();
	/**
	 * @brief Constructs the physics object based on the parameters provided
	 * @param gameObject A copy of the gameobject is made and is applied to the object
	 * @param objectSize The radial size of the object and its area of collision
	 */
	PhysicsObject(const GameObject& gameObject, const double& objectSize);
	/**
	 * @brief gets the current size of the object 
	 * @return Returns the object size
	 */
    double getSize() const;
    /**
     * @brief Virtual function that is called whenever a collision occurs between this object and a different one
     * @param objectType The GameObjectType of the object that was collided with
     */
	virtual void collisionAction(const GameObjectType& objectType);

	virtual ~PhysicsObject() = default;
    
protected:
	double _objectSize; /**<The radial collision size of the object*/
};

#endif