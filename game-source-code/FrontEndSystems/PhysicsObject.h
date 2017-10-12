#ifndef PHYSICS_OBJ_H
#define PHYSICS_OBJ_H

#include "GameObject.h"

#include "../Vector2D.hpp"
#include "MovableObject.h"

/// May not need to inherit from GameObject 
class PhysicsObject : public GameObject
{
public:
    // Constructor
    PhysicsObject()
    {
        _type = GameObjectType::physicsObject;
    }
    PhysicsObject(double objectSpeed, Vector2D<double> position):
    _objectSpeed{objectSpeed}
    {
		_type = GameObjectType::physicsObject; 
	}
    //Commands
    //set speed of the physics object
    void setSpeed(double newSpeed) {_objectSpeed = newSpeed;}
    
    //Queries
    double getSize() {return _objectSize;}
    
    virtual void collisionAction(GameObjectType objectType) = 0;
    
    //Destructor
    virtual ~PhysicsObject() {}
    
protected:
    double _objectSpeed;
    double _objectSize;
};

#endif