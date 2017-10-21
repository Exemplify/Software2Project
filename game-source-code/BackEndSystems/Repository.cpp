#include "Repository.h"
#include "RandomEnemyFactory.h"
#include "SplashSceneFactory.h"
#include "WinSceneFactory.h"
#include "LoseSceneFactory.h"
#include "GameSceneFactory.h"
#include "PlayerProjectileFactory.h"
#include "EnemyProjectileFactory.h"
#include "EnemyFactory.h"

Repository::Repository(std::shared_ptr<DataMapperInterface> dataMapper, 
						std::shared_ptr<DatabaseInterface> runtime_database):
_dataMapper{dataMapper},
_runtime_database{runtime_database}
{
	_dataMapper->UpdateGameTimeDatabase(_runtime_database);
}

std::vector<std::shared_ptr<Scene>> Repository::getGameScenes() const
{
	vector<shared_ptr<Scene>> gameScenes_vector;
	SplashSceneFactory splashSceneFactory;
	WinSceneFactory winSceneFactory;
	LoseSceneFactory loseSceneFactory;
	GameSceneFactory gameSceneFactory;
	gameScenes_vector.push_back(splashSceneFactory.getScene(_runtime_database));
	gameScenes_vector.push_back(gameSceneFactory.getScene(_runtime_database));
	gameScenes_vector.push_back(winSceneFactory.getScene(_runtime_database));
	gameScenes_vector.push_back(loseSceneFactory.getScene(_runtime_database));
	
	return gameScenes_vector;
}

std::shared_ptr<GameObject> Repository::getGameObjectbyTypeDuringRuntime(GameObjectType objtype) const
{

	std::unique_ptr<GameObjectFactory> objectFactory;
	switch(objtype)
	{
		case GameObjectType::playerBullet:
		{
			objectFactory = std::make_unique<PlayerProjectileFactory>();
			break;
		}
		case GameObjectType::enemyBullet:
		{
			objectFactory = std::make_unique<EnemyProjectileFactory>();
			break;
		}
		case GameObjectType::enemy:
		{
			objectFactory = std::make_unique<RandomEnemyFactory>();
			break;
		}
		default:
		{
			throw GameObjectTypeConstructionNotDefined();
			break;
		}
	}
	return objectFactory->getGameObject(_runtime_database);
}

std::vector<unsigned int> Repository::getGameScreenSize() const
{
	auto gamestateData = _runtime_database->getGameStateData();
	return std::vector<unsigned int>{gamestateData.screen_size_x, gamestateData.screen_size_y};
}
std::string Repository::getGameName() const
{
	auto gamestateData = _runtime_database->getGameStateData();
	return gamestateData.gameName;
}
