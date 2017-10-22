#include "PhysicsObjectFactory.h"
#include "../FrontEndSystems/PhysicsObject.h"

std::shared_ptr<GameObject> PhysicsObjectFactory::getGameObject(const std::shared_ptr<DatabaseInterface>& database)
{
	auto objectdata = getObjectData(database);
	auto gameObject = GameObjectFactory::getGameObject(database);
	return std::make_shared<PhysicsObject> (*gameObject, objectdata.collider_size);
}