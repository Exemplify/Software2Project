#ifndef PROJ_H
#define PROJ_H
#include "PhysicsObject.h"
#include "Boundary.h"

/// needs to be moved into a database
const double PLAYER_PROJECTILE_DESTROY_REGION = 10;
/// Object needs to be converted into a polymorphic object, one for player and one for enemy with virtual destorys and boundaries
/// corresponds to the type information in a better way
class Projectile: public PhysicsObject
{
public:
	/// Constructors need to be redesigned 
	Projectile(){}

	Projectile(GameObjectType projectileType) 
	{
		_type = projectileType;
	}
	// constructor used to identify whether the gameobject type is an enemy projectile or a player projectile 
	// with the corresponding graphical information
	Projectile(std::shared_ptr<GraphicObject> bulletGraphic, GameObjectType projectileType, xyVector scale);
	// copy constructor used by the shoot coponent to create copys of a standard projectile
	Projectile(const Projectile& copyProjectile);
	// Overrides Update function for specific responsibilities 
	virtual void Update() override;
	// used to define the characteristics of the projectile once is has been created by the copy constructor
	// this is necessary because the start position of each projectile is always changing
	void Initialise(Vector2D<double> startingPos, Vector2D<double> direction, double moveSpeed);
	// Override function used to determine when a collision has occured with the specific object types
    virtual void collisionAction(GameObjectType objectType) override;
	// returns the graphic object
	virtual const std::shared_ptr<GraphicObject> getGraphicObject() override {return _bulletGraphic;}
	/// Clone Function Still in development
	virtual Projectile* Clone() override 
	{return new Projectile(*this);}
	// virtual Destructor
	/// Needs the virtual tag
	~Projectile() override{}
private:
	// Projectile direction
	Vector2D<double> _direction;
	std::shared_ptr<GraphicObject> _bulletGraphic;
	/// Need to remove both boundaries, should be passed through the constructor redundant information
	Boundary _enemyDestroyBounds;
	Boundary _playerDestroyBounds;
	// projectile movement speed
	double _moveSpeed;
	/// should be virtual 
	void DestroySelf();
	void Move();
	
	void DestroyPlayerProjectile();
	void DestroyEnemyProjectile();
};

#endif
