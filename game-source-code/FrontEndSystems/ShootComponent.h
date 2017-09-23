#ifndef SHOOT_H
#define SHOOT_H
#include "../Vector2D.hpp"
#include "Scene.h"
#include "Projectile.h"

class ShootComponent
{
public:
	ShootComponent(){}
	ShootComponent(std::shared_ptr<SpriteInfo> bulletInfo, GameObjectType bulletType);
	ShootComponent(std::shared_ptr<Projectile> bullet);
	void Shoot(	
		Vector2D<double> target,
		Vector2D<double> startPosition, 
		double shootSpeed,
		Scene& scene
		);
private:
	std::shared_ptr<Projectile> _bullet;
};

#endif