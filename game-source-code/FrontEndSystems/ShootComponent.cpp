#include "ShootComponent.h"


ShootComponent::ShootComponent(std::shared_ptr<SpriteInfo> spriteInfo):
_bulletSpriteInfo{spriteInfo}
{}
void ShootComponent::Shoot(	Vector2D<double> target,
	Vector2D<double> startPosition, double shootSpeed, Scene& scene)
{	
	auto shotDirec = target - startPosition;
	shotDirec /= shotDirec.magnitude(shotDirec);
	auto bullet = std::make_shared<Projectile>(_bulletSpriteInfo);
	bullet->Initialise(startPosition, shotDirec, shootSpeed);
	scene.Instantiate(bullet);
}
