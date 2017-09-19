#include "Projectile.h"
#include "../BackEndSystems/GameTime.h"

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
}

void Projectile::Move()
{
	_position += _direction * _moveSpeed * GameTime::getDeltaTime();
}
