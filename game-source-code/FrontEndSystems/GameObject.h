#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include <memory>
#include <string>

#include "../BackEndSystems/Input.h"
#include "../Vector2D.hpp"

class Scene;

class DestroyedObjectOutsideScene{};
enum class GameObjectType
{
	gameObject,
	graphicObject,
	player,
	enemy,
	playerBullet,
	enemyBullet
};
class GameObject: public std::enable_shared_from_this<GameObject>
{
public:
		// Constructors //
	GameObject();
	GameObject(Vector2D<double> startingPosition);
	
		// virtual callbacks for the class //
	// start is called when the GameObject is initiliased into the scene 
	virtual void Start() {}
	// Update is called once each frame within the game
	virtual void Update() {}
	
		// class getters //
		
	// Returns the active state of the object
	bool isActive() {return _active;}
	// Returns the current possiton of the object
	Vector2D<double> getPosition() const {return _position;}
	// Returns the Gameobject type
	GameObjectType getType() const {return _type;}
	// Returns the scene the object is stored in
	std::shared_ptr<Scene> getScene() const {return _scene;}
	
		// class setters //
		
	// sets the state of the current game object
	void setActive(bool active_state) {_active = active_state;} 
	void setScene(std::shared_ptr<Scene> scene) {_scene = scene;}

	
	// class invariance that a gameobject must be destroyed in a specific way 
	void Destroy();
	virtual ~GameObject(){}
protected:
	std::shared_ptr<Scene> _scene;
	// Invariance that _type should never be null
	GameObjectType _type;
	Vector2D<double> _position;
	bool _active = true;
};

#endif