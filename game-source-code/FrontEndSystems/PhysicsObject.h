#ifndef PHYSICS_OBJ_H
#define PHYSICS_OBJ_H

#include "GraphicObject.h"
#include "../Vector2D.hpp"
#include "MovableObject.h"

class PhysicsObject : public GraphicObject
{
public:
    // Constructor
    PhysicsObject()
    {
        _type = GameObjectType::physicsObject;
    }
    PhysicsObject(double objectSpeed, std::shared_ptr<SpriteInfo> spriteInfo, Vector2D<double> position):
    GraphicObject(),
    _objectSpeed{objectSpeed}
    { _type=GameObjectType::physicsObject; }
    
    //Commands
    //set speed of the physics object
    void setSpeed(double newSpeed) {_objectSpeed = newSpeed;}
    
    //Queries
    double getSize() {return _objectSize;}
    
    virtual void collisionAction(GameObjectType objectType) {}
    
    //Destructor
    virtual ~PhysicsObject() {}
    
protected:
    double _objectSpeed;
    double _objectSize;
};

#endif