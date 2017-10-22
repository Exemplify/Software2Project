#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(const GameObject& gameObject, const double& objectSize):
GameObject{gameObject},
_objectSize{objectSize}
{
	_type = GameObjectType::physicsObject;
}

double PhysicsObject::getSize() const 
{
	return _objectSize;
}
void PhysicsObject::collisionAction(const GameObjectType& objectType)
{}