#include "GameSceneFactory.h"
#include "GameScreenBackgroundFactory.h"
#include "PlayerFactory.h"
#include "EnemyControllerFactory.h"

std::list<std::shared_ptr<GameObject>> GameSceneFactory::getGameObectList() const
{
	std::list<std::shared_ptr<GameObject>> gameObjectlist;
	GameScreenBackgroundFactory backgroundFactory;
	PlayerFactory playerFactory;
	EnemyControllerFactory enemyControllerFactory;
	auto backgroundObject = backgroundFactory.getGameObject();
	auto playerObject = playerFactory.getGameObject();
	auto enemyControllerObject = enemyControllerFactory.getGameObject();
	gameObjectlist.push_back(backgroundObject);
	gameObjectlist.push_back(enemyControllerObject);
	gameObjectlist.push_back(playerObject);

	return gameObjectlist;
}
