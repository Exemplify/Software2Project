#ifndef SHOOT_H
#define SHOOT_H
#include "../Vector2D.hpp"
#include "Scene.h"
#include "Projectile.h"

class ShootComponent
{
public:
	ShootComponent(const Projectile& bullet);
	void Shoot(	
		Vector2D<double> target,
		Vector2D<double> startPosition, 
		double shootSpeed,
		Scene& scene
		);
private:
	Projectile _bulletType;
};

#endif