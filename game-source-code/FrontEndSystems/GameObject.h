#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include <memory>
#include <string>

#include "../BackEndSystems/Input.h"
#include "../Vector2D.hpp"

class Scene;

// ensures that an object cannot be destroyed when it should only exist from within a scene
class DestroyedObjectOutsideScene{};
// The different object types used to identify whic object to draw and to 
// determine when a specific collision has occured
struct xyVector
{
	double x;
	double y;
};
enum class GameObjectType
{
	gameObject,
	enemyController,
	graphicObject,
    physicsObject,
	player,
	enemy,
	playerBullet,
	enemyBullet
};
class GameObject: public std::enable_shared_from_this<GameObject>
{
public:
		// Constructors //
	/// default constructor should be removed however is useful for testing
	GameObject();
	GameObject(const GameObject& copyObj);
	GameObject(Vector2D<double> startingPosition);
	
		// virtual callbacks for the class //
	// start is called when the GameObject is initiliased into the scene 
	/// may not be necessary as it has not been used and the constructor is usually used to initialise information
	virtual void Start() {}
	// Update is called once each frame within the game
	/// could aslo be used as a friendship with scene
	virtual void Update() {}
	
		// class getters //
	// The getters are used to ensure that there is a decoupling between sfml and the game logic of the system
	// the gameObjects do not need to have information about the display manager and gameManger but they require the information 
	// about the gameobjects. This means getter functions are essential
		
	// Returns the active state of the object
	bool isActive() {return _active;}
	// Returns the current possiton of the object
	Vector2D<double> getPosition() const {return _position;}
	// Returns the Gameobject type
	GameObjectType getType() const {return _type;}
	// Returns the scene the object is stored in
	std::shared_ptr<Scene> getScene() const {return _scene;}
	xyVector getScale() const { return _scale;}
		// class setters //
		
	// sets the state of the current game object
	void setActive(bool active_state) {_active = active_state;} 
	/// needs to be reconsidered only Scene class needs access to this method
	/// may be worthwhile making a frienship class here to ensure a tightly coupled relationship between scene and gameobject
	/// Need to ask about this
	/// Edit: Game Obejct should never exist outside of a scene so should require a scene object in the constructor
	void setScene(std::shared_ptr<Scene> scene) {_scene = scene;}
	
	// covarient return type so that the gameobject list can be copied successfully
	// this is necessary for to create a copy of the original active scene so that the game can be reloaded
	// smart pointers unfortunately cannot be used
	virtual GameObject* Clone() 
	{return new GameObject(*this);}
	// class invariance that a gameobject must be destroyed in a specific way 
	void Destroy();
	virtual ~GameObject(){}
protected:
	xyVector _scale;
	// smart pointer to the scene the game object exists in this should not be changed, is an invarient
	std::shared_ptr<Scene> _scene;
	// Invariance that _type should never be null
	GameObjectType _type;
	// the Vector space position of the object
	Vector2D<double> _position;
	// used to inform the system not to display the object or call the its update function
	// is not removed from the scene so another object can set it active if need be
	bool _active = true;
	// function used to return the current object inside of the scene that the gameobject exists in 
	std::shared_ptr<GameObject> FindGameObjectByType(GameObjectType searchType); 
};

#endif