#include "GameSceneFactory.h"
#include "BackgroundFactory.h"
#include "PlayerFactory.h"
#include "EnemyControllerFactory.h"

std::list<std::shared_ptr<GameObject>> GameSceneFactory::getGameObectList(std::shared_ptr<DatabaseInterface> database) const
{
	std::list<std::shared_ptr<GameObject>> gameObjectlist;
	BackgroundFactory backgroundFactory{"gameScreen"};
	PlayerFactory playerFactory;
	EnemyControllerFactory enemyControllerFactory;
	auto backgroundObject = backgroundFactory.getGameObject(database);
	auto playerObject = playerFactory.getGameObject(database);
	auto enemyControllerObject = enemyControllerFactory.getGameObject(database);
	gameObjectlist.push_back(backgroundObject);
	gameObjectlist.push_back(enemyControllerObject);
	gameObjectlist.push_back(playerObject);

	return gameObjectlist;
}
