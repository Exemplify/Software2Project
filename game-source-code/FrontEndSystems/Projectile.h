#ifndef PROJ_H
#define PROJ_H
#include "PhysicsObject.h"
#include "Boundary.h"

const double PLAYER_PROJECTILE_DESTROY_REGION = 10;

class Projectile: public PhysicsObject
{
public:
	Projectile(){}
	Projectile(GameObjectType projectileType) 
	{
		_type = projectileType;
	}
	Projectile(std::shared_ptr<SpriteInfo> spriteInfo, GameObjectType projectileType);
	Projectile(const Projectile& copyProjectile);
	virtual void Update() override;
	void Initialise(Vector2D<double> startingPos, Vector2D<double> direction, double moveSpeed);
    virtual void collisionAction(GameObjectType objectType) override;
	virtual Projectile* Clone() override 
	{return new Projectile(*this);}
	~Projectile() override{}
private:
	Vector2D<double> _direction;
	Boundary _enemyDestroyBounds;
	Boundary _playerDestroyBounds;
	double _moveSpeed;
	void DestroySelf();
	void Move();
	void DestroyPlayerProjectile();
	void DestroyEnemyProjectile();
};

#endif
