#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"

const double PROJECTILE_DESTROY_REGION = 100;

Projectile::Projectile(Vector2D<double> startingPos, Vector2D<double> direction, double moveSpeed):
GraphicObject(),
_direction {direction},
_moveSpeed {moveSpeed}
{
	_position =  startingPos;
	_spriteInfo->textureLocation = "resources/PlayerBullet.png";
	_spriteInfo->scale = sf::Vector2f{0.5f,0.5f};
}
void Projectile::Update()
{
	Move();
	DestroySelf();
}

void Projectile::Move()
{
	_position += _direction * _moveSpeed * GameTime::getDeltaTime();
}
void Projectile::DestroySelf()
{
	if(_position.magnitude(_position) < PROJECTILE_DESTROY_REGION)
	{
		setActive(false);
	}
}
