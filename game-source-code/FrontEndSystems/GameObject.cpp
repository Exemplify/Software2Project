#include "GameObject.h"
#include "Scene.h"

GameObject::GameObject(): 
_type{GameObjectType::gameObject}
{}
GameObject::GameObject(const GameObject& copyObj)
{
	_type = copyObj._type;
	_position = copyObj._position;
	_active = copyObj._active;
	_scene = copyObj._scene;
}
GameObject::GameObject(Vector2D<double> startingPosition): 
_type{GameObjectType::gameObject},
_position{startingPosition}
{}
void GameObject::Destroy()
{
	if(_scene != NULL)
	{
		std::shared_ptr<GameObject> thisObj = shared_from_this();
		_scene->DestroyGameObject(thisObj);
	}
	else
	{
		throw(DestroyedObjectOutsideScene());
	}
}

std::shared_ptr<GameObject> GameObject::FindGameObjectByType(GameObjectType searchType)
{
	auto gameObjList = _scene->getGameObjectList();
	for(auto& GO: gameObjList)
	{
		if(GO->getType() == searchType)
			return GO;
	}
	return NULL;
}