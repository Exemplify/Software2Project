#include "PlayerFactory.h"
#include "../Vector2D.hpp"
#include "../FrontEndSystems/Character.h"

std::shared_ptr<GameObject> PlayerFactory::getGameObject()
{
	Vector2D<double> startPosition{0,-400, 0};
	Character playerStats{3,5};
	GraphicObject playerGraphic{"resources/playerSprite.png", "player"};
	GraphicObject bulletGraphic{"resources/Rock.png", "playerBullet"};
	auto player = std::make_shared<Player>(startPosition, playerStats, playerGraphic, bulletGraphic);
	return player;
}