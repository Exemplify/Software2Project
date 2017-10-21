#include "PhysicsObject.h"


PhysicsObject::PhysicsObject()
{
	_type = GameObjectType::physicsObject;
}
PhysicsObject::PhysicsObject(const GameObject& gameObject const double& objectSpeed, const double& objectSize):
GameObject(gameObject),
_objectSpeed{objectSpeed},
_objectSize{objectSize}
{
	_type = GameObjectType::physicsObject;
}

double PhysicsObject::getSize() 
{
	return _objectSize;
}