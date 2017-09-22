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
	shotDirec /= shotDirec.magnitude(shotDirec);
	auto bullet = std::make_shared<Projectile>(*_bullet);
	bullet->Initialise(startPosition, shotDirec, shootSpeed);
	scene.Instantiate(bullet);
}
