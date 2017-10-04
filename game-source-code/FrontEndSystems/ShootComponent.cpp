#include "ShootComponent.h"

/// Constructor will need to be deleted 
ShootComponent::ShootComponent(std::shared_ptr<SpriteInfo> bulletInfo, GameObjectType bulletType)
{
	_bullet = std::make_shared<Projectile>(bulletInfo, bulletType);
}
/// correct type of constructor 
ShootComponent::ShootComponent(std::shared_ptr<Projectile> bullet):
_bullet{bullet}
{}

void ShootComponent::Shoot(	Vector2D<double> target,
	Vector2D<double> startPosition, double shootSpeed, Scene& scene)
{	
	// Calculates the shoot direction based off of the target
	/// can be implemented in a better way with the vector functions
	auto shotDirec = target - startPosition;
	auto shotDirecVec = shotDirec.rtpVector();
	shotDirecVec[0] = 1;
	auto shotDirecTwo = Vector2D<double>(shotDirecVec, VectorType::rtp);
	// Copies the _bullet variable to be instantiated
	auto bullet = std::make_shared<Projectile>(*_bullet);
	// Initialises the current bullet with the specific direction and speed
	bullet->Initialise(startPosition, shotDirecTwo, shootSpeed);
	// Instantiates the copied bullet
	scene.Instantiate(bullet);
}
