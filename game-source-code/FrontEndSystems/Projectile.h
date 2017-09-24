#ifndef PROJ_H
#define PROJ_H
#include "GraphicObject.h"
#include "Boundary.h"

const double PLAYER_PROJECTILE_DESTROY_REGION = 10;

class Projectile: public GraphicObject
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
