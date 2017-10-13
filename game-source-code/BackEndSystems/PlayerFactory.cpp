#include "PlayerFactory.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/Character.h"

std::shared_ptr<GameObject> PlayerFactory::getGameObject()
{
	Vector2D startPosition{0,-400};
	Character playerStats{3,5};
	GraphicObject playerGraphic{"resources/playerSprite.png", "player"};
	xyVector scale{0.25f,0.25f};
	auto player = std::make_shared<Player>(startPosition, playerStats, playerGraphic, scale);
	return player;
}