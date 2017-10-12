#include "ShootComponent.h"

/// Constructor will need to be deleted 
ShootComponent::ShootComponent(GraphicObject bulletGraphic, GameObjectType bulletType)
{
	if(bulletType == GameObjectType::enemyBullet)
		_bullet = std::make_shared<Projectile>(bulletGraphic, bulletType, xyVector{0.1, 0.1});
	else
		_bullet = std::make_shared<Projectile>(bulletGraphic,  bulletType, xyVector{0.035, 0.035});
}
/// correct type of constructor 
ShootComponent::ShootComponent(std::shared_ptr<Projectile> bullet):
_bullet{bullet}
{}

void ShootComponent::Shoot(	Vector2D target,
	Vector2D startPosition, double shootSpeed, Scene& scene)
{	
	// Calculates the shoot direction based off of the target
	/// can be implemented in a better way with the vector functions
	auto shotDirec = target - startPosition;
	auto shotDirecVec = shotDirec.getRTVector();
	shotDirecVec.r = 1;
	shotDirec = Vector2D(shotDirecVec);
	// Copies the _bullet variable to be instantiated
	auto bullet = std::make_shared<Projectile>(*_bullet);
	// Initialises the current bullet with the specific direction and speed
	bullet->Initialise(startPosition, shotDirec, shootSpeed);
	// Instantiates the copied bullet
	scene.Instantiate(bullet);
}
