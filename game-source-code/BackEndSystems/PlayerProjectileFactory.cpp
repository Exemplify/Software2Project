#include "PlayerProjectileFactory.h"
#include "../FrontEndSystems/Projectile.h"
#include "../Vector2D.h"

std::shared_ptr<GameObject> PlayerProjectileFactory::getGameObject()
{
	auto bulletType = GameObjectType::playerBullet;
	GraphicObject bulletGraphic{"resources/Rock.png", "playerBullet"};
	xyVector scale{0.035, 0.035};
	auto projectile = std::make_shared<Projectile>(bulletGraphic, bulletType, scale);
	return projectile;
}