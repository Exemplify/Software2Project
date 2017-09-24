#include "ShootComponent.h"


ShootComponent::ShootComponent(std::shared_ptr<SpriteInfo> bulletInfo, GameObjectType bulletType)
{
	_bullet = std::make_shared<Projectile>(bulletInfo, bulletType);
}

ShootComponent::ShootComponent(std::shared_ptr<Projectile> bullet):
_bullet{bullet}
{}

void ShootComponent::Shoot(	Vector2D<double> target,
	Vector2D<double> startPosition, double shootSpeed, Scene& scene)
{	
	auto shotDirec = target - startPosition;
	auto shotDirecVec = shotDirec.rtpVector();
	shotDirecVec[0] = 1;
	auto shotDirecTwo = Vector2D<double>(shotDirecVec, VectorType::rtp);
	auto bullet = std::make_shared<Projectile>(*_bullet);
	bullet->Initialise(startPosition, shotDirecTwo, shootSpeed);
	scene.Instantiate(bullet);
    // there is better implementation possible.
    // why does this class have access to scene, and how does it have acces to scene?
}
