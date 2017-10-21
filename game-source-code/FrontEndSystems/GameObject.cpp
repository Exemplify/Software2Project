#include "GameObject.h"
#include "Scene.h"

// default constructor ensures that every gameobject has a type
GameObject::GameObject(): 
_type{GameObjectType::gameObject}
{}

GameObject::GameObject(const Vector2D& startingPosition): 
_type{GameObjectType::gameObject},
_position{startingPosition}
{}
GameObject::GameObject(const GraphicObject& graphic):
_graphicObject{graphic}
{}
GameObject::GameObject(const xyVector& scale):
_scale{scale}
{}
GameObject::GameObject(const Vector2D& startingPosition, const xyVector& scale, const GraphicObject& graphicObject):
_scale{scale},
_type{GameObjectType::gameObject},
_position{startingPosition},
_graphicObject{graphicObject}
{}

// Removes the gameobject from the scene that it exists in
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
const GraphicObject& GameObject::getGraphicObject() const
{
	return _graphicObject;
} 
// checks the list of gameObjects inside the current scene and returns the first gameobject that matches the GameObjectType
std::shared_ptr<GameObject> GameObject::FindGameObjectByType(GameObjectType searchType)
{
	auto gameObjList = _scene->getGameObjectList();
	for(auto& GO: gameObjList)
	{
		if(GO->getType() == searchType)
			return GO;
	}
	// returns a NULL pointer if the object is not found
	return NULL;
}