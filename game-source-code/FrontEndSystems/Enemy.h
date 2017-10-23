#ifndef ENEM_H
#define ENEM_H
#include "PhysicsObject.h"
#include "DelayComponent.h"
#include "ShootInterface.h"
#include "Boundary.h"
#include "GraphicObject.h"
#include "SizeReduction.h"
#include "MovableInterface.h"
#include "EnemyController.h"

/// Needs to be changed into a polymorphic interaction where different characters define different movement types
/// requires a large amount of redesign for a better implementation
/// Needs a copy constructor and assignment opperator
class Enemy: public PhysicsObject
{
public:
	/**
	 * @brief Constructs the main enemy object used within the game
	 * @param physicsObject The physics object information used to construct the enemy 
	 * @param shootDelay The DelayComponent specified between enemy shots 
	 * @param moveComp the MovableInterface that the enemy uses 
	 * @param shootComp The ShootInterface used by the enemy
	 */
	Enemy(const PhysicsObject& physicsObject, const double& shootDelay,
									const std::shared_ptr<MovableInterface>& moveComp, const std::shared_ptr<ShootInterface>& shootComp);
	/**
	 * @brief Used to initialise the Enemy 
	 * @details ensures that the enemy is scaled correctly before it is displayed, and generates a random direction for its movement
	 */
	virtual void Start() override; 
	/**
	 * @brief Runs once a frame and updates the various methods and members of the enemy
	 */
	virtual void Update() override;
	/**
	 * @brief Checks if the enemy has collided with a player or player projectile and responds accordingly
	 * @param objectType The type of object that has collided with the enemy
	 */
    virtual void collisionAction(const GameObjectType& objectType) override;
	/**
	 * @brief Assigns an enemy controller to the specific enemy, used to communicate with the enemy controller so that it knows whenever an enemy is destroyed
	 * @param enemyController shared pointer to the EnemyController that created the enemy
	 */
	void AssignEnemyController(const std::shared_ptr<GameObject>& enemyController);
	/**
	 * @brief Default Destructor
	 */
	virtual ~Enemy() = default;
private:
	// Private Members 
	DelayComponent _shootDelay; /**< delay used between each shot per object*/
	std::shared_ptr<ShootInterface> _enemyShoot; /**<ShootInterface used to specify the specific type of shooting*/
	// Boundary object used to detect when the object is outside the screen
	Boundary _screenBounds; /**<Default boundary used to test if the enemy is outside of the screen*/
	SizeReduction _sizeReduction; /**<SizeReduction component used to scale the enemy as it moves towards or away from the centre of the screen*/
	std::shared_ptr<MovableInterface> _moveComp; /**<MoveableInterface used to move the enemy in a specific way*/
	std::shared_ptr<EnemyController> _enemyController; /**<EnemyController used to create the enemy object, is notified when the Enemy object is destroyed*/
	
	//Private Methods
	/**
	 * @brief Determines if the shootDelay is finished, if it is an EnemyProjectile is created using the shootComp
	 */
	void Shoot();
	/**
	 * @brief Checks if the enemy is out of screen bounds 
	 */
	void CheckOutsideScreen();
	/**
	 * @brief Generates the random direction for the object to move in
	 * @return Returns the generated random direction 
	 */
	Vector2D GenerateRandomMoveDirection();
	/**
	 * @brief The Response of an EnemyObejct to colliding with the player or the player bullet
	 */
	void PlayerProjectileCollision();
};


#endif 