#ifndef PHYSICS_OBJ_H
#define PHYSICS_OBJ_H

#include "GameObject.h"

#include "../Vector2D.h"
#include "MovableInterface.h"

class PhysicsObject : public GameObject
{
public:

	PhysicsObject();
	PhysicsObject(const GameObject& gameObject const double& objectSpeed, const double& objectSize);
	
    double getSize();
    
	virtual void collisionAction(GameObjectType objectType) {}

	virtual ~PhysicsObject() = default;
    
protected:
	double _objectSize;
};

#endif