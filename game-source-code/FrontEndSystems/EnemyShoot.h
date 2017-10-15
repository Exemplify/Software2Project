#ifndef ENEMY_SHOOT_H
#define ENEMY_SHOOT_H
#include "ShootInterface.h"

class EnemyShoot : public ShootInterface
{
protected:
	virtual std::shared_ptr<Projectile> getProjectile() override;
};

#endif