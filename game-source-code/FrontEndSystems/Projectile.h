#ifndef PROJ_H
#define PROJ_H
#include "PhysicsObject.h"
#include "MovableInterface.h"
#include "SizeReduction.h"
#include "Boundary.h"

/**
 * @class Projectile
 * @brief The base class for all the projectiles that exist within the game
 * @details uses the template design pattern to define functionality that is shared 
 * between the different projectiles and has pure virtual functions that must be overriden to allow for different variants of projectiles
 */
class Projectile: public PhysicsObject
{
public:
	/**
	 * @brief Default Constructor of the projectile abstract class that is used to create a mock projectile object for testing purposes
	 */
	Projectile();
	/**
	 * @brief Constructs the base projectile with the various members that it requires 
	 * @param physicsObject The base physics object copies the properties defined
	 * @param move A MovableInterface object that defines the various ways that the projectile can move
	 * @param destroyBounds The boundary that defines when the projectile is destroyed
	 */
	Projectile(const PhysicsObject& physicsObject, const std::shared_ptr<MovableInterface>& move, const Boundary& destroyBounds);
	/**
	 * @brief Intialises the objects members, use of final prevents any derived objects from overriding the function
	 */
	virtual void Start() final;
	/**
	 * @brief Used to Update the various members of the class, called once per frame
	 * @details This implementation of Update is used to move the object, reduced its scale based on the proximity to the centre of the screen
	 * and check if it should be destroyed. 
	 */
	virtual void Update() final;
	/** 
	* @brief used to define the characteristics of the projectile once is has been created by the copy constructor
	* @details This is necessary because the start position and direction of the projectile are assigned during runtime
	*/
	virtual void Initialise(const Vector2D& startingPos, const Vector2D& direction);

	virtual ~Projectile() override = default;

protected:
	/**
	 * @brief Used to identify when the object needs to destroy itself
	 * @details This is usually called when the object goes out of the defined boundary that it exists in 
	 */
	virtual void DestroySelf() = 0;
	Boundary _destroyBounds; /**<The boundary that is used to identify when the projectile should be destroyed*/
private:
	std::shared_ptr<MovableInterface> _moveComp; /**<Defines the particular movement pattern for the projectile*/
	SizeReduction _sizeReduction; /**<Changes the size of the projectile with relation to the proximity of the object to the centre of the screen*/
};

#endif
