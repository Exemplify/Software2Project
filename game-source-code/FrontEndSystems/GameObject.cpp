#include "GameObject.h"
#include "Scene.h"

GameObject::GameObject(): 
_type{GameObjectType::gameObject},
_scale{Vector2D<double>(1,1, VectorType::xyp)}
{}

GameObject::GameObject(Vector2D<double> startingPosition): 
_type{GameObjectType::gameObject},
_position{startingPosition},
_scale{1,1,VectorType::xyp}
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