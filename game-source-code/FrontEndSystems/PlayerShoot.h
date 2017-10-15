#ifndef PLAYER_SHOOT_H
#define PLAYER_SHOOT_H
#include "ShootInterface.h"

class PlayerShoot : public ShootInterface
{
protected:
	virtual std::shared_ptr<Projectile> getProjectile() override;
};

#endif