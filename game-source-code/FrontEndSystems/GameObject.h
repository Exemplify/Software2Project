#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include <memory>
#include <string>

#include "../BackEndSystems/Input.h"
#include "../Vector2D.h"
#include "GraphicObject.h"

class Scene;

// ensures that an object cannot be destroyed when it should only exist from within a scene
class DestroyedObjectOutsideScene{};
// The different object types used to identify whic object to draw and to 
// determine when a specific collision has occured

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

/**
 * @class GameObject
 * @brief The base class that is used for all game logic systems
 * @details Gameobject is used as a base class from which the various types of game logic elements are derived from. Every game object exist inside of the game space this invariance 
 * means that every game object must have a vector position. The position is used by the Presentation Layer (DisplayManager) and the CollisionDetection. 
 * GameManager and Scene work together to call the update function for each GameObject which acts as the Domain Layer. The virtual functions are overriden by the derived classes to define specific game behaviour.
 */
class GameObject: public std::enable_shared_from_this<GameObject>
{
public:
		// Constructors //
	GameObject();
	GameObject(GraphicObject graphic);
	GameObject(xyVector scale);
	GameObject(const GameObject& copyObj);
	GameObject(Vector2D startingPosition);
	GameObject(Vector2D startingPosition, xyVector scale, GraphicObject graphicObject);
	
//	bool operator==(const GameObject& rhs) const;
	
	/**
	 * @brief Update is a virtual method that is used to interface with the Back End System of the Game operations. 
	 * @details Update is managed by the scene object which iterates through the list of GameObjects composed within it. For each GameObject the Update function is called once per frame. 
	 * This function is overriden by the various derived classes, it is given a default return that does nothing, this enables derived classes to implement it only when necessary.
	 */
	virtual void Update() {}
	
		// class getters //
	// The getters are used to ensure that there is a decoupling between sfml and the game logic of the system
	// the gameObjects do not need to have information about the display manager and gameManger but they require the information 
	// about the gameobjects. This means getter functions are essential
		
	/**
	 * @brief get function that allows a client to determine if the GameObject is active
	 * @return Returns the boolean that represents the GameObjects active state
	 */
	bool isActive() {return _active;}
	/**
	 * @brief get function used to return the Position of the object, used in the collisionDetection calculations and the presentation layer
	 * @return Returns the Vector2D composition object 
	 */
	Vector2D getPosition() const {return _position;}
	/**
	 * @brief get function used to return the GameObjectType of the object, used in the collisionDetection calculations
	 * @return Returns the xyVector composition object 
	 */
	GameObjectType getType() const {return _type;}
	/// Possibly Redundant
	std::shared_ptr<Scene> getScene() const {return _scene;}
	
	/**
	 * @brief get function used to return the scale of the object, used in the presentation layer
	 * @return Returns the xyVector composition object 
	 */
	const xyVector& getScale() const { return _scale;}

	/**
	 * @brief Returns the GraphicObject of the current GameObject to interface with the presentation layer
	 * @return Returns the GraphicObject composition object
	 */
	virtual const GraphicObject& getGraphicObject() const;
	
	
	
		// class setters //
	
	// sets the state of the current game object
	void setActive(bool active_state) {_active = active_state;} 
	/// needs to be reconsidered only Scene class needs access to this method
	/// may be worthwhile making a frienship class here to ensure a tightly coupled relationship between scene and gameobject
	/// Need to ask about this
	/// Edit: Game Object should never exist outside of a scene so should require a scene object in the constructor
	void setScene(std::shared_ptr<Scene> scene) {_scene = scene;}
	
	/**
	 * @brief Removes the current GameObject from the GameObject list stored within the current scene. Ensures that the object does not get updated 
	 * or displayed by the Presentation layer.
	 */
	void Destroy();
	virtual ~GameObject(){}
protected:
	xyVector _scale; /**<xyVector representing the scale of the object*/
	// smart pointer to the scene the game object exists in this should not be changed, is an invarient
	std::shared_ptr<Scene> _scene; /**<The Scene that the object exists in*/
	// Invariance that _type should never be null
	GameObjectType _type; /**<The GameObjectType representation of the object*/
	// the Vector space position of the object
	Vector2D _position; /**<The Vector2D composition used to represent the objects position in the game's Vector space*/
	GraphicObject _graphicObject; /**<The GraphicObject composition used to identify the specific Sprite the GameObject*/
	bool _active = true; /**<Returns the active state of the object, does not get displayed or updated when not active*/
	
	/**
	 * @brief Searches the list of available GameObjects from the Scene object and returns the first object that matches the specifc GameObjectType.
	 * @param searchType The GameObjectType that is being searched for, used to find a specific object of a specific type.
	 * @return Returns a pointer to the object of the desired type.
	 */
	std::shared_ptr<GameObject> FindGameObjectByType(GameObjectType searchType); 
};

#endif