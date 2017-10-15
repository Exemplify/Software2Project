#include "ShootInterface.h"
#include "../BackEndSystems/GameManager.h"
#include <memory>


void ShootInterface::Shoot(	Vector2D startPosition, Vector2D target, std::shared_ptr<Scene> scene)
{	
	// Calculates the shoot direction based off of the target

	auto shotDirec = CalculateShootDirection(startPosition, target);
	auto bullet = getProjectile();
	bullet->Initialise(startPosition, shotDirec);
	// Instantiates the copied bullet
	scene->Instantiate(bullet);
}

Vector2D ShootInterface::CalculateShootDirection(Vector2D startPosition, Vector2D target)
{
	auto shotDirec = target - startPosition;
	return shotDirec.normalize();
}

