#include "ShootComponent.h"

ShootComponent::ShootComponent(const Projectile& bullet):
_bulletType{bullet}
{}
void ShootComponent::Shoot(	Vector2D<double> target,
	Vector2D<double> startPosition, double shootSpeed, Scene& scene)
{	
	auto shotDirec = target - startPosition;
	shotDirec /= shotDirec.magnitude(shotDirec);
	auto bullet = std::make_shared<Projectile>(_bulletType);
	scene.Instantiate(bullet);
}
