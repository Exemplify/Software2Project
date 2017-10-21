#ifndef BASIC_SHOOT_H
#define BASIC_SHOOT_H
#include "ShootInterface.h"

class NonProjectileObjectShot{};

class BasicShoot : public ShootInterface
{
public:
	BasicShoot(GameObjectType projectileType);
protected:
	virtual std::shared_ptr<Projectile> getProjectile() override;
private:
	GameObjectType _projectileType;
};

#endif