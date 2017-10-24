#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include <memory>
#include <string>

#include "../BackEndSystems/Input.h"
#include "../Vector2D.h"
#include "GraphicObject.h"

// Forward declaration of scene as both objects need to know about each other
class Scene;

/**
 * @class DestroyedObjectOutsideScene
 * @brief Exception that is thrown when an object is destroyed and it does not exist inside of a Scene 
 */
class DestroyedObjectOutsideScene{};


/**
* The Various GameObjectTypes that exist within the game
*/
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
	/**
	* @brief Default Constructor - Creates the object using default values
	* 
	*/
	GameObject();
	/**
	* @brief Constructs an object with a specific GraphicObject 
	* @param graphic defines the GameObjects GraphicObject composition
	*/
	GameObject(const GraphicObject& graphic);
	/**
	* @brief Constructs an object with a specific scale
	* @param scale The desired scale for the GameObject
	*/
	GameObject(const xyVector& scale);
	/**
	* @brief Constructs an object with a specific starting position
	* @param startingPosition The desired starting position for the GameObject
	*/
	GameObject(const Vector2D& startingPosition);
	/**
	 * @brief Constructor used to specify the main members of the gameobject
	 */
	GameObject(const Vector2D& startingPosition, const xyVector& scale, const GraphicObject& graphicObject);
	
	// default copy constructor is used the specific instance of scene needs to be shared when copying the game object, it should not create a new one
	
	/**
	 * @brief Used for initialisation of the objects parameters when it is instantiated.
	 * @details Start is used to define the various intitialisation parameters that an object may require to be set before it exists inside of the game scene. The Scene Object calls this 
	 * function when it is instantiated
	 */
	virtual void Start() {}
	/**
	 * @brief Update is a virtual method that is used to interface with the Back End System of the Game operations. 
	 * @details Update is managed by the scene object which iterates through the list of GameObjects composed within it. For each GameObject the Update function is called once per frame. 
	 * This function is overriden by the various derived classes, it is given a default return that does nothing, this enables derived classes to implement it only when necessary.
	 */
	virtual void Update() {}
	
		// class getters //
	// The getters are used to ensure that there is a decoupling between sfml and the game logic of the system
	// the gameObjects do not need to have information about the display manager and gameManger but these classes require the information 
	// about the gameobjects.
		
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
	/**
	 * @brief Sets the active state of the GameObject, if it is unactive it does not update, get displayed by the game or cause collisions 
	 * @param active_state the desired state of the Gameobject
	 */
	void setActive(bool active_state) {_active = active_state;}
	/**
	 * @brief sets the Scene pointer of the Gameobject, used to know which Scene the GameObject exists in  
	 * @param scene The Scene pointer that is copied
	 */
	void setScene(std::shared_ptr<Scene> scene) {_scene = scene;}
	
	virtual ~GameObject() = default;
protected:
	xyVector _scale; /**<xyVector representing the scale of the object*/
	std::shared_ptr<Scene> _scene; /**<The Scene that the object exists in*/
	GameObjectType _type; /**<The GameObjectType representation of the object*/
	Vector2D _position; /**<The Vector2D composition used to represent the objects position in the game's Vector space*/
	GraphicObject _graphicObject; /**<The GraphicObject composition used to identify the specific Sprite the GameObject*/
	bool _active = true; /**<Returns the active state of the object, does not get displayed or updated when not active*/
	
	/**
	 * @brief Searches the list of available GameObjects from the Scene object and returns the first object that matches the specifc GameObjectType.
	 * @param searchType The GameObjectType that is being searched for, used to find a specific object of a specific type.
	 * @return Returns a pointer to the object of the desired type.
	 */
	std::shared_ptr<GameObject> FindGameObjectByType(GameObjectType searchType); 
	/**
	 * @brief Removes the current GameObject from the GameObject list stored within the current scene. Ensures that the object does not get updated 
	 * or displayed by the Presentation layer, will be removed from memory once the remaining pointers go out of scope.
	 */
	void Destroy();
};

#endif